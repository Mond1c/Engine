//
// collider.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "collider.h"
using namespace Physics;

SDL::Vector ICollider::GetPosition() const {
	return position_;
}

SDL::Vector ICollider::GetSize() const {
	return size_;
}