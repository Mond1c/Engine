//
// window.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once
#ifndef _window_h_
#define _window_h_

#include "../Objects/shapes.h"
#include <SDL.h>


namespace engine {
	
	class Renderer {
	public:
		explicit Renderer(SDL_Window* window, int index, Uint32 flags) noexcept;
		~Renderer() {
            SDL_DestroyRenderer(renderer_);
        }
		
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&& other)  noexcept {
			if (this != &other) {
				if (renderer_) SDL_DestroyRenderer(renderer_);
				renderer_ = other.renderer_;
				other.renderer_ = nullptr;
			}
		}
		
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&& other)  noexcept {
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
		explicit Window(const char* title, const Vector2f& position, const Vector2f& size, Uint32 flags) noexcept;
		
		Window(const Window&) = delete;
		Window(Window&& other)  noexcept {
			if (this != &other) {
				if (window_) SDL_DestroyWindow(window_);
				window_ = other.window_;
				other.window_ = nullptr;
			}
		}
        ~Window() {
            SDL_DestroyWindow(window_);
        }
		
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&& other)  noexcept {
			if (this != &other) {
				if (window_) SDL_DestroyWindow(window_);
				window_ = other.window_;
				other.window_ = nullptr;
			}
			return *this;
		}
		
		SDL_Window* Ptr();

	private:
		SDL_Window* window_;
	};

	class RendererWindow {
	public:
	    explicit RendererWindow(const char* title, const Vector2f& position, const Vector2f& size, Uint32 window_flags,
                             int index, Uint32 renderer_flags) noexcept;
	    RendererWindow(const RendererWindow&) = delete;
	    RendererWindow(RendererWindow&& other) noexcept {
	        if (this != &other) {
	            if (window_) SDL_DestroyWindow(window_);
	            if (renderer_) SDL_DestroyRenderer(renderer_);
	            window_ = other.window_;
	            renderer_ = other.renderer_;
	            other.window_ = nullptr;
	            other.renderer_ = nullptr;
	        }
	    }

        ~RendererWindow() {
            SDL_DestroyRenderer(renderer_);
            SDL_DestroyWindow(window_);
        }

        RendererWindow& operator=(const RendererWindow&) = delete;
        RendererWindow& operator=(RendererWindow&& other)  noexcept {
            if (this != &other) {
                if (window_) SDL_DestroyWindow(window_);
                if (renderer_) SDL_DestroyRenderer(renderer_);
                window_ = other.window_;
                renderer_ = other.renderer_;
                other.window_ = nullptr;
                other.renderer_ = nullptr;
            }
            return *this;
        }

        void SetColor(const Color& color);
        void Draw(Object& object);
        void Update();
        void Clear();

        SDL_Window* WindowPtr();
        SDL_Renderer* RendererPtr();
	private:
	    SDL_Window* window_;
	    SDL_Renderer* renderer_;
	};
	
	inline void Delay(Uint32 ms) {
        SDL_Delay(ms);
    }
}

#endif