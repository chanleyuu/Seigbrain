cmake_minimum_required(VERSION 3.0)

project(seigbrain LANGUAGES CXX)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/usr/local/lib/pkgconfig")
list(APPEND flags "--cxxflags --cppflags")

#include_directories(included ${PROJECT_SOURCE_DIR}/include)
#find_library(IMAGE_LIB ${PROJECT_SOURCE_DIR}/include/stb/stb_image)
#INCLUDE_DIRECTORIES(/usr/include/CL)
#LINK_DIRECTORIES(${PROJECT_SOURCE_DIR})

include(${PROJECT_SOURCE_DIR}/build/FindOpenCL.cmake)

#add_library(OPENCL SHARED /usr/include/CL/opencl.hpp 
#    /usr/include/CL/cl_d3d10.h 
#    /usr/include/CL/cl_d3d11.h 
#    /usr/include/CL/cl_dx9_media_sharing_intel.h
#    /usr/include/CL/cl_dx9_media_sharing.h
#    /usr/include/CL/cl_egl.h
#    /usr/include/CL/cl_ext_intel.h
#    /usr/include/CL/cl_ext.h
#    /usr/include/CL/cl_gl_ext.h
#    /usr/include/CL/cl_gl.h
#    /usr/include/CL/cl_half.h
#    /usr/include/CL/cl_icd.h
#    /usr/include/CL/cl_layer.h
#    /usr/include/CL/cl_platform.h
#    /usr/include/CL/cl_va_api_media_sharing_intel.h
#    /usr/include/CL/cl_version.h
#    /usr/include/CL/cl.h
#    /usr/include/CL/opencl.h)
#target_include_directories(OPENCL PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})
#target_include_directories(cmake PRIVATE "${PROJECT_SOURCE_DIR}/include")
#set_target_properties(OPENCL PROPERTIES LINKER_LANGUAGE Cxx) 
#set_target_properties(OPENCL CMAKE_Cxx_CREATE_SHARED_LIBRARY )
set(source_files ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/imageprocesser.cpp
    ${PROJECT_SOURCE_DIR}/imageprocesser.h
    ${PROJECT_SOURCE_DIR}/my_math.h
    ${PROJECT_SOURCE_DIR}/my_math.cpp
    ${PROJECT_SOURCE_DIR}/neuron.h
    ${PROJECT_SOURCE_DIR}/neuron.cpp
    ${PROJECT_SOURCE_DIR}/layer.h
    ${PROJECT_SOURCE_DIR}/layer.cpp
    ${PROJECT_SOURCE_DIR}/network.h
    ${PROJECT_SOURCE_DIR}/network.cpp
    ${PROJECT_SOURCE_DIR}/intelligence.h
    ${PROJECT_SOURCE_DIR}/intelligence.cpp
    )
add_executable(seigbrain ${source_files})
# Loop through each source file
#foreach(source_file IN LISTS source_files)
    # Get the name of the file without the extension (e.g. 'a' from src/a.cpp'
    #get_filename_component(seigbrain ${source_file} NAME_WE)
    
    # Create an executable with the above name, building the above source
    #add_executable(seigbrain  "${source_file}")
#endforeach()
#target_link_libraries(seigbrain PRIVATE OPENCL)
#target_sources(seigbrain PRIVATE ${source_files})
target_link_libraries(seigbrain PUBLIC OpenCL::OpenCL)
install(TARGETS seigbrain RUNTIME DESTINATION bin)
