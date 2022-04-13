//
// collider.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _collider_h_
#define _collider_h_

#include "shapes.h"
#include "component.h"
#include "settings.h"
#include <vector>

namespace engine {
	class ICollider : public IComponent {
	public:
		ICollider(const engine::Vector2f& position, const engine::Vector2f& size, engine::Object& object, double mass) :
			position_(position), size_(size), object_(object), mass_(mass), speed_({0, 0}) {}

		void Update() override;
		
		[[nodiscard]] engine::Vector2f GetPosition() const;
        [[nodiscard]] engine::Vector2f GetSize() const;
        [[nodiscard]] engine::Vector2f GetSpeed() const;
		
		void SetSpeed(const engine::Vector2f& speed);
	protected:
        engine::Vector2f position_;
        engine::Vector2f size_;
        engine::Vector2f speed_;
        engine::Object& object_;
		
		double mass_;
	};
	
	namespace collider {
		class Rect : public ICollider {
		public:
			Rect(const engine::Vector2f& position, const engine::Vector2f& size, engine::shapes::Rect& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Rect() override = default;
		};
		
		class Circle : public ICollider {
		public:
			Circle(const engine::Vector2f& position, const engine::Vector2f& size, engine::shapes::Circle& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circle() override = default;
		};
		
		class Circumference : public ICollider {
		public:
			Circumference(const engine::Vector2f& position, const engine::Vector2f& size, engine::shapes::Circumference& object, double mass) :
				ICollider(position, size, object, mass) {}
			~Circumference() override = default;
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