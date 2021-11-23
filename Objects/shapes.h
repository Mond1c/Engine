//
// shapes.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _shapes_h_
#define _shapes_h_

#include "vector.h"
#include <SDL.h>
#include <iostream>
#include <utility>
#include <vector>


namespace SDL {	
	struct Color {
		Uint8 r, g, b, a;
		explicit Color(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255) :
			r(r), g(g), b(b), a(a) {}
	};
	
	class Object {
	public:
		Object(const Vector& position, const Vector& size) :
			position_(position), size_(size) {}
		virtual ~Object() = default;
		
		
		[[nodiscard]] const Vector& GetPosition() const;
		[[nodiscard]] const Vector& GetSize() const;
		
		void SetPosition(const Vector& position);
		
		virtual void Draw(SDL_Renderer* renderer) = 0;
		[[nodiscard]] virtual std::string GetString() const = 0;
		
		virtual void StringToObject(std::stringstream& ss) = 0;
	protected:
		Vector position_;
		Vector size_;
	};
	
	namespace Shapes {
		
		class Point : public Object {
		public:
			explicit Point(const Vector& position) :
			Object(position, {1, 1}) {}
			~Point() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Line : public Object {
		public:
			Line(const Vector& start, const Vector& finish) : Object(start, {finish.x - start.x, 1}), finish(finish) {}
			~Line() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
			Vector finish;
		};
		
		class Rect : public Object {
		public:
			Rect(const Vector& position, const Vector& size) : Object(position, size) {
				rect_ = {position.x, position.y, position.x + size.x, position.y + size.y};
			}
			~Rect() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			void Fill(SDL_Renderer* renderer);
			
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
			SDL_FRect rect_{};
		};
		
		class Circle : public Object {
		public:
			Circle(const Vector& position, const Vector& size) : Object(position, size) {}
			~Circle() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Circumference : public Object {
		public:
			Circumference(const Vector& position, const Vector& size) : Object(position, size) {}
			~Circumference() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Triangle : public Object {
		public:
			Triangle(const Vector& first_point, const Vector& second_point, const Vector& third_point) :
			Object(first_point, {0, 0}), second_point_(second_point), third_point_(third_point) {}
			~Triangle() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
			Vector second_point_;
			Vector third_point_;
		};
		
		class Polygon : public Object {
		public:
			explicit Polygon(std::vector<Vector>  points) : Object({0, 0}, {0, 0}), points_(std::move(points)) {}
			~Polygon() override = default;
		
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
			std::vector<Vector> points_;
		};
	}
}

#endif
