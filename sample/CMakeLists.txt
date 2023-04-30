cmake_minimum_required(VERSION 3.13)
project(sample)

set (CMAKE_CXX_STANDARD 17)

find_library(PQXX_LIB pqxx REQUIRED)
find_library(PQ_LIB pq REQUIRED)

#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-lm -g -O0 -Wall -W -fprofile-arcs -ftest-coverage -Llibs -lpq -lpqxx")
set(SAMPLE_LIBRARIES)
set(SAMPLE_INCLUDE_DIRS)

file(GLOB SOURCES *.cpp)
file(GLOB INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${NLOHMANN_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PQXX_LIB} ${PQ_LIB}  ${NLOHMANN_LIBRARIES})

set(SAMPLE_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(SAMPLE_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)