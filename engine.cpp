//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

Engine::Engine() : window(SDL::Window("Window", SDL::Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), SDL::Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN)), renderer(SDL::Renderer(window.Ptr(), -1, SDL_RENDERER_ACCELERATED)) {
} // This is Awake. You need to init window and renderer

void Engine::Start() { // Here you can create start Objects and Colliders
	renderer.SetColor(SDL::Color(225, 255, 255));
	renderer.Clear();
	renderer.SetColor(SDL::Color(0, 0, 0));
	SDL::Shapes::Rect* rect = new SDL::Shapes::Rect(SDL::Vector(WIDTH / 2, HEIGHT / 2), SDL::Vector(5, 5));
	rect->Fill(renderer.Ptr());
	renderer.Draw(*rect);
	renderer.Update();
	objects.push_back(rect);
	
	Physics::Collider::Rect* collider = new Physics::Collider::Rect(SDL::Vector(WIDTH / 2, HEIGHT / 2), SDL::Vector(5, 5), *rect, 10);
	colliders.push_back(collider);
}

void Engine::Update() { // Gameplay and Physics
	renderer.SetColor(SDL::Color(255, 255, 255));
	renderer.Clear();
	renderer.SetColor(SDL::Color(0, 0, 0));
	//std::cout << renderer.Ptr() << '\n';
	for (Physics::ICollider* collider : colliders) {
		collider->Update(colliders);
		//std::cout << collider.GetPosition().x << " " << collider.GetPosition().y << '\n';
	}
	
	for (SDL::Object* object : objects) {
		renderer.Draw(*object);
	}
	renderer.Update();
}