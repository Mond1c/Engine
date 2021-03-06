cmake_minimum_required(VERSION 3.17)
project(Engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)



find_package(SDL2 REQUIRED)

include_directories(.)
include_directories(Functions)
include_directories(Objects)
include_directories(Parser)
include_directories(Physics)
include_directories(Render)

add_executable(Engine
        Language/parser.h
        Language/parser.cpp
        Language/script.h
        Language/script.cpp
        Language/token.h
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
        settings.h Language/parser.cpp Language/script.cpp)

target_link_libraries(Engine SDL2::SDL2)
