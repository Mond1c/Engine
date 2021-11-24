//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include <iostream>

//To load objects use objects = file.Load();
using namespace engine;
using namespace shapes;

class Player : public Circle {
public:
    Player(const Vector2f& position, const Vector2f& size, const Vector2f& speed) : Circle(position, size),
                                                                                             speed_(speed) {}

    void Move() {
        if (position_.x < 0 && speed_.x < 0) speed_.x *= -1;
        else if (position_.x >= WIDTH && speed_.x > 0) speed_.x *= -1;
        if (position_.y < 0 && speed_.y < 0) speed_.y *= -1;
        else if (position_.y >= HEIGHT && speed_.y > 0) speed_.y *= -1;
        position_ += speed_;
    }
private:
    Vector2f speed_;
};

std::shared_ptr<Player> player;

void Engine::Start() { // Here you can create start Objects and Colliders
	window.SetColor(Color(225, 255, 255));
    window.Clear();
    window.SetColor(Color(0, 0, 0));
	player = std::make_shared<Player>(Vector2f(WIDTH / 2, HEIGHT / 2), Vector2f(50, 50), Vector2f(10, 10));

    window.Update();
}

void Engine::Update() { // Gameplay and Physics
    window.SetColor(Color(255, 255, 255));
    window.Clear();
    window.SetColor(Color(0, 0, 0));
    player->Move();
    player->Draw(window.RendererPtr());
}
