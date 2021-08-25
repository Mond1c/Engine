//
// shapes.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _shapes_h_
#define _shapes_h_

#include "vector.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>


namespace SDL {	
	struct Color {
		Uint8 r, g, b, a;
		Color() : r(0), g(0), b(0), a(255) {}
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) :
			r(r), g(g), b(b), a(a) {}
	};
	
	class Object {
	public:
		Object(const Vector& position, const Vector& size) :
			position_(position), size(size) {}
		virtual ~Object() {
			
		}
		
		
		Vector GetPosition() const;
		Vector GetSize() const;
		
		void SetPosition(const Vector& position);
		
		virtual void Draw(SDL_Renderer* renderer) = 0;
		virtual std::string GetString() const = 0;
		
		virtual void stringToObject(std::stringstream& ss) = 0;
	protected:
		Vector position_;
		Vector size;
	};
	
	namespace Shapes {
		
		class Point : public Object {
		public:
			Point(const Vector& position) :
			Object(position, {1, 1}) {}
			~Point() {}
			
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		};
		
		class Line : public Object {
		public:
			Line(const Vector& start, const Vector& finish) : Object(start, {finish.x - start.x, 1}), finish(finish) {}
			~Line() {}
			
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		private:
			Vector finish;
		};
		
		class Rect : public Object {
		public:
			Rect(const Vector& position, const Vector& size) : Object(position, size) {
				rect_ = {position.x, position.y, position.x + size.x, position.y + size.y};
			}
			~Rect() {}
			
			void Draw(SDL_Renderer* renderer) override;
			void Fill(SDL_Renderer* renderer);
			
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		private:
			SDL_FRect rect_;
		};
		
		class Circle : public Object {
		public:
			Circle(const Vector& position, const Vector& size) : Object(position, size) {}
			~Circle() {}
			
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		};
		
		class Circumference : public Object {
		public:
			Circumference(const Vector& position, const Vector& size) : Object(position, size) {}
			~Circumference() {}
			
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		};
		
		class Trinagle : public Object {
		public:
			Trinagle(const Vector& first_point, const Vector& second_point, const Vector& third_point) : 
			Object(first_point, {0, 0}), second_point_(second_point), third_point_(third_point) {}
			~Trinagle() {}
			
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		private:
			Vector second_point_;
			Vector third_point_;
		};
		
		class Polygon : public Object {
		public:
			Polygon(const std::vector<Vector>& points) : Object({0, 0}, {0, 0}), points_(points) {}
			~Polygon() {}
		
			void Draw(SDL_Renderer* renderer) override;
			std::string GetString() const override;
			void stringToObject(std::stringstream& ss) override;
		private:
			std::vector<Vector> points_;
		};
	}
}

#endif