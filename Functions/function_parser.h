//
// function_parser.h
// Created by Mihail Kornilovich on 30.08.2021.
#pragma once

#ifndef _function_parser_h_
#define _function_parser_h_

#include <string>
#include <vector>
#include <memory>

namespace Functions {
	struct IToken {
		double number;
		
		IToken(double number) : number(number) {}
		
		virtual double Calculate(double x) const = 0;
		
		virtual ~IToken() {}
	};
	
	namespace Token {
		struct Number : public IToken {
			Number(double number) : IToken(number) {}
			
			double Calculate(double x) const override;
			
			~Number() {}
		};
		
		struct Linear : public IToken {
			Linear(double number) : IToken(number) {}
			
			double Calculate(double x) const override;
			
			~Linear() {}
		};
		
		struct Power : public IToken {
			double power;
			
			Power(double number, double power) : IToken(number), power(power) {}
			
			double Calculate(double x) const override;
			
			~Power() {}
		};
		
		struct Logarithmic : public IToken {
			double base;
			
			Logarithmic(double number, double base) : IToken(number), base(base) {}
			
			double Calculate(double x) const override;
			
			~Logarithmic() {}
		};
	}
	
	class Function {
	public:

		void AddToken(std::shared_ptr<IToken> token);
		
		double Calculate(double x) const;
		std::vector<std::shared_ptr<IToken>>& GetTokens();
	private:
		std::vector<std::shared_ptr<IToken>> tokens_;
	};
	
	class Parser {
	public:
		static std::unique_ptr<Function> Parse(const std::string& expression);
	private:
		static std::vector<std::string> Split(const std::string string);
		
		enum class Type {
			LINEAR,
			POWER,
			LOGARITHMIC
		};
		
		static Type GetTypeOfExpression(const std::string& expression);
		
		static std::unique_ptr<Function> ParseLinearFunction(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParsePowerFunction(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParseLogarithmicFunction(std::vector<std::string>& expression);
	};
}
#endif