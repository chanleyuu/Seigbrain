cmake_minimum_required(VERSION 3.0)

project(seigbrain)

add_executable(seigbrain main.cpp)

install(TARGETS seigbrain RUNTIME DESTINATION bin)
