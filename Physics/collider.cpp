//
// collider.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "collider.h"
#include "engine.h"
using namespace engine;
using namespace collider;

Vector2f ICollider::GetPosition() const {
	return position_;
}

Vector2f ICollider::GetSize() const {
	return size_;
}

Vector2f ICollider::GetSpeed() const {
	return speed_;
}

void ICollider::SetSpeed(const Vector2f& speed) {
	speed_ = speed;
}

void ICollider::Update() {
	for (const auto& collider : COLLIDERS) {
		if (this != collider.get() && DetectCollision(*this, *collider)) {
			speed_.x = ((mass_ - collider->mass_) * speed_.x + 2 * collider->mass_ * collider->speed_.x) / (mass_ + collider->mass_);
			speed_.y = ((mass_ - collider->mass_) * speed_.y + 2 * collider->mass_ * collider->speed_.y) / (mass_ + collider->mass_);
			
			collider->speed_.x = ((collider->mass_ - mass_) * collider->speed_.x + 2 * mass_ * speed_.x) / (mass_ + collider->mass_);
			collider->speed_.y = ((collider->mass_ - mass_) * collider->speed_.y + 2 * mass_ * speed_.y) / (mass_ + collider->mass_);
		}
	}
	
	position_ += speed_;
	position_.y += GRAVITY * mass_;
	object_.SetPosition(position_);
}

namespace {
	inline bool DetectCollision(const collider::Rect& r1, const collider::Rect& r2) {
        Vector2f p1 = r1.GetPosition();
        Vector2f s1 = r1.GetSize();
        Vector2f p2 = r2.GetPosition();
        Vector2f s2 = r2.GetSize();
		
		return  p1.x < p2.x + s2.x &&
				p1.x + s1.x > p2.x &&
				p1.y < p2.y + s2.y &&
				p1.y + s1.y > p2.y;
	}
	
	inline bool DetectCollision(const collider::Rect& r, const collider::Circle& c) {
        Vector2f center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const collider::Rect& r, const collider::Circumference& c) {
        Vector2f center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const collider::Circle& c, const collider::Rect& r) {
        Vector2f center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const collider::Circumference& c, const collider::Rect& r) {
        Vector2f center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const collider::Circle& c1, const collider::Circle& c2) {
        Vector2f pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const collider::Circle& c1, const collider::Circumference& c2) {
        Vector2f pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const collider::Circumference& c1, const collider::Circle& c2) {
        Vector2f pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const collider::Circumference& c1, const collider::Circumference& c2) {
        Vector2f pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
}

inline bool engine::DetectCollision(const ICollider& c1, const ICollider& c2) {
	return ::DetectCollision(c1, c2);
}

