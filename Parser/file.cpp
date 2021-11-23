//
// File.cpp
// Created by Mihail Kornilovich on 23.08.2021.

#include "file.h"
using namespace engine;

std::vector<std::shared_ptr<Object>> File::Load() {
	std::fstream file(file_name_);
	if (!file) throw std::runtime_error("File does not exist");
	std::string str;
	std::string obj_info;
	std::vector<std::shared_ptr<Object>> objects;
	while (file >> str) {
		if (str.substr(0, 4) == "type" && !obj_info.empty()) {
			std::stringstream ss;
			ss << obj_info;
			//std::cout << obj_info << std::endl;
			objects.push_back(Parser::Parse(ss));
			obj_info.clear();
		}
		obj_info += str + '\n';
	}
	if (!obj_info.empty()) {
		std::stringstream ss;
		ss << obj_info;
		std::cout << obj_info << std::endl;
		objects.push_back(Parser::Parse(ss));
	}
	file.close();
	return objects;
}

void File::Save(std::vector<std::shared_ptr<Object>> objects) {
	std::ofstream file;
	file.open(file_name_);
	for (int i = 0; i < objects.size(); ++i) {
		if (!objects[i]) continue;
		file << objects[i]->GetString();
		//if (i != objects.size() - 1) file << "\n";
	}
	file.close();
}

