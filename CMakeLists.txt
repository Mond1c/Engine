cmake_minimum_required(VERSION 3.17)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED SDL2)

include_directories(.)
include_directories(Functions)
include_directories(Objects)
include_directories(Parser)
include_directories(Physics)
include_directories(Render)

add_executable(Engine
        Functions/function_parser.cpp
        Functions/function_parser.h
        Objects/shapes.cpp
        Objects/shapes.h
        Objects/vector.h
        Parser/file.cpp
        Parser/file.h
        Parser/object_parser.cpp
        Parser/object_parser.h
        Physics/collider.cpp
        Physics/collider.h
        Render/event.cpp
        Render/event.h
        Render/window.cpp
        Render/window.h
        engine.cpp
        engine.h
        main.cpp
        settings.h)

target_link_libraries(Engine PRIVATE SDL2::SDL2)
