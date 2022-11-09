#include "Brick.h"

Brick::Brick(float bX, float bY, int a) {
	this->Zniszczony = 0;
	shape.setPosition(bX, bY);
	shape.setSize({ Stale::blockWidth, Stale::blockHeight });
	SetKolor(a);
	shape.setOrigin(Stale::blockWidth / 2.f, Stale::blockHeight / 2.f);
}

void Brick::SetKolor(int a)
{
	auto liczba = a;
	switch (liczba)
	{
	case 0:
		shape.setFillColor(Color::White);
		break;
	case 1:
		shape.setFillColor(Color::Blue);
		break;
	case 2:
		shape.setFillColor(Color::Green);
		break;
	case 3:
		shape.setFillColor(Color::Yellow);
		break;
	case 4:
		shape.setFillColor(Color::Magenta);
		break;
	}

}

Brick& Brick::operator=(const Brick& a)
{
	this->shape.setPosition(a.shape.getPosition());
	this->Zniszczony = a.Zniszczony;
	return *this;
}
