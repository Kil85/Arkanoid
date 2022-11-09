#include "Ball.h"

Ball::Ball(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setRadius(10.f);
	shape.setFillColor(Color::White);
	shape.setOrigin(10.f, 10.f);
}

void Ball::update(bool& L)
{
	shape.move(velocity);

	if (left() < stala.StartOkna)
		velocity.x = -velocity.x;
	else if (right() > stala.KoniecOkna)
		velocity.x = -velocity.x;

	if (top() < stala.WysokoscOkna)
		velocity.y = stala.ballVelocity;
	else if (bottom() > stala.windowHeight)
		L = 1;
}

void Ball::reset()
{
	shape.setPosition(stala.windowWidth / 2, stala.windowHeight / 2);
	velocity = { -7.5f, -7.5f };
}
