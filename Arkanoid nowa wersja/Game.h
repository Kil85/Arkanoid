#pragma once
#include "Stale.h"
#include "Ball.h"
#include "Platforma.h"
#include "Brick.h"
#include "Menu.h"
#include "Nacisniety.h"
#include "Scoreboard.h"
#include "Koniec.h"
#include "Punkty.h"
import Stoper;



class Game
{
	void Gra();
public:
	sf::RenderWindow* Window;
	Ball *pilka;
	Platforma *platforma;
	Menu* menu;
	Nacisniety n;
	vector<Brick> klocki;
	sf::Texture TloTextura;
	sf::Texture PoziomTextura;
	sf::Texture DoPodaniaNazwy;
	sf::Sprite DoNazwy;
	sf::Sprite Level;
	sf::Sprite Tlo;
	sf::Text NrPoziomu;
	sf::Text WpisanaNazwa;
	sf::Font StoperFont;
	sf::Text Stoper;
	sf::Texture STexture;
	sf::Sprite Strzalka;
	int IleKlockow;
	int odpowiedz;
	Stale stala;
	Scoreboard* Scboard;
	Koniec* koniec;
	Punkty* punkty;
	bool Lose;
	bool Win;
	int Poziom;
	bool NowyPoziom;
	bool PotrzebnaNazwa;
	bool DobraNazwa;
	bool Inicjacja;
	std::string Nazwa;
	Event event;


	Game();
	~Game();
	void Run();

	template <class T1, class T2>
	bool Interakcja(T1& mA, T2& mB) noexcept;
	void Kolizja(Platforma& mPlatforma, Ball& mBall) noexcept;
	void Kolizja(Brick& mbrick, Ball& mBall) noexcept;
	void WyswietlTlo();
	void LadowanieKlockow();
	void WyswietlStoper();
	void TabelaWynikow();
	void WyborPrzycisku(int a);
	void Reset();
	void LevelUp();
	void PodajNazwe();
};



