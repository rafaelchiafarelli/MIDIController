
cmake_minimum_required(VERSION 3.13)
include_directories(./include)
include_directories(../rtmidi)
include_directories(../Common/include)

set(RTMIDI_BUILD_STATIC_LIBS TRUE)
file(GLOB SOURCES "src/*.cpp")

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS FALSE)
    set(BUILD_SHARED_LIBS NO)
endif()
add_library(MIDI ${SOURCES})

target_link_libraries(MIDI PUBLIC Common)
target_link_libraries(MIDI PUBLIC rtmidi)

