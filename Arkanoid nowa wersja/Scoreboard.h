#pragma once

#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
#include <ranges>

namespace fs = std::filesystem;

struct record
{
public:
	std::string nazwa;
	int wynik;
	clock_t czas;
};


class Scoreboard
{
public:
	fs::path ScoreboardPath;
	std::vector<record> lista;
	sf::Font font;
	sf::Text text;
	sf::Texture texture;
	sf::Sprite Tlo;
	bool Dodany;
	

	Scoreboard();
	void OdczytListy();
	void ZapisListy();
	void WyswietlListe(sf::RenderWindow& Window);
	bool Test(int wynik, clock_t czas);
	void DodanieDoListy(std::string nazwa, int wynik, clock_t czas);
	std::vector<record>::iterator ZnajdzMiejsce(int wynik, clock_t czas);
};

