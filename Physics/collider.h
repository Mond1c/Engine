//
// collider.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _collider_h_
#define _collider_h_

#include "../Objects/shapes.h"
#include "../settings.h"

namespace Physics {
	class ICollider {
	public:
		ICollider(const SDL::Vector& position, const SDL::Vector& size) :
			position_(position), size_(size) {}
		virtual ~ICollider();
		
		virtual void Update() = 0;
		
		SDL::Vector GetPosition() const;
		SDL::Vector GetSize() const;
	private:
		SDL::Vector position_;
		SDL::Vector size_;
	};
	
	namespace Collider {
		
	}
	
	inline bool DetectCollision(const ICollider& c1, const ICollider& c2);
}

#endif