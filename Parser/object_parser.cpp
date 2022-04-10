//
// object_parser.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "object_parser.h"
using namespace engine;

std::shared_ptr<Object> Parser::Parse(std::stringstream& stream) {
	std::string type;
	stream >> type;
	type = Split(type)[1];
	if (type == "point") {
		std::shared_ptr<shapes::Point> point = std::make_shared<shapes::Point>(Vector2f(0, 0));
		point->StringToObject(stream);
		return point;
	}
	if (type == "line") {
		std::shared_ptr<shapes::Line> line = std::make_shared<shapes::Line>(Vector2f(0, 0), Vector2f(0, 0));
		line->StringToObject(stream);
		return line;
	}
	if (type == "rect") { 
		std::shared_ptr<shapes::Rect> rect = std::make_shared<shapes::Rect>(Vector2f(0, 0), Vector2f(0, 0));
		rect->StringToObject(stream);
		return rect;
	}
	if (type == "circle") {
		std::shared_ptr<shapes::Circle> circle = std::make_shared<shapes::Circle>(Vector2f(0, 0), Vector2f(0, 0));
		circle->StringToObject(stream);
		return circle;
	}
	if (type == "circumference") { 
		std::shared_ptr<shapes::Circumference> circumference = std::make_shared<shapes::Circumference>(Vector2f(0, 0), Vector2f(0, 0));
		circumference->StringToObject(stream);
	}
	if (type == "trinagle") {
		std::shared_ptr<shapes::Triangle> trinagle = std::make_shared<shapes::Triangle>(Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
		trinagle->StringToObject(stream);
		return trinagle;
	}
	if (type == "polygon") {
		std::shared_ptr<shapes::Polygon> polygon = std::make_shared<shapes::Polygon>(std::vector<Vector2f>{});
		polygon->StringToObject(stream);
		return polygon;
	}
	return nullptr;
}

std::vector<std::string> Parser::Split(const std::string& str) {
	std::vector<std::string> words;
	std::string word;
	
	for (char ch : str) {
		if (ch == ',' || ch == '=') {
			words.push_back(word);
			word.clear();
		} else word += ch;
	}
	if (!word.empty()) words.push_back(word);
	return words;
}