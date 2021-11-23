//
// collider.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _collider_h_
#define _collider_h_

#include "../Objects/shapes.h"
#include "../settings.h"
#include <vector>

namespace engine {
	class ICollider {
	public:
		ICollider(const engine::Vector& position, const engine::Vector& size, engine::Object& object, double mass) :
			position_(position), size_(size), object_(object), mass_(mass), speed_({0, 0}) {}
		virtual ~ICollider() {}
		
		void Update(std::vector<ICollider*>& objects);
		
		engine::Vector GetPosition() const;
        engine::Vector GetSize() const;
        engine::Vector GetSpeed() const;
		
		void SetSpeed(const engine::Vector& speed);
	protected:
        engine::Vector position_;
        engine::Vector size_;
        engine::Vector speed_;
        engine::Object& object_;
		
		double mass_;
	};
	
	namespace collider {
		class Rect : public ICollider {
		public:
			Rect(const engine::Vector& position, const engine::Vector& size, engine::shapes::Rect& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Rect() {}
		};
		
		class Circle : public ICollider {
		public:
			Circle(const engine::Vector& position, const engine::Vector& size, engine::shapes::Circle& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circle() {}
		};
		
		class Circumference : public ICollider {
		public:
			Circumference(const engine::Vector& position, const engine::Vector& size, engine::shapes::Circumference& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circumference() {}
		};
	}
	
	namespace {
		inline bool DetectCollision(const collider::Rect& r1, const collider::Rect& r2);
		inline bool DetectCollision(const collider::Rect& r, const collider::Circle& c);
		inline bool DetectCollision(const collider::Rect& r, const collider::Circumference& c);
		inline bool DetectCollision(const collider::Circle& c, const collider::Rect& r);
		inline bool DetectCollision(const collider::Circumference& c, const collider::Rect& r);
		inline bool DetectCollision(const collider::Circle& c1, const collider::Circle& c2);
		inline bool DetectCollision(const collider::Circle& c1, const collider::Circumference& c2);
		inline bool DetectCollision(const collider::Circumference& c1, const collider::Circle& c2);
		inline bool DetectCollision(const collider::Circumference& c1, const collider::Circumference& c2);
	}
	
	inline bool DetectCollision(const ICollider& c1, const ICollider& c2);
}

#endif