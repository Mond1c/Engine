//
// File.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "file.h"
using namespace SDL;

std::vector<Object*> File::Load() {
	if (!file) throw std::runtime_error("File does not exist");
	std::string str;
	std::string obj_info;
	std::vector<Object*> objects;
	while (file >> str) {
		if (str[0] == '#') {
			std::stringstream ss;
			ss << obj_info;
			objects.push_back(Parser::Parse(ss));
			obj_info.clear();
		} else {
			obj_info += str + '\n';
		}
	}
	if (!obj_info.empty()) {
		std::stringstream ss;
		ss << obj_info;
		objects.push_back(Parser::Parse(ss));
	}
	return objects;
}
