#include "Punkty.h"


Punkty::Punkty()
{
	this->Points = 0;
	this->Mnoznik = 1.0;
	this->font.loadFromFile("fonts/Orbitron-VariableFont_wght.ttf");
	this->text.setFont(font);
	this->text.setPosition(987.0f, 295.0f);
	this->text.setCharacterSize(40);
}

void Punkty::update()
{
	Points += 10 * this->Mnoznik;
}

void Punkty::wyswietl(sf::RenderWindow& Window)
{
	text.setString(std::to_string(this->Points));
	Window.draw(text);
}

void Punkty::reset()
{
	this->Points = 0;
	this->Mnoznik = 1;
}

void Punkty::RundUp()
{
	this->Mnoznik += 0.5;
}
