//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

Engine::Engine() : window(SDL::Window("Window", SDL::Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), SDL::Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN)), renderer(SDL::Renderer(window.Ptr(), -1, SDL_RENDERER_ACCELERATED)) {
} // This is Awake. You need to init window and renderer

//To create object use CreateObject(Object*);
//To create collider use CreateCollider(ICollider*)
//To load objects use objects = file.Load();

void Engine::Start() { // Here you can create start Objects and Colliders
	renderer.SetColor(SDL::Color(225, 255, 255));
	renderer.Clear();
	renderer.SetColor(SDL::Color(0, 0, 0));
	SDL::File file("Object.object");
	objects = file.Load();
	for (SDL::Object* obj : objects) if (obj) renderer.Draw(*obj);
	renderer.Update();
	SDL::File file2("test.object");
	file2.Save(objects);
}

void Engine::Update() { // Gameplay and Physics
}