//
// shapes.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "shapes.h"
#include <cmath>
using namespace SDL;



Vector Object::GetPosition() const {
	return position_;
}

Vector Object::GetSize() const {
	return size;
}


void Point::Draw(SDL_Renderer* renderer) const {
	SDL_RenderDrawPointF(renderer, position_.x, position_.y);
}

void Line::Draw(SDL_Renderer* renderer) const {
	SDL_RenderDrawLineF(renderer, position_.x, position_.y, finish.x, finish.y);
}

void Rect::Draw(SDL_Renderer* renderer) const {
	SDL_RenderDrawRectF(renderer, &rect_);
}

void Rect::Fill(SDL_Renderer* renderer) {
	SDL_RenderFillRectF(renderer, &rect_);
}

void Circle::Draw(SDL_Renderer* renderer) const {
	for (float y = position_.y - size.x; y < position_.y + size.x; ++y) {
		for (float x = position_.x - size.x; x < position_.x + size.x; ++x) {
			if ((position_.x - x)*(position_.x - x) + (position_.y - y)*(position_.y - y) <= 
				size.x) {
				SDL_RenderDrawPointF(renderer, x, y); 
			}
		}
	}
}

void Circumference::Draw(SDL_Renderer* renderer) const {
	float CircumferenceSize = size.x / 5;
	
	for (float y = position_.y - size.x; y < position_.y + size.x; ++y) {
		for (float x = position_.x - size.x; x < position_.x + size.x; ++x) {
			float length =(position_.x - x)*(position_.x - x) + (position_.y - y)*(position_.y - y);  
			if (length >= size.x - CircumferenceSize &&
				length <= size.x) {
					SDL_RenderDrawPointF(renderer, x, y); 
				}
		}
	}
}

namespace {
	// Вычисляет положение точки D(xd,yd) относительно прямой AB
	double g(const Vector& a, const Vector& b, const Vector& d) {
		return (d.x - a.x) * (b.y - a.y) - (d.y - a.y) * (b.x - a.x);
	}
	
	// Лежат ли точки C и D с одной стороны прямой (AB)?
	bool f(const Vector& a, const Vector& b, const Vector& c, const Vector& d) {
		return g(a, b, c) * g(a, b, d) >= 0;
	}
}

void Trinagle::Draw(SDL_Renderer* renderer) const {	
	float start_x = std::fminf(position_.x, std::fminf(second_point_.x, third_point_.x));
	float start_y = std::fminf(position_.y, std::fminf(second_point_.y, third_point_.y));
	float finish_x = std::fmaxf(position_.x, std::fmaxf(second_point_.x, third_point_.x));
	float finish_y = std::fmaxf(position_.y, std::fmaxf(second_point_.y, third_point_.y));
	
	for (float y0 = start_y; y0 <= finish_y; ++y0) {
		for (float x0 = start_x; x0 <= finish_x; ++x0) {
			Vector a = position_;
			Vector b = second_point_;
			Vector c = third_point_;
			Vector d = Vector(x0, y0);
			if (f(a,b,c,d) && f(b,c,a,d) && f(c,a,b,d)) {
				SDL_RenderDrawPointF(renderer, x0, y0);
			}
		}
	}
}