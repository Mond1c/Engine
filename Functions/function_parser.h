//
// function_parser.h
// Created by Mihail Kornilovich on 30.08.2021.
#pragma once

#ifndef _function_parser_h_
#define _function_parser_h_

#include <string>
#include <vector>

namespace Functions {
	namespace {
		struct Token {
			double variable; // Only power of variable. If power equals 0 means that variable does not exist
			double number;
		};
	}
	
	class Function {
	public:
		void AddToken(Token&& token);
		
		double Calculate(double x) const;
		std::vector<Token>& GetTokens();
	private:
		std::vector<Token> tokens_;
	};
	
	class Parser {
	public:
		static Function Parse(const std::string& expression);
	private:
		static std::vector<std::string> Split(const std::string string);
		static void Simplification(std::vector<Token>& tokens);
	};
}
#endif