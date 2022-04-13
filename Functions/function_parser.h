//
// function_parser.h
// Created by Mihail Kornilovich on 30.08.2021.
#pragma once

#ifndef _function_parser_h_
#define _function_parser_h_

#include "settings.h"

#include <string>
#include <vector>
#include <memory>
#include <SDL.h>

namespace functions {
	struct IToken {
		double number;
		
		explicit IToken(double number) : number(number) {}
		
		[[nodiscard]] virtual double Calculate(double x) const = 0;

		
		virtual ~IToken() = default;
	};
	
	namespace Token {
		struct Number : public IToken {
			explicit Number(double number) : IToken(number) {}
			
			[[nodiscard]] double Calculate(double x) const override;
			
			~Number() override = default;
		};
		
		struct Linear : public IToken {
			explicit Linear(double number) : IToken(number) {}
			
			[[nodiscard]] double Calculate(double x) const override;
			
			~Linear() override = default;
		};
		
		struct Power : public IToken {
			double power;
			
			Power(double number, double power) : IToken(number), power(power) {}
			
			[[nodiscard]] double Calculate(double x) const override;

			
			~Power() override = default;
		};
		
		struct Logarithmic : public IToken {
			double base;
			
			Logarithmic(double number, double base) : IToken(number), base(base) {}
			
			[[nodiscard]] double Calculate(double x) const override;
			
			~Logarithmic() override = default;
		};
		
		struct Sinus : public IToken {
			explicit Sinus(double number) : IToken(number) {}
			[[nodiscard]] double Calculate(double x) const override;

			~Sinus() override = default;
		};
		
		struct Cosinus : public IToken {
			explicit Cosinus(double number) : IToken(number) {}
			[[nodiscard]] double Calculate(double x) const override;

			~Cosinus() override = default;
		};
		
		struct Tangens : public IToken {
			explicit Tangens(double number) : IToken(number) {}
			[[nodiscard]] double Calculate(double x) const override;

			~Tangens() override = default;
		};
	}
	
	class Function {
	public:

		void AddToken(std::shared_ptr<IToken> token);
		
		[[nodiscard]] double Calculate(double x) const;
		void Draw(SDL_Renderer* renderer) const;
		std::vector<std::shared_ptr<IToken>>& GetTokens();
	private:
		std::vector<std::shared_ptr<IToken>> tokens_;
	};
	
	class Parser {
	public:
		static std::unique_ptr<Function> Parse(const std::string& expression);
	private:
		static std::vector<std::string> Split(const std::string& string);
		
		enum class Type {
			LINEAR,
			POWER,
			LOGARITHMIC,
			SINUS,
			COSINE,
			TANGENT
		};
		
		static Type GetTypeOfExpression(const std::string& expression);
		
		static std::unique_ptr<Function> ParseLinear(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParsePower(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParseLogarithmic(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParseSinus(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParseCosine(std::vector<std::string>& expression);
		static std::unique_ptr<Function> ParseTangent(std::vector<std::string>& expression);
	};
}
#endif