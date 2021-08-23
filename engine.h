//
// engine.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once
#ifndef _engine_h_
#define _engine_h_

#include "settings.h"
#include "Render/window.h"
#include "Render/event.h"
#include "Parser/object_parser.h"
#include "Physics/collider.h"

#include <vector>

class Engine {
public:
	Engine();
	~Engine() {
		for (SDL::Object* object : objects) delete object;
		for (Physics::ICollider* collider : colliders) delete collider;
	}
	
	void Start();
	void Update();
private:
	std::vector<SDL::Object*> objects;
	std::vector<Physics::ICollider*> colliders;
	
	SDL::Window window;
	SDL::Renderer renderer;
};

#endif