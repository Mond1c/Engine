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
#include "Functions/function_parser.h"

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
	
	template<typename Shape>
	Shape* CreateObject(SDL::Object* object) {
		if (object == nullptr) return nullptr;
		objects.push_back(object);
		return static_cast<Shape*>(object);
	}
	
	template<typename Collider>
	Collider* CreateCollider(Physics::ICollider* collider) {
		if (collider == nullptr) return nullptr;
		colliders.push_back(collider);
		return static_cast<Collider*>(collider);
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