cmake_minimum_required(VERSION 3.13)
project(dockertest)

set (CMAKE_CXX_STANDARD 20)

find_library(PQXX_LIB pqxx REQUIRED)
find_library(PQ_LIB pq REQUIRED)

add_subdirectory(nlohmann)
add_subdirectory(sample)

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(dockertest PUBLIC ${PQXX_LIB} ${PQ_LIB})

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-lm -g -O0 -Wall -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")

set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

target_include_directories(${PROJECT_NAME} PUBLIC ${SAMPLE_INCLUDE_DIRS})
 
target_link_libraries(${PROJECT_NAME} PRIVATE ${SAMPLE_LIBRARIES})


if (${TEST})
    add_subdirectory(test)
endif ()