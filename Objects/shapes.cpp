//
// shapes.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "shapes.h"
#include "settings.h"
#include "object_parser.h"
#include <cmath>
using namespace engine;
using namespace shapes;


Vector2f engine::ParseVector2f(const std::string& x, const std::string& y) {
    Vector2f vec {0, 0};
    if (x == "X_SIZE") vec.x = WIDTH;
    else vec.x = std::stof(x);
    if (y == "Y_SIZE") vec.y = HEIGHT;
    else vec.y = std::stof(y);
    return vec;
}

const Vector2f& Object::GetPosition() const {
	return position_;
}

const Vector2f& Object::GetSize() const {
	return size_;
}

void Object::SetPosition(const Vector2f& position) {
	position_ = position;
}

void Object::AddComponent(std::unique_ptr<IComponent> &&component) {
    components_.push_back(std::move(component));
}

void Object::Update() {
    for (const auto& component : components_) {
        component->Update();
    }
}

void Point::Draw(SDL_Renderer* renderer) {
	SDL_RenderDrawPointF(renderer, position_.x, position_.y);
}

std::string Point::GetString() const {
	return "type=point\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + '\n';
}

void Point::StringToObject(std::stringstream& ss) {
	std::string str;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		position_ = ParseVector2f(elements[1], elements[2]);
	}
}

void Line::Draw(SDL_Renderer* renderer) {
	SDL_RenderDrawLineF(renderer, position_.x, position_.y, finish.x, finish.y);
}

std::string Line::GetString() const {
	return  "type=line\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + '\n'
			+ "position=" + std::to_string(finish.x) + "," + std::to_string(finish.y) + '\n';	
}

void Line::StringToObject(std::stringstream& ss) {
	std::string str;
	bool itFirstPoint = true;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		if (itFirstPoint) position_ = ParseVector2f(elements[1], elements[2]);
		else finish = ParseVector2f(elements[1], elements[2]);
        itFirstPoint = false;
	}
}

void Rect::Draw(SDL_Renderer* renderer) {
	rect_ = {position_.x, position_.y, position_.x + size_.x, position_.y + size_.y};
	Fill(renderer);
	SDL_RenderDrawRectF(renderer, &rect_);
}

void Rect::Fill(SDL_Renderer* renderer) {
	SDL_RenderFillRectF(renderer, &rect_);
}

std::string Rect::GetString() const {
	return  "type=rect\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + '\n' +
			"size=" + std::to_string(size_.x) + "," + std::to_string(size_.y) + '\n';
}

void Rect::StringToObject(std::stringstream& ss) {
	std::string str;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		if (elements[0] == "position") position_ = ParseVector2f(elements[1], elements[2]);
		else size_ = ParseVector2f(elements[1], elements[2]);
	}
}

void Circle::Draw(SDL_Renderer* renderer) {
	for (float y = position_.y - size_.x; y < position_.y + size_.x; ++y) {
		for (float x = position_.x - size_.x; x < position_.x + size_.x; ++x) {
			if ((position_.x - x)*(position_.x - x) + (position_.y - y)*(position_.y - y) <= 
				size_.x) {
				SDL_RenderDrawPointF(renderer, x, y); 
			}
		}
	}
}

std::string Circle::GetString() const {
	return  "type=circle\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + "\n" +
			"size=" + std::to_string(size_.x) + "," + std::to_string(size_.y) + "\n";
}

void Circle::StringToObject(std::stringstream& ss) {
	std::string str;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		if (elements[0] == "position") position_ = ParseVector2f(elements[1], elements[2]);
		else size_ = ParseVector2f(elements[1], elements[2]);
	}
}

void Circumference::Draw(SDL_Renderer* renderer) {
	float CircumferenceSize = size_.x / 5;
	
	for (float y = position_.y - size_.x; y < position_.y + size_.x; ++y) {
		for (float x = position_.x - size_.x; x < position_.x + size_.x; ++x) {
			float length =(position_.x - x)*(position_.x - x) + (position_.y - y)*(position_.y - y);  
			if (length >= size_.x - CircumferenceSize &&
				length <= size_.x) {
					SDL_RenderDrawPointF(renderer, x, y); 
				}
		}
	}
}

std::string Circumference::GetString() const {
	return  "type=circumference\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + "\n" +
			"size=" + std::to_string(size_.x) + "," + std::to_string(size_.y) + "\n";
}

void Circumference::StringToObject(std::stringstream& ss) {
	std::string str;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		if (elements[0] == "position") ParseVector2f(elements[1], elements[2]);
		else size_ = ParseVector2f(elements[1], elements[2]);
	}
}


