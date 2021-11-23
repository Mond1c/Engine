//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

//To load objects use objects = file.Load();

void Engine::Start() { // Here you can create start Objects and Colliders
	window.SetColor(SDL::Color(225, 255, 255));
    window.Clear();
    window.SetColor(SDL::Color(0, 0, 0));
	SDL::File file("Object.object");
	auto objects = file.Load();
	for (const auto& obj : objects) if (obj) window.Draw(*obj);
	SDL::File file2("test.object");
	file2.Save(objects);
	auto function = Functions::Parser::Parse("sinx");
	
	for (float x = (float)-WIDTH / 2; x < (float)WIDTH / 2; x += 0.05) {
		float y = function->Calculate(x);
		if (y > (float)HEIGHT / 2) continue;
		auto p = std::make_shared<SDL::Shapes::Point>(SDL::Vector(x * 2 + WIDTH / 2, -1 * y * 20 + HEIGHT / 2));
		p->Draw(window.RendererPtr());
	}

    window.Update();
}

void Engine::Update() { // Gameplay and Physics
}
