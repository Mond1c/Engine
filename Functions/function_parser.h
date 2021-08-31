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
	class IToken {
	public:
		double number;
		
		IToken(double number) : number(number) {}
		
		virtual double Calculate(double x) const = 0;
		
		virtual ~IToken() {}
	};
	
	namespace Token {
		class Number : public IToken {
		public:
			Number(double number) : IToken(number) {}
			
			double Calculate(double x) const override;
			
			~Number() {}
		};
		
		class Linear : public IToken {
		public:
			Linear(double number) : IToken(number) {}
			
			double Calculate(double x) const override;
			
			~Linear() {}
		};
		
		class Power : public IToken {
		public:
			double power;
			
			Power(double number, double power) : IToken(number), power(power) {}
			
			double Calculate(double x) const override;
			
			~Power() {}
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
		
		static std::unique_ptr<Function> ParseLinearFunction(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParsePowerFunction(std::vector<std::string>& expression);
	};
}
#endif