//
// object_parser.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once

#ifndef _object_parser_h_
#define _object_parser_h_
#include "../Objects/shapes.h"
#include <fstream>
#include <vector>

namespace SDL {
	class Parser {
	public:
		static SDL::Object* Parse(const char* file_name);
		static std::vector<std::string> Split(const std::string& str);
	};
}

#endif