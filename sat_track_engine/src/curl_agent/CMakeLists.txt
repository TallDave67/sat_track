cmake_minimum_required(VERSION 3.18)
project(sat_track_engine-src-curl_agent)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(
  ../curl_agent
)

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})

add_library(sat_track_engine-src-curl_agent
  curl_agent.cpp
)

target_compile_options(sat_track_engine-src-curl_agent PRIVATE
)

target_link_libraries(sat_track_engine-src-curl_agent ${CURL_LIBRARIES})