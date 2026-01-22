cmake_minimum_required(VERSION 3.20)

project(
  run_all_quest_tests
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
foreach(DIR IN LISTS SUBDIRS)
  if(IS_DIRECTORY ${DIR})
    get_filename_component(DIR_NAME ${DIR} NAME)

    add_subdirectory("quests/${DIR_NAME}")
    list(APPEND SUBPROJECT_LIBS quest_${DIR_NAME})
    list(APPEND SUBPROJECT_TARGET_SOURCES "$<TARGET_OBJECTS:quest_${DIR_NAME}>")
  endif()
endforeach()

message("Subproject Libraries: ${SUBPROJECT_LIBS}")
message("Subproject Target Sources: ${SUBPROJECT_TARGET_SOURCES}")

option(BUILD_TESTS "Build Tests" ON)
if(BUILD_TESTS)
  enable_language(CXX)
  add_executable(${PROJECT_NAME} runners/run_all_tests.cpp)
  target_link_libraries(${PROJECT_NAME} PRIVATE umbra_test ${SUBPROJECT_LIBS})
  target_sources(${PROJECT_NAME} PRIVATE ${SUBPROJECT_TARGET_SOURCES})
  target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /EHsc)
  else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
endif()
