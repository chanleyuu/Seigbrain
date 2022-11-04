cmake_minimum_required(VERSION 3.0)

project(seigbrain LANGUAGES CXX)

set(PROJECT_SOURCE_DIR "/home/aquadoff/projects/siegbrain")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/usr/local/lib/pkgconfig")
list(APPEND flags "--cxxflags --cppflags")

include_directories(included ${PROJECT_SOURCE_DIR}/include)
#find_library(IMAGE_LIB ${PROJECT_SOURCE_DIR}/include/stb/stb_image)
#add_library(image imageprocesser.h)
#target_include_directories(cmake PRIVATE "${PROJECT_SOURCE_DIR}/include")
add_executable(seigbrain)
target_sources(seigbrain PRIVATE main.cpp imageprocesser.h  network.h intelligence.h neuron.cpp neuron.h layer.cpp layer.h my_math.h)
#target_link_libraries(seigbrain ${image})

install(TARGETS seigbrain RUNTIME DESTINATION bin)
