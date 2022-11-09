#pragma once
#include<SFML/graphics.hpp> 
#include "Nacisniety.h"


class Menu
{
public:
	sf::Texture Ttexture;
	sf::Texture Stexture;
	sf::Texture SNajechanetexture;
	sf::Texture Sbtexture;
	sf::Texture SbNajechanetexture;
	sf::Texture Etexture;
	sf::Texture ENajechanetexture;
	sf::Sprite Tlo;
	sf::Sprite Start;
	sf::Sprite Exit;
	sf::Sprite Scoreboard;


	Menu();
	void Najechane(int x, int y, bool& nacisk, Nacisniety &n);
	


};

