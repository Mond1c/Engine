//
// shapes.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _shapes_h_
#define _shapes_h_

#include "vector.h"
#include <SDL2/SDL.h>


namespace SDL {	
	class Object {
	public:
		Object(const Vector& position, const Vector& size) :
			position(position), size(size) {}
		virtual ~Object() {
			
		}
		
		Vector GetPosition() const;
		Vector GetSize() const;
		
		virtual void Draw(SDL_Renderer* renderer) const = 0;
	protected:
		Vector position;
		Vector size;
	};
	
	class Point : public Object {
	public:
		Point(const Vector& position) :
			Object(position, {1, 1}) {}
		~Point() {}
		
		void Draw(SDL_Renderer* renderer) const override;
	};
}

#endif