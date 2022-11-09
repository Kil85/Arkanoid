#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Nacisniety.h"

class Koniec
{
public:

	sf::Texture WinTexture;
	sf::Sprite WinTlo;
	sf::Texture LoseTexture;
	sf::Sprite LoseTlo;
	sf::Texture TryAgainButtonTexture;
	sf::Texture TryAgainButtonNajechaneTexture;
	sf::Sprite TryAgainButton;
	sf::Texture ExitButtonTexture;
	sf::Texture ExitButtonNajechaneTexture;
	sf::Sprite ExitButton;
	sf::Font font;
	sf::Text wynik;
	Nacisniety nac;

	Koniec();
	void Najechane(sf::RenderWindow& Window, int x, int y, bool nacisk);
	int Wyswietl(sf::RenderWindow& Window, bool WinOrLose, int wynik);
};

