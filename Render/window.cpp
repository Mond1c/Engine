//
// window.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "window.h"
using namespace SDL;

Renderer::Renderer(SDL_Window* window, int index, Uint32 flags) noexcept {
	renderer_ = SDL_CreateRenderer(window, index, flags);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer_);
}

void Renderer::Draw(Object& object) {
	object.Draw(renderer_);
}

void Renderer::SetColor(const Color& color) {
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
}

void Renderer::Clear() {
	SDL_RenderClear(renderer_);
}

void Renderer::Update() {
	SDL_RenderPresent(renderer_);
}

SDL_Renderer* Renderer::Ptr() {
	return renderer_;
}

Window::Window(const char* title, const Vector& position, const Vector& size, Uint32 flags) noexcept {
	window_ = SDL_CreateWindow(title, position.x, position.y, size.x, size.y, flags);
}
	
Window::~Window() {
	SDL_DestroyWindow(window_);
}

SDL_Window* Window::Ptr() {
	return window_;
}