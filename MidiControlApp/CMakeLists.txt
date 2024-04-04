# CMakeList.txt: projeto de CMake para MidiControlApp, incluir origem e definir
# lógica específica a um projeto aqui.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project ("MidiControlApp")

include_directories(./MIDI/include)
include_directories(./Common/include)
include_directories(./rtmidi)
set(RTMIDI_BUILD_STATIC_LIBS TRUE)
add_subdirectory (Common)
add_subdirectory (MIDI)
add_subdirectory (rtmidi)



# Adicione a origem ao executável deste projeto.
add_executable (MidiControlApp "MidiControlApp.cpp" "MidiControlApp.h")
target_link_libraries(MidiControlApp PUBLIC Common)
target_link_libraries(MidiControlApp PUBLIC MIDI)
target_link_libraries(MidiControlApp PUBLIC rtmidi)


# TODO: Adicione testes e instale destinos, se necessário.
