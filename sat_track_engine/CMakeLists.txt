cmake_minimum_required(VERSION 3.18)
project(sat_track_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src)
include_directories(
  src
  src/curl_agent
)

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})

add_executable(sat_track_engine main.cpp)

target_link_libraries(sat_track_engine sat_track_engine-src ${CURL_LIBRARIES})
