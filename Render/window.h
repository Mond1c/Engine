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
		
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&& other) {
			if (this != &other) {
				if (renderer_) SDL_DestroyRenderer(renderer_);
				renderer_ = other.renderer_;
				other.renderer_ = nullptr;
			}
		}
		
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&& other) {
			if (this != &other) {
				if (renderer_) SDL_DestroyRenderer(renderer_);
				renderer_ = other.renderer_;
				other.renderer_ = nullptr;
			}
			return *this;
		}
		
		void SetColor(const Color& color);
		void Draw(Object& object);
		void Clear();
		void Update();
		
		SDL_Renderer* Ptr();
	private:
		SDL_Renderer* renderer_;
	};
	
	class Window {
	public:
		explicit Window(const char* title, const Vector& position, const Vector& size, Uint32 flags) noexcept;
		
		Window(const Window&) = delete;
		Window(Window&& other) {
			if (this != &other) {
				if (window_) SDL_DestroyWindow(window_);
				window_ = other.window_;
				other.window_ = nullptr;
			}
		}
		
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&& other) {
			if (this != &other) {
				if (window_) SDL_DestroyWindow(window_);
				window_ = other.window_;
				other.window_ = nullptr;
			}
			return *this;
		}
		
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