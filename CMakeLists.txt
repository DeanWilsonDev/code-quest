cmake_minimum_required(VERSION 3.20)

project(
  CodeQuest
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# UmbraTest
FetchContent_Declare(
  umbra_test
  GIT_REPOSITORY "https://github.com/UmbraEngine/UmbraTest.git"
  GIT_TAG main)
FetchContent_MakeAvailable(umbra_test)

file(
  GLOB SUBDIRS
  LIST_DIRECTORIES true
  "${CMAKE_CURRENT_SOURCE_DIR}/quests/*")

set(SUBPROJECT_LIBS "")
set(SUBPROJECT_TARGET_SOURCES "")

function(add_subdirectories_recursive parent_dir)
  file(
    GLOB children
    RELATIVE ${parent_dir}
    ${parent_dir}/*)

  # check for cmake lists in dir
  foreach(child ${children})
    set(child_path ${parent_dir}/${child})
    if(IS_DIRECTORY ${child_path})
      if(EXISTS ${child_path}/CMakeLists.txt)
        get_filename_component(DIR_NAME ${child_path} NAME)

        add_subdirectory("${child_path}")
        list(APPEND SUBPROJECT_LIBS quest_${DIR_NAME})
        list(APPEND SUBPROJECT_TARGET_SOURCES
             "$<TARGET_OBJECTS:quest_${DIR_NAME}>")

        # Propagate lists back to parent scope
        set(SUBPROJECT_LIBS
            ${SUBPROJECT_LIBS}
            PARENT_SCOPE)
        set(SUBPROJECT_TARGET_SOURCES
            ${SUBPROJECT_TARGET_SOURCES}
            PARENT_SCOPE)
      else()
        # Recurse into subdirectories to find CMakeLists.txt
        add_subdirectories_recursive(${child_path})

        # Propagate results
        set(SUBPROJECT_LIBS
            ${SUBPROJECT_LIBS}
            PARENT_SCOPE)
        set(SUBPROJECT_TARGET_SOURCES
            ${SUBPROJECT_TARGET_SOURCES}
            PARENT_SCOPE)
      endif()
    endif()
  endforeach()
endfunction()

add_subdirectories_recursive(${CMAKE_CURRENT_SOURCE_DIR}/quests)

# foreach(DIR IN LISTS SUBDIRS) if(IS_DIRECTORY ${DIR})
# get_filename_component(DIR_NAME ${DIR} NAME)
#
# add_subdirectory("quests/${DIR_NAME}") list(APPEND SUBPROJECT_LIBS
# quest_${DIR_NAME}) list(APPEND SUBPROJECT_TARGET_SOURCES
# "$<TARGET_OBJECTS:quest_${DIR_NAME}>") endif() endforeach()

message("Subproject Libraries: ${SUBPROJECT_LIBS}")
message("Subproject Target Sources: ${SUBPROJECT_TARGET_SOURCES}")

option(BUILD_TESTS "Build Tests" ON)
if(BUILD_TESTS)
  set(TEST_PROJECT_NAME test_${PROJECT_NAME})
  enable_language(CXX)
  add_executable(${TEST_PROJECT_NAME} runners/run_all_tests.cpp)
  target_link_libraries(${TEST_PROJECT_NAME} PRIVATE umbra_test ${SUBPROJECT_LIBS})
  target_sources(${TEST_PROJECT_NAME} PRIVATE ${SUBPROJECT_TARGET_SOURCES})
  target_compile_features(${TEST_PROJECT_NAME} PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(${TEST_PROJECT_NAME} PRIVATE /W4 /EHsc)
  else()
    target_compile_options(${TEST_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
endif()
