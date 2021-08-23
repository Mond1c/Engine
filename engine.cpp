//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

Engine::Engine() : window(SDL::Window("Window", SDL::Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), SDL::Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN)), renderer(SDL::Renderer(window.Ptr(), -1, SDL_RENDERER_ACCELERATED)) {
} // This is Awake. You need to init window and renderer

void Engine::Start() { // Here you can create start Objects and Colliders
	
}

void Engine::Update() { // Gameplay and Physics
	
}