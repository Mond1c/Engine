//
// window.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once
#ifndef _window_h_
#define _window_h_

#include "../Objects/shapes.h"
#include <SDL2/SDL.h>

namespace SDL {
	
	class Renderer {
	public:
		explicit Renderer(SDL_Window* window, int index, Uint32 flags) noexcept;
		~Renderer();
		
		void SetColor(const Color& color);
		void Draw(Object& object);
		void Clear();
		void Update();
		
		SDL_Renderer* Ptr();
	private:
		SDL_Renderer* renderer_;
		Color color_;
	};
	
	class Window {
	public:
		explicit Window(const char* title, const Vector& position, const Vector& size, Uint32 flags) noexcept;
		
		SDL_Window* Ptr();
		
		~Window();
	private:
		SDL_Window* window_;
	};
	
	inline void Delay(Uint32 ms) {
		SDL_Delay(ms);
	}
}

#endif