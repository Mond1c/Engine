//
// function_parser.cpp
// Created by Mihail Kornilovich on 30.08.2021.

#include "function_parser.h"
#include <cmath>
#include <algorithm>

using namespace functions;

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

double Token::Sinus::Calculate(double x) const {
	return std::sin(x);
}

double Token::Cosinus::Calculate(double x) const {
	return std::cos(x);
}

double Token::Tangens::Calculate(double x) const {
	return std::tan(x);
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

void Function::Draw(SDL_Renderer *renderer) const {
    for (double x = -WIDTH / 2; x <= WIDTH / 2; x += 0.01f) {
        double y = -1 * Calculate(x) + HEIGHT / 2;
        if (y >= 0 && y <= HEIGHT) SDL_RenderDrawPointF(renderer, x + WIDTH / 2, y);
    }
}

std::unique_ptr<Function> Parser::Parse(const std::string& expression) { // x - x + 5
	std::vector<std::string> parts = Split(expression); // {"x", "-x", "+5"}
	
	std::unique_ptr<Function> function;
	
	Type type = GetTypeOfExpression(expression);
	
	if (type == Type::POWER) function = ParsePower(parts);
	else if (type == Type::LOGARITHMIC) function = ParseLogarithmic(parts);
	else if (type == Type::SINUS) function = ParseSinus(parts);
	else if (type == Type::COSINE) function = ParseCosine(parts);
	else if (type == Type::TANGENT) function = ParseTangent(parts);
	else function = ParseLinear(parts);
	
	return function;
}

std::vector<std::string> Parser::Split(const std::string& string) {
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
	if (expression.find("sin") != std::string::npos) return Type::SINUS;
    if (expression.find("cos") != std::string::npos) return Type::COSINE;
    if (expression.find("tan") != std::string::npos) return Type::TANGENT;
	return Type::LINEAR;
}

std::unique_ptr<Function> Parser::ParseLinear(std::vector<std::string>& expression) {
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

std::unique_ptr<Function> Parser::ParsePower(std::vector<std::string>& expreesion) {
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

std::unique_ptr<Function> Parser::ParseLogarithmic(std::vector<std::string>& expression) {
	std::unique_ptr<Function> function = std::make_unique<Function>();
	for (const std::string& part : expression) {
		auto it = part.find('x');
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

std::unique_ptr<Function> Parser::ParseSinus(std::vector<std::string> &expression) {
    std::unique_ptr<Function> function = std::make_unique<Function>();
    for (const std::string& part : expression) {
        auto it = part.find('x');
        if (it != std::string::npos) {
            std::string number;
            auto sinus = part.find("sin");
            if (sinus != std::string::npos) {
                number = part.substr(0, sinus);
                if (number.empty()) number = "1";
                else if (number == "-") number = "-1";
                function->AddToken(std::make_shared<Token::Sinus>(std::stod(number)));
            } else {
                number = part.substr(0, it);
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

std::unique_ptr<Function> Parser::ParseCosine(std::vector<std::string> &expression) {
    std::unique_ptr<Function> function = std::make_unique<Function>();
    for (const std::string& part : expression) {
        auto it = part.find('x');
        if (it != std::string::npos) {
            std::string number;
            auto cosinus = part.find("cos");
            if (cosinus != std::string::npos) {
                number = part.substr(0, cosinus);
                if (number.empty()) number = "1";
                else if (number == "-") number = "-1";
                function->AddToken(std::make_shared<Token::Cosinus>(std::stod(number)));
            } else {
                number = part.substr(0, it);
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

std::unique_ptr<Function> Parser::ParseTangent(std::vector<std::string> &expression) {
    std::unique_ptr<Function> function = std::make_unique<Function>();
    for (const std::string& part : expression) {
        auto it = part.find('x');
        if (it != std::string::npos) {
            std::string number;
            auto tangens = part.find("tan");
            if (tangens != std::string::npos) {
                number = part.substr(0, tangens);
                if (number.empty()) number = "1";
                else if (number == "-") number = "-1";
                function->AddToken(std::make_shared<Token::Tangens>(std::stod(number)));
            } else {
                number = part.substr(0, it);
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
