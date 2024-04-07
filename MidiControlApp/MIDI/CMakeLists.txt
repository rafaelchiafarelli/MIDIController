cmake_minimum_required(VERSION 3.13)

set(RTMIDI_BUILD_STATIC_LIBS TRUE)
file(GLOB SOURCES "src/*.cpp")

include_directories(./include)
include_directories(../rtmidi)
include_directories(../WinKeyboard/include)
include_directories(../Common/include)
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS NO)
endif()
add_library(MIDI ${SOURCES})

target_link_libraries(MIDI PUBLIC Common)
target_link_libraries(MIDI PUBLIC rtmidi)

