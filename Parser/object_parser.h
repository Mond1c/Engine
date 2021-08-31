//
// object_parser.h
// Created by Mihail Kornilovich on 23.08.2021.
#pragma once

#ifndef _object_parser_h_
#define _object_parser_h_
#include "../Objects/shapes.h"
#include <sstream>
#include <vector>
#include <memory>

namespace SDL {
	class Parser {
	public:
		Parser() = delete;
		Parser(const Parser&) = delete;
		Parser(Parser&&) = delete;
		
		Parser& operator=(const Parser&) = delete;
		Parser& operator=(Parser&&) = delete;
		
		static std::shared_ptr<SDL::Object> Parse(std::stringstream& stream);
		static std::vector<std::string> Split(const std::string& str);
	};
}

#endif