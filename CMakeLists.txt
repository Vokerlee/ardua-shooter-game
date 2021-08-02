# Ardua Shooter game

# CMAKE MINIMAL VERSION
cmake_minimum_required (VERSION 3.8)

# PROJECT PROPERTIES
project ("Ardua shooter" VERSION 0.0.3 LANGUAGES CXX)

# SOURCE FILES
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

set(HEADERS
        src/camera/camera.hpp
        src/config/config.hpp
        src/config/drawable.hpp
        src/manager/manager.hpp
        src/menu/menu.hpp
        src/objects2D/object2D.hpp
        src/objects2D/circle2D.hpp
        src/objects2D/polygon2D.hpp
        src/point2D/point2D.hpp
        src/weapon/weapon.hpp
        src/world/world.hpp
)

# SFML LIBRARY CONNECTION
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sfml/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# EXECUTABLE FILE
add_executable(ArduaShooter ${SOURCES} ${HEADERS})

target_link_libraries(ArduaShooter
    sfml-graphics sfml-audio
)

# COMPILATION OPTIONS
set_target_properties(ArduaShooter PROPERTIES
    CXX_STANDARD          14
    CXX_STANDARD_REQUIRED ON
)

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