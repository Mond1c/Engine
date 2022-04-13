//
// engine.cpp
// Created by Mihail Kornilovich on 23.08.2021.
#include "engine.h"
#include "file.h"
#include "Language/parser.h"
#include <iostream>

//To load objects use objects = file.Load();


void Engine::Start() { // Here you can create start Objects and Colliders
//    auto script = language::parser::Parser::Parse("../test.script");
//    script.ShowVariables();

	window.SetColor(engine::Color(225, 255, 255));
    window.Clear();
    window.SetColor(engine::Color(0, 0, 0));
    window.Update();
    engine::File file("../Object.object");
    auto objects = file.Load();
    for (const auto& obj : objects) {
        window.Draw(*obj);
    }
    auto function = functions::Parser::Parse("x^2");
    function->Draw(window.RendererPtr());
}

void Engine::Update() { // Gameplay and Physics
    
}
