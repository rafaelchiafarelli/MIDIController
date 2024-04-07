cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include_directories(./include)

file(GLOB SOURCES "src/*.cpp")

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS FALSE)
    set(BUILD_SHARED_LIBS NO)
endif()
add_library(Common ${SOURCES} )