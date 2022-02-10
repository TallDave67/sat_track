cmake_minimum_required(VERSION 3.18)
project(sat_track_engine-src)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(curl_agent)
include_directories(
  curl_agent
)

add_library(sat_track_engine-src
  src_main.cpp
)

target_compile_options(sat_track_engine-src PRIVATE
)

target_link_libraries(sat_track_engine-src
  sat_track_engine-src-curl_agent
)
