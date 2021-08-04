cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp wincl.cpp srcemul.cpp ${MY_INCLUDE_DIR}/wincl.h ${MY_INCLUDE_DIR}/srcemul.h )
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Windows ${SOURCES})

target_include_directories(Windows PUBLIC ${MY_INCLUDE_DIR})