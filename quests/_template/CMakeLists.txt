get_filename_component(PROJECT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(quest_${PROJECT_DIR_NAME})
add_library(${PROJECT_NAME} OBJECT src/solution.cpp test/solution.test.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC umbra_test)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
option(${PROJECT_NAME_UPPER}_BUILD_RUNNER "Build Quest: Array I standalone one"
       ON)
if(${PROJECT_NAME_UPPER}_BUILD_RUNNER)
  add_executable(run_${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test/test_runner.cpp)
  target_link_libraries(run_${PROJECT_NAME} PRIVATE ${PROJECT_NAME} umbra_test)
  target_sources(run_${PROJECT_NAME} PRIVATE $<TARGET_OBJECTS:${PROJECT_NAME}>)
endif()
