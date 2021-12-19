# CMakeList.txt: CMake-Projektdatei der obersten Ebene. Führen Sie hier die globale Konfiguration aus,
# und schließen Sie Unterprojekte ein.
#
cmake_minimum_required (VERSION 3.8)

project ("sfmlPhysicstest" VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Schließen Sie Unterprojekte ein.
add_subdirectory ("deps")
add_subdirectory ("sfmlPhysicstest")
