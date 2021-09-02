//
// function_parser.cpp
// Created by Mihail Kornilovich on 30.08.2021.

#include "function_parser.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace Functions;

double Token::Number::Calculate(double x) const {
	return number;
}

double Token::Linear::Calculate(double x) const {
	return number * x;
}

double Token::Power::Calculate(double x) const {
	return number * std::pow(x, power);
}

double Token::Logarithmic::Calculate(double x) const {
	return log(x) / log(base);
}

void Function::AddToken(std::shared_ptr<IToken> token) {
	tokens_.push_back(token);
}

double Function::Calculate(double x) const {
	double y = 0;
	for (const std::shared_ptr<IToken> token : tokens_) {
		y += token->Calculate(x);
	}
	return y;
}

std::vector<std::shared_ptr<IToken>>& Function::GetTokens() {
	return tokens_;
}

std::unique_ptr<Function> Parser::Parse(const std::string& expression) { // x - x + 5
	std::vector<std::string> parts = Split(expression); // {"x", "-x", "+5"}
	
	std::unique_ptr<Function> function;
	
	Type type = GetTypeOfExpression(expression);
	
	if (type == Type::POWER) function = ParsePowerFunction(parts);
	else if (type == Type::LOGARITHMIC) function = ParseLogarithmicFunction(parts);
	else function = ParseLinearFunction(parts);
	
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

Parser::Type Parser::GetTypeOfExpression(const std::string& expression) {
	if (expression.find('^') != std::string::npos) return Type::POWER;
	if (expression.find("log") != std::string::npos) return Type::LOGARITHMIC;
	return Type::LINEAR;
}

std::unique_ptr<Function> Parser::ParseLinearFunction(std::vector<std::string>& expression) {
	std::unique_ptr<Function> function = std::make_unique<Function>();
	for (const std::string& part : expression) {
		auto it = part.find('x');
		if (it != std::string::npos) {
			std::string number = part.substr(0, it);
			//std::cout << number << std::endl;
			if (number.empty()) number = "1";
			else if (number == "-") number = "-1";
			function->AddToken(std::make_shared<Token::Linear>(std::stod(number)));
		} else {
			function->AddToken(std::make_shared<Token::Number>(std::stod(part)));
		}
	}
	return function;
}

std::unique_ptr<Function> Parser::ParsePowerFunction(std::vector<std::string>& expreesion) {
	std::unique_ptr<Function> function = std::make_unique<Function>();
	for (const std::string& part : expreesion) {
		auto it = part.find('x');
		if (it != std::string::npos) {
			if (it + 1 < part.size() && part[it + 1] == '^') {
				std::string number = part.substr(0, it);
				std::string power = part.substr(it + 2, part.size());
				if (number.empty()) number = "1";
				else if (number == "-") number = "-1";
				function->AddToken(std::make_shared<Token::Power>(std::stod(number), std::stod(power)));
			} else {
				std::string number = part.substr(0, it);
				if (number.empty()) number = "1";
				else if (number == "-") number = "-1";
				function->AddToken(std::make_shared<Token::Linear>(std::stod(number)));
			}
		} else {
			function->AddToken(std::make_shared<Token::Number>(std::stod(part)));
		}
	}
	return function;
}

std::unique_ptr<Function> Parser::ParseLogarithmicFunction(std::vector<std::string>& expression) {
	std::unique_ptr<Function> function = std::make_unique<Function>();
	for (const std::string& part : expression) {
		auto it = part.find("x");
		if (it != std::string::npos) {
			auto lg = part.find("log");
			std::string number;
			std::string base;
			if (lg != std::string::npos) {
				base = part.substr(lg + 3, it - 2);
				number = part.substr(0, lg);
				if (number.empty()) number = "1";
				else if (number == "-") number = "-1";
				function->AddToken(std::make_shared<Token::Logarithmic>(std::stod(number), std::stod(base)));
			} else {
				number = part.substr(0, it);
				if (number.empty()) number = "1";
				else if(number == "-") number = "-1";
				function->AddToken(std::make_shared<Token::Linear>(std::stod(number)));
			}
		} else {
			function->AddToken(std::make_shared<Token::Number>(std::stod(part)));
		}
	}
	return function;
}