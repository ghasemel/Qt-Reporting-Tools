cmake_minimum_required(VERSION 2.6)
project(generator-test)

link_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../build
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

set(SRC_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(generator-test ${SRC_FILES})

target_link_libraries(generator-test
  hpdf
  reportpp
)

set_property(TARGET generator-test APPEND_STRING PROPERTY COMPILE_FLAGS "-std=c++11 -O0 -g")
