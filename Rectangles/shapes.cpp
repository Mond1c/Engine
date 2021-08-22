//
// shapes.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "shapes.h"

using namespace SDL;


Vector Object::GetPosition() const {
	return position;
}

Vector Object::GetSize() const {
	return size;
}


void Point::Draw(SDL_Renderer* renderer) const {
	SDL_RenderDrawPointF(renderer, position.x, position.y);
}