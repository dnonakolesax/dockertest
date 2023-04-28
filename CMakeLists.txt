cmake_minimum_required(VERSION 3.0.0)
project(dockertest)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(sample)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

target_include_directories(${PROJECT_NAME} PUBLIC ${SAMPLE_INCLUDE_DIRS})
 
target_link_libraries(${PROJECT_NAME} PRIVATE ${SAMPLE_LIBRARIES})

if (${TEST})
    add_subdirectory(test)
endif ()