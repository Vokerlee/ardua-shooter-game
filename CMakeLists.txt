# Ardua Shooter game

# CMAKE MINIMAL VERSION
cmake_minimum_required (VERSION 3.8)

# PROJECT PROPERTIES
project ("Ardua shooter" VERSION 0.0.3 LANGUAGES CXX)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# TODO: split to separate subdirectories
set(SOURCES
    src/camera/camera.cpp
    src/main/main.cpp
    src/manager/manager.cpp
    src/menu/menu.cpp
    src/objects2D/object2D.cpp
    src/point2D/point2D.cpp
    src/weapon/weapon.cpp
    src/world/world.cpp
)

# SFML LIBRARY CONNECTION
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

# EXECUTABLE FILE
add_executable(ardua ${SOURCES})
set_target_properties(ardua PROPERTIES
    CXX_STANDARD          14
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(ardua sfml-graphics sfml-audio)
target_include_directories(ardua PUBLIC src textures)

# Copy textures to build directory
add_custom_command(TARGET ardua PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/textures/ ${CMAKE_CURRENT_BINARY_DIR}/textures/)