namespace {
	// ?????????????????? ?????????????????? ?????????? D(xd,yd) ???????????????????????? ???????????? AB
	double FindDPoint(const Vector2f& a, const Vector2f& b, const Vector2f& d) {
		return (d.x - a.x) * (b.y - a.y) - (d.y - a.y) * (b.x - a.x);
	}

	// ?????????? ???? ?????????? C ?? D ?? ?????????? ?????????????? ???????????? (AB)?
	bool CAndDOnOneSide(const Vector2f& a, const Vector2f& b, const Vector2f& c, const Vector2f& d) {
		return FindDPoint(a, b, c) * FindDPoint(a, b, d) >= 0;
	}
}

void Triangle::Draw(SDL_Renderer* renderer) {
	float start_x = std::fminf(position_.x, std::fminf(second_point_.x, third_point_.x));
	float start_y = std::fminf(position_.y, std::fminf(second_point_.y, third_point_.y));
	float finish_x = std::fmaxf(position_.x, std::fmaxf(second_point_.x, third_point_.x));
	float finish_y = std::fmaxf(position_.y, std::fmaxf(second_point_.y, third_point_.y));
	
	for (float y0 = start_y; y0 <= finish_y; ++y0) {
		for (float x0 = start_x; x0 <= finish_x; ++x0) {
            Vector2f a = position_;
            Vector2f b = second_point_;
            Vector2f c = third_point_;
            Vector2f d = Vector2f(x0, y0);
			if (CAndDOnOneSide(a, b, c, d) && CAndDOnOneSide(b, c, a, d) && CAndDOnOneSide(c, a, b, d)) {
				SDL_RenderDrawPointF(renderer, x0, y0);
			}
		}
	}
}

std::string Triangle::GetString() const {
	return  "type=trinagle\nposition=" + std::to_string(position_.x) + "," + std::to_string(position_.y) + '\n'
			+ "position=" + std::to_string(second_point_.x) + "," + std::to_string(second_point_.y) + '\n' 
			+ "position=" + std::to_string(third_point_.x) + "," + std::to_string(third_point_.y) + '\n';	
}

void Triangle::StringToObject(std::stringstream& ss) {
	std::string str;
	int point = 0;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		if (point == 0) position_ = ParseVector2f(elements[1], elements[2]);
		else if (point == 1) second_point_ = ParseVector2f(elements[1], elements[2]);
		else third_point_ = ParseVector2f(elements[1], elements[2]);
		++point;
	}
}

namespace {
	double CalculateAngle(const Vector2f& point1, const Vector2f& point2) {
		double dtheta, theta1, theta2;
		
		theta1 = atan2(point1.y, point1.x);
		theta2 = atan2(point2.y, point2.x);
		dtheta = theta2 - theta1;
		while (dtheta > M_PI) dtheta -= 2 * M_PI;
		while (dtheta < -M_PI) dtheta += 2 * M_PI;
		return dtheta;
	}
	
	bool InsidePolygon(const std::vector<Vector2f>& points, const Vector2f& point) {
		double angle = 0;
		for (int i = 0; i < points.size(); ++i) {
            Vector2f p1(points[i].x - point.x, points[i].y - point.y);
            Vector2f p2(points[(i + 1) % points.size()].x - point.x, points[(i + 1) % points.size()].y - point.y);
			angle += CalculateAngle(p1, p2);
		}
		if (abs(angle) < M_PI) return false;
		return true;
	}
	
}

void Polygon::Draw(SDL_Renderer* renderer) {
	float x1 = MAXFLOAT, x2 = -1;
	float y1 = MAXFLOAT, y2 = -1;
	
	for (const Vector2f& point : points_) {
		x1 = std::fminf(point.x, x1);
		x2 = std::fmaxf(point.x, x2);
		y1 = std::fminf(point.y, y1);
		y2 = std::fmaxf(point.y, y2);
	}
	
	for (float y = y1; y <= y2; ++y) {
		for (float x = x1; x <= x2; ++x) {
			if (InsidePolygon(points_, {x, y})) {
				SDL_RenderDrawPointF(renderer, x, y);
			}
		}
	}
}

std::string Polygon::GetString() const {
	std::string ans="type=polygon";
	for (auto point : points_) {
		ans += "\nposition=" + std::to_string(point.x) + "," + std::to_string(point.y);
	}
	return ans;
}

void Polygon::StringToObject(std::stringstream& ss) {
	std::string str;
	while (ss >> str) {
		std::vector<std::string> elements = Parser::Split(str);
		points_.emplace_back(ParseVector2f(elements[1], elements[2]));
	}
}

