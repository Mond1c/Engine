//
// object_parser.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "object_parser.h"
#include <iostream>
using namespace SDL;

Object* Parser::Parse(std::stringstream& stream) {
	std::string type;
	stream >> type;
	type = Split(type)[1];
	if (type == "point") {
		Shapes::Point* point = new Shapes::Point({0, 0});
		point->stringToObject(stream);
		return point;
	}
	if (type == "line") {
		Shapes::Line* line = new Shapes::Line({0, 0}, {0, 0});
		line->stringToObject(stream);
		return line;
	}
	if (type == "rect") { 
		Shapes::Rect* rect = new Shapes::Rect({0, 0}, {0, 0});
		rect->stringToObject(stream);
		return rect;
	}
	if (type == "circle") {
		Shapes::Circle* circle = new Shapes::Circle({0, 0}, {0, 0});
		circle->stringToObject(stream);
		return circle;
	}
	if (type == "circumference") { 
		Shapes::Circumference* circumference = new Shapes::Circumference({0, 0}, {0, 0});
		circumference->stringToObject(stream);
	}
	if (type == "trinagle") {
		Shapes::Trinagle* trinagle = new Shapes::Trinagle({0, 0}, {0, 0}, {0, 0});
		trinagle->stringToObject(stream);
		return trinagle;
	}
	if (type == "polygon") {
		Shapes::Polygon* polygon = new Shapes::Polygon({});
		polygon->stringToObject(stream);
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