#pragma once
#include <SFML/Graphics.hpp>

class Rectangle
{
public:
	sf::RectangleShape shape;
	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float left() const noexcept { return x() - shape.getSize().x / 2.f; }
	float right() const noexcept { return x() + shape.getSize().x / 2.f; }
	float top() const noexcept { return y() - shape.getSize().y / 2.f; }
	float bottom() const noexcept { return y() + shape.getSize().y / 2.f; }
};
