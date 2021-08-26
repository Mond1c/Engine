//
// engine.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once
#ifndef _engine_h_
#define _engine_h_

#include "settings.h"
#include "Render/window.h"
#include "Render/event.h"
#include "Physics/collider.h"
#include "Parser/file.h"

#include <vector>
#include <memory>

class Engine {
public:
	Engine();
	~Engine() {
		for (SDL::Object* object : objects) delete object;
		for (Physics::ICollider* collider : colliders) delete collider;
	}
	
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;
	
	SDL::Object* CreateObject(SDL::Object* object) {
		objects.push_back(object);
		return object;
	}
	
	Physics::ICollider* CreateCollider(Physics::ICollider* collider) {
		colliders.push_back(collider);
		return collider;
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