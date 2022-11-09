#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Stale.h"

class Ball 
{
public:
	Stale stala;
	CircleShape shape;
	Vector2f velocity{ -7.5f, -7.5f };

	Ball(float mX, float mY);
	void update(bool& L);

	float x() const noexcept { return shape.getPosition().x; }
	float y() const noexcept { return shape.getPosition().y; }
	float left() const noexcept { return x() - shape.getRadius(); }
	float right() const noexcept { return x() + shape.getRadius(); }
	float top() const noexcept { return y() - shape.getRadius(); }
	float bottom() const noexcept { return y() + shape.getRadius(); }
	void reset();

};



