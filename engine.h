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
	Engine(): window("Window", SDL::Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED),
                  SDL::Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN,
                  -1, SDL_RENDERER_ACCELERATED) { }
	~Engine() {
		SDL_Quit();
	}
	
	Engine(const Engine&) = delete;
	Engine(Engine&&) = delete;
	
	Engine& operator=(const Engine&) = delete;
	Engine& operator=(Engine&&) = delete;
	
	void Awake() {
		Start();
		Game();
	}
	
	void Start();
	void Update();
	
	void Game() {
		while (true) {
			Update();
			SDL::Event event;
			if (event.PollEvent()) {
				if (event.Type() == SDL::EventType::QUIT) {
					break;
				}
			}
			SDL::Delay(DELAY);
		}
	}
private:
	SDL::RendererWindow window;
};

#endif