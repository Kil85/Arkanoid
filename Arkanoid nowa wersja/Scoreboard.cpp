#include "Scoreboard.h"

Scoreboard::Scoreboard() {
	this->ScoreboardPath = "Scoreboard/tabela.txt";
	this->OdczytListy();
	this->font.loadFromFile("fonts/Orbitron-VariableFont_wght.ttf");
	this->text.setFont(font);
	this->texture.loadFromFile("imiges/Scoreboard_Tlo.png");
	this->Tlo.setTexture(this->texture);
	this->text.setCharacterSize(38);
	this->Dodany = 0;
}

void Scoreboard::OdczytListy()
{
	std::ifstream plik(this->ScoreboardPath);
	if (!plik.good())std::cout << "Error\n";
	while (!plik.eof())
	{
		record tmp;
		plik >> tmp.nazwa >> tmp.wynik >> tmp.czas;
		if (tmp.nazwa.size() == 0)break;
		this->lista.push_back(tmp);
	}
	plik.close();
}

void Scoreboard::ZapisListy()
{
	std::fstream plik(this->ScoreboardPath, std::ios::out | std::ios::trunc);
	for (auto& b : lista) {
		plik << b.nazwa << "     " << b.wynik << "     " << b.czas << "\n";
	}
	plik.close();
}

void Scoreboard::WyswietlListe(sf::RenderWindow& Window)
{
	int iterator = 1;
	for (auto& a : this->lista) {
		std::string minuty = std::to_string(a.czas / 60);
		std::string sekundy = std::to_string(a.czas % 60);
		if (minuty.size() < 2)minuty.insert(0, "0");
		if (sekundy.size() < 2)sekundy.insert(0, "0");
		std::string wysw = { std::to_string(iterator) + ". " + a.nazwa
			+ "     " + std::to_string(a.wynik) + "     " + minuty + ":" + sekundy };
		text.setString(wysw);
		this->text.setPosition(390.0f, 230.0f + 70 * (iterator - 1));
		iterator++;
		Window.draw(text);
	}
}

bool Scoreboard::Test(int wynik, clock_t czas)
{
	if (lista.empty())return 1;
	if (wynik > lista.back().wynik)return 1;
	else if (wynik == lista.back().wynik) {
		if (czas < lista.back().czas)return 1;
		else return 0;
	}
	else return 0;
}

void Scoreboard::DodanieDoListy(std::string nazwa, int wynik, clock_t czas)
{
	if (Test(wynik, czas)) {
		record tmp{ nazwa, wynik, czas };
		if (!lista.empty()) {
			auto miejsce = ZnajdzMiejsce(wynik, czas);
			lista.insert(miejsce, tmp);
			Dodany = 1;
		}
		else {
			lista.push_back(tmp);
			Dodany = 1;
		}
		if (lista.size() > 10) {
			lista.pop_back();
		}
		this->ZapisListy();
	}


}

std::vector<record>::iterator Scoreboard::ZnajdzMiejsce(int wynik, clock_t czas)
{
	for (auto i = std::ranges::begin(lista); i < std::ranges::end(lista); i++) {
		if (wynik > i->wynik)return i;
		if (wynik == i->wynik && czas < i->czas)return i;
	}
}


