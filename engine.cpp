//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

//To create object use CreateObject(Object*);
//To create collider use CreateCollider(ICollider*)
//To load objects use objects = file.Load();

void Engine::Start() { // Here you can create start Objects and Colliders
	renderer.SetColor(SDL::Color(225, 255, 255));
	renderer.Clear();
	renderer.SetColor(SDL::Color(0, 0, 0));
	SDL::File file("Object.object");
	std::vector<std::shared_ptr<SDL::Object>> objects = file.Load();
	for (std::shared_ptr<SDL::Object> obj : objects) if (obj) renderer.Draw(*obj);
	SDL::File file2("test.object");
	file2.Save(objects);
	std::unique_ptr<Functions::Function> function = Functions::Parser::Parse("x - x + 5");
	
	//for (std::shared_ptr<Functions::IToken> token : function->GetTokens()) std::cout << token->number << std::endl; 
	
	for (float x = -WIDTH / 2; x < WIDTH / 2; x += 0.1f) {
		float y = function->Calculate(x);
	//	std::cout << y << std::endl;
		//std::cout << y << std::endl;
		//std::cout << x + WIDTH / 2 << " " << -1 * y + HEIGHT / 2 << std::endl;
		std::shared_ptr<SDL::Shapes::Point> p = std::make_shared<SDL::Shapes::Point>(SDL::Vector(x + WIDTH / 2, -1 * y + HEIGHT / 2));
		p->Draw(renderer.Ptr());
	}
	
	renderer.Update();
}

void Engine::Update() { // Gameplay and Physics
}