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


namespace engine {

    Vector2f ParseVector2f(const std::string& x, const std::string& y);


	struct Color {
		Uint8 r, g, b, a;
		explicit Color(Uint8 r = 0, Uint8 g = 0, Uint8 b = 0, Uint8 a = 255) :
			r(r), g(g), b(b), a(a) {}
	};
	
	class Object {
	public:
		Object(const Vector2f& position, const Vector2f& size) :
			position_(position), size_(size) {}
		virtual ~Object() = default;
		
		
		[[nodiscard]] const Vector2f& GetPosition() const;
		[[nodiscard]] const Vector2f& GetSize() const;
		
		void SetPosition(const Vector2f& position);
		
		virtual void Draw(SDL_Renderer* renderer) = 0;
		[[nodiscard]] virtual std::string GetString() const = 0;
		
		virtual void StringToObject(std::stringstream& ss) = 0;
	protected:
        Vector2f position_;
        Vector2f size_;
	};
	
	namespace shapes {
		
		class Point : public Object {
		public:
			explicit Point(const Vector2f& position) :
			Object(position, {1, 1}) {}
			~Point() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Line : public Object {
		public:
			Line(const Vector2f& start, const Vector2f& finish) : Object(start, {finish.x - start.x, 1}), finish(finish) {}
			~Line() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
            Vector2f finish;
		};
		
		class Rect : public Object {
		public:
			Rect(const Vector2f& position, const Vector2f& size) : Object(position, size) {
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
			Circle(const Vector2f& position, const Vector2f& size) : Object(position, size) {}
			~Circle() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Circumference : public Object {
		public:
			Circumference(const Vector2f& position, const Vector2f& size) : Object(position, size) {}
			~Circumference() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		};
		
		class Triangle : public Object {
		public:
			Triangle(const Vector2f& first_point, const Vector2f& second_point, const Vector2f& third_point) :
			Object(first_point, {0, 0}), second_point_(second_point), third_point_(third_point) {}
			~Triangle() override = default;
			
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
            Vector2f second_point_;
            Vector2f third_point_;
		};
		
		class Polygon : public Object {
		public:
			explicit Polygon(std::vector<Vector2f>  points) : Object({0, 0}, {0, 0}), points_(std::move(points)) {}
			~Polygon() override = default;
		
			void Draw(SDL_Renderer* renderer) override;
			[[nodiscard]] std::string GetString() const override;
			void StringToObject(std::stringstream& ss) override;
		private:
			std::vector<Vector2f> points_;
		};

	}
}

#endif
