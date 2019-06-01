cmake_minimum_required(VERSION 3.13)
project(game)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(game main.cpp Game/Renderer.cpp Game/Renderer.h Game/Logic.cpp Game/Logic.h Game/Game.cpp Game/Game.h Objects/GameObject.cpp Objects/GameObject.h Objects/Wall.cpp Objects/Wall.h Objects/Map.cpp Objects/Map.h Game/Textures.cpp Game/Textures.h)

target_link_libraries(game sfml-graphics sfml-audio)


