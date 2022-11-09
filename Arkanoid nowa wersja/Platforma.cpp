#include "Platforma.h"

Platforma::Platforma(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setSize({ stala.paddleWidth, stala.paddleHeight });
	shape.setFillColor(Color::Red);
	shape.setOrigin(stala.paddleWidth / 2.f, stala.paddleHeight / 2.f);
}

void Platforma::update()
{
	shape.move(velocity);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > stala.StartOkna+4)
		velocity.x = -stala.paddleVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) &&
		right() < stala.KoniecOkna)
		velocity.x = stala.paddleVelocity;
	else
		velocity.x = 0;
}

void Platforma::Reset()
{
	shape.setPosition(stala.windowWidth / 2, stala.windowHeight - 50);
}


