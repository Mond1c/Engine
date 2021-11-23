//
// object_parser.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "object_parser.h"
#include <iostream>
using namespace SDL;

std::shared_ptr<Object> Parser::Parse(std::stringstream& stream) {
	std::string type;
	stream >> type;
	type = Split(type)[1];
	if (type == "point") {
		std::shared_ptr<Shapes::Point> point = std::make_shared<Shapes::Point>(Vector(0, 0));
		point->StringToObject(stream);
		return point;
	}
	if (type == "line") {
		std::shared_ptr<Shapes::Line> line = std::make_shared<Shapes::Line>(Vector(0, 0), Vector(0, 0));
		line->StringToObject(stream);
		return line;
	}
	if (type == "rect") { 
		std::shared_ptr<Shapes::Rect> rect = std::make_shared<Shapes::Rect>(Vector(0, 0), Vector(0, 0));
		rect->StringToObject(stream);
		return rect;
	}
	if (type == "circle") {
		std::shared_ptr<Shapes::Circle> circle = std::make_shared<Shapes::Circle>(Vector(0, 0), Vector(0, 0));
		circle->StringToObject(stream);
		return circle;
	}
	if (type == "circumference") { 
		std::shared_ptr<Shapes::Circumference> circumference = std::make_shared<Shapes::Circumference>(Vector(0, 0), Vector(0, 0));
		circumference->StringToObject(stream);
	}
	if (type == "trinagle") {
		std::shared_ptr<Shapes::Triangle> trinagle = std::make_shared<Shapes::Triangle>(Vector(0, 0), Vector(0, 0), Vector(0, 0));
		trinagle->StringToObject(stream);
		return trinagle;
	}
	if (type == "polygon") {
		std::shared_ptr<Shapes::Polygon> polygon = std::make_shared<Shapes::Polygon>(std::vector<Vector>{});
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