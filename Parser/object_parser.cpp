//
// object_parser.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "object_parser.h"
#include <iostream>
using namespace SDL;

Object* Parser::Parse(std::stringstream& stream) {
	std::string str;
	std::string type;
	Vector position(0, 0), size(0, 0), second_point(0, 0), third_point(0, 0);
	int state = 0;
	while (stream >> str) {
		std::vector<std::string> elements = Split(str);
		if (elements[0] == "position" && state == 0) {
			position = Vector(std::stof(elements[1]), std::stof(elements[2]));
			state = 1;
		} else if (elements[0] == "position" && state == 1) {
			second_point = Vector(std::stof(elements[1]), std::stof(elements[2]));
			state = 2;
		} else if (elements[0] == "position" && state == 2) {
			third_point = Vector(std::stof(elements[1]), std::stof(elements[2]));
		} else if (elements[0] == "size") {
			size = Vector(std::stof(elements[1]), std::stof(elements[2]));
		} else if (elements[0] == "type") {
			type = elements[1];
		}
	}
	if (type == "point") return new Shapes::Point(position);
	if (type == "line") return new Shapes::Line(position, second_point);
	if (type == "rect") return new Shapes::Rect(position, size);
	if (type == "circle") return new Shapes::Circle(position, size);
	if (type == "circumference") return new Shapes::Circumference(position, size);
	if (type == "trinagle") return new Shapes::Trinagle(position, second_point, third_point);
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