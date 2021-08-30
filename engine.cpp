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
	SDL::File file2("test.object");
	file2.Save(objects);
	Functions::Function function = Functions::Parser::Parse("x^0.5 - 4*x - 5");
	for (float x = -WIDTH / 2; x < WIDTH / 2; x += 0.1f) {
		float y = function.Calculate(x);
		//std::cout << x + WIDTH / 2 << " " << -1 * y + HEIGHT / 2 << std::endl;
		SDL::Shapes::Point* p = CreateObject<SDL::Shapes::Point>(new SDL::Shapes::Point(SDL::Vector(x + WIDTH / 2, -1 * y + HEIGHT / 2)));
		p->Draw(renderer.Ptr());
	}
	
	renderer.Update();
}

void Engine::Update() { // Gameplay and Physics
}