#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Punkty
{
	int Points;
	float Mnoznik;
	sf::Font font;
	sf::Text text;
public:
	Punkty();
	void update();
	void wyswietl(sf::RenderWindow& Window);
	void reset();
	void RundUp();
	int getPoints() { return Points; }
};

