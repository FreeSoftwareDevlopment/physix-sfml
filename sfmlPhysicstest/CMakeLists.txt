# CMakeList.txt: CMake-Projekt für "sfmlPhysicstest". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (sfmlPhysicstest "sfmlPhysicstest.cpp" "sfmlPhysicstest.h"  "renderer.cpp" "timeelapsed.cpp" )

target_link_libraries(sfmlPhysicstest sfml-graphics sfml-window chipmunk_static)

