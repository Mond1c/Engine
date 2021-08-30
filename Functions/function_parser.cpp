//
// function_parser.cpp
// Created by Mihail Kornilovich on 30.08.2021.

#include "function_parser.h"
#include <cmath>
#include <algorithm>
using namespace Functions;

void Function::AddToken(Token&& token) {
	tokens_.push_back(token);
}

double Function::Calculate(double x) {
	double y = 0;
	for (const Token& token : tokens_) {
		y += token.number * std::pow(x, token.variable);
	}
	return y;
}

Function Parser::Parse(const std::string& expression) { // x^2 - 4*x - 5
	std::vector<std::string> parts = Split(expression);
	Function function;
	for (const std::string part : parts) {
		if (std::count(part.begin(), part.end(), 'x') > 0) {
			std::string number;
			std::string power;
			bool isPower = false;
			for (char ch : part) {
				if (ch == 'x' || ch == '*') continue;
				if (ch == '^') isPower = true;
				else if (isPower) power += ch;
				else number += ch;
			}
			if (power.empty()) power = "0";
			if (number.empty()) number = "1";
			function.AddToken(Token{std::stod(power), std::stod(number)});
		} else {
			function.AddToken(Token{0, std::stod(part)});
		}
	}
	return function;
}

std::vector<std::string> Parser::Split(const std::string string) {
	std::vector<std::string> strings;
	std::string part;
	for (char ch : string) {
		if (ch == '+' || ch == '-') {
			strings.push_back(part);
			part.clear();
		}
		if (ch != ' ') part += ch;
	}
	if (!part.empty()) strings.push_back(part);
	return strings;
}