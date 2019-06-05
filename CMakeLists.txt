cmake_minimum_required(VERSION 3.13)
#set(CMAKE_BUILD_TYPE Release)
project(game)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS -static)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(OBJECT_FILES Objects/GameObject.cpp Objects/GameObject.h Objects/Wall.cpp Objects/Wall.h Objects/Map.cpp Objects/Map.h Objects/Player.cpp Objects/Player.h Objects/Bullet.cpp Objects/Bullet.h Objects/Textures.cpp Objects/Textures.h)
set(GAME_SOURCE Game/Renderer.cpp Game/Renderer.h Game/Logic.cpp Game/Logic.h Game/Game.cpp Game/Game.h)
set(SERVER_SOURCE Server/Server.cpp Server/Server.h)

add_executable(game ${OBJECT_FILES} ${GAME_SOURCE} gameMain.cpp)
target_link_libraries(game sfml-graphics sfml-audio)
target_link_libraries(game ${PROJECT_SOURCE_DIR}/lib/liblil.a)
target_link_libraries(game WS2_32.lib)

add_executable(server ${OBJECT_FILES} ${SERVER_SOURCE} serverMain.cpp)
target_link_libraries(server sfml-graphics sfml-audio)
target_link_libraries(server ${PROJECT_SOURCE_DIR}/lib/liblil.a)
target_link_libraries(server WS2_32.lib)

include_directories(include)

