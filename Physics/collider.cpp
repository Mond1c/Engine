//
// collider.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "collider.h"
using namespace Physics;
using namespace Collider;

SDL::Vector ICollider::GetPosition() const {
	return position_;
}

SDL::Vector ICollider::GetSize() const {
	return size_;
}

SDL::Vector ICollider::GetSpeed() const {
	return speed_;
}

void ICollider::SetSpeed(const SDL::Vector& speed) {
	speed_ = speed;
}

void ICollider::Update(std::vector<ICollider*>& objects) {
	for (ICollider* collider : objects) {
		if (this != collider && DetectCollision(*this, *collider)) {
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
	inline bool DetectCollision(const Collider::Rect& r1, const Collider::Rect& r2) {
		SDL::Vector p1 = r1.GetPosition();
		SDL::Vector s1 = r1.GetSize();
		SDL::Vector p2 = r2.GetPosition();
		SDL::Vector s2 = r2.GetSize();
		
		return  p1.x < p2.x + s2.x &&
				p1.x + s1.x > p2.x &&
				p1.y < p2.y + s2.y &&
				p1.y + s1.y > p2.y;
	}
	
	inline bool DetectCollision(const Collider::Rect& r, const Collider::Circle& c) {
		SDL::Vector center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const Collider::Rect& r, const Collider::Circumference& c) {
		SDL::Vector center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const Collider::Circle& c, const Collider::Rect& r) {
		SDL::Vector center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const Collider::Circumference& c, const Collider::Rect& r) {
		SDL::Vector center_vector = c.GetPosition() - r.GetPosition();
		float rect_w = r.GetSize().x, rect_h = r.GetSize().y;
		float radius = c.GetSize().x;
		float dist_x = fabs(center_vector.x) - rect_w / 2;
		float dist_y = fabs(center_vector.y) - rect_h / 2;
		
		if (dist_x > radius || dist_y > radius) return false;
		if (dist_x < 1e-3 || dist_y < 1e-3) return true;
		
		return dist_x * dist_x + dist_y * dist_y < (radius * radius + 1e-3);
	}
	
	inline bool DetectCollision(const Collider::Circle& c1, const Collider::Circle& c2) {
		SDL::Vector pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const Collider::Circle& c1, const Collider::Circumference& c2) {
		SDL::Vector pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const Collider::Circumference& c1, const Collider::Circle& c2) {
		SDL::Vector pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
	
	inline bool DetectCollision(const Collider::Circumference& c1, const Collider::Circumference& c2) {
		SDL::Vector pos1 = c1.GetPosition(), pos2 = c2.GetPosition();
		float dx = pos1.x - pos2.x;
		float dy = pos1.y - pos2.y;
		float r1 = c1.GetSize().x, r2 = c2.GetSize().x;
		return dx * dx + dy * dy < (r1 + r2) * (r1 + r2);
	}
}

inline bool Physics::DetectCollision(const ICollider& c1, const ICollider& c2) {
	return ::DetectCollision(c1, c2);
}