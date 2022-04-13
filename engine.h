//
// engine.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once
#ifndef _engine_h_
#define _engine_h_

#include "settings.h"
#include "window.h"
#include "event.h"
#include "collider.h"
#include "file.h"
#include "function_parser.h"

#include <vector>
#include <memory>

class Engine {
public:
	Engine(): window("Window", engine::Vector2f(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED),
                  engine::Vector2f(WIDTH, HEIGHT), SDL_WINDOW_SHOWN,
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
        bool running = true;
		while (running) {
           // Uint64 start = SDL_GetPerformanceCounter();
			Update();
			engine::Event event{};
			while (event.PollEvent()) {
                if (event.Type() == engine::EventType::QUIT) {
                    running = false;
                }
            }
            engine::Delay(DELAY);
        //    Uint64 end = SDL_GetPerformanceCounter();
           // float fps = (float)(end - start) / (float)SDL_GetPerformanceFrequency();
           // std::cout << 1 / fps << std::endl;
            window.Update();
		}
	}
private:
	engine::RendererWindow window;
};

#endif