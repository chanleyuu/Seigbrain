cmake_minimum_required(VERSION 3.0)

project(seigbrain LANGUAGES CXX)

#set(PROJECT_SOURCE_DIR "/home/aquadoff/projects/siegbrain")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/usr/local/lib/pkgconfig")
list(APPEND flags "Magick++-config --cxxflags --cppflags")

target_include_directories(cmake PRIVATE "${PROJECT_SOURCE_DIR}/lib/include")
add_executable(seigbrain main.cpp )

install(TARGETS seigbrain RUNTIME DESTINATION bin)
