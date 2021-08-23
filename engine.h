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

#include <vector>

class Engine {
public:
	Engine();
	
	void Start();
	void Update();
private:
	std::vector<SDL::Object> objects;
	std::vector<Physics::ICollider> colliders;
	
	SDL::Window window;
	SDL::Renderer renderer;
};

#endif