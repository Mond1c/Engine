//
// collider.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _collider_h_
#define _collider_h_

#include "../Objects/shapes.h"
#include "../settings.h"
#include <vector>

namespace Physics {
	class ICollider {
	public:
		ICollider(const SDL::Vector& position, const SDL::Vector& size, SDL::Object& object, double mass) :
			position_(position), size_(size), object_(object), mass_(mass), speed_({0, 0}) {}
		virtual ~ICollider() {}
		
		void Update(std::vector<ICollider*>& objects);
		
		SDL::Vector GetPosition() const;
		SDL::Vector GetSize() const;
		SDL::Vector GetSpeed() const;
		
		void SetSpeed(const SDL::Vector& speed);
	protected:
		SDL::Vector position_;
		SDL::Vector size_;
		SDL::Vector speed_;
		SDL::Object& object_;
		
		double mass_;
	};
	
	namespace Collider {
		class Rect : public ICollider {
		public:
			Rect(const SDL::Vector& position, const SDL::Vector& size, SDL::Shapes::Rect& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Rect() {}
		};
		
		class Circle : public ICollider {
		public:
			Circle(const SDL::Vector& position, const SDL::Vector& size, SDL::Shapes::Circle& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circle() {}
		};
		
		class Circumference : public ICollider {
		public:
			Circumference(const SDL::Vector& position, const SDL::Vector& size, SDL::Shapes::Circumference& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circumference() {}
		};
	}
	
	namespace {
		inline bool DetectCollision(const Collider::Rect& r1, const Collider::Rect& r2);
		inline bool DetectCollision(const Collider::Rect& r, const Collider::Circle& c);
		inline bool DetectCollision(const Collider::Rect& r, const Collider::Circumference& c);
		inline bool DetectCollision(const Collider::Circle& c, const Collider::Rect& r);
		inline bool DetectCollision(const Collider::Circumference& c, const Collider::Rect& r);
		inline bool DetectCollision(const Collider::Circle& c1, const Collider::Circle& c2);
		inline bool DetectCollision(const Collider::Circle& c1, const Collider::Circumference& c2);
		inline bool DetectCollision(const Collider::Circumference& c1, const Collider::Circle& c2);
		inline bool DetectCollision(const Collider::Circumference& c1, const Collider::Circumference& c2);
	}
	
	inline bool DetectCollision(const ICollider& c1, const ICollider& c2);
}

#endif