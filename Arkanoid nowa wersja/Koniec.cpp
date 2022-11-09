#include "Koniec.h"

Koniec::Koniec()
{
	WinTexture.loadFromFile("imiges/Win_Tlo.png");
	LoseTexture.loadFromFile("imiges/Lose_Tlo.png");
	TryAgainButtonTexture.loadFromFile("imiges/Try_Again.png");
	TryAgainButtonNajechaneTexture.loadFromFile("imiges/Try_Again_Najechane.png");
	ExitButtonTexture.loadFromFile("imiges/Win_Exit.png");
	ExitButtonNajechaneTexture.loadFromFile("imiges/Win_Exit_Najechane.png");
	ExitButton.setTexture(ExitButtonTexture);
	WinTlo.setTexture(WinTexture);
	LoseTlo.setTexture(LoseTexture);
	TryAgainButton.setTexture(TryAgainButtonTexture);
	TryAgainButton.setPosition(300.0f, 600.0f);
	ExitButton.setPosition(300.0f, 780.0f);
	this->font.loadFromFile("fonts/Orbitron-VariableFont_wght.ttf");
	this->wynik.setFont(font);
	this->wynik.setCharacterSize(60);
	this->wynik.setPosition(505.f, 390.f);
}

void Koniec::Najechane(sf::RenderWindow& Window, int x, int y, bool nacisk)
{
	if ((x > 300.0f && x < 800.0f) && (y > 600.0f && y < 750.0f)) {
		if (TryAgainButton.getTexture() == &TryAgainButtonTexture) {
			TryAgainButton.setTexture(TryAgainButtonNajechaneTexture);
		}
		if (nacisk)nac.start = 1;
	}
	else if ((x > 300.0f && x < 800.0f) && (y > 780.0f && y < 930.0f)) {
		if (ExitButton.getTexture() == &ExitButtonTexture) {
			ExitButton.setTexture(ExitButtonNajechaneTexture);
		}
		if (nacisk)nac.exit = 1;
	}
	else
	{
		if (TryAgainButton.getTexture() == &TryAgainButtonNajechaneTexture) {
			TryAgainButton.setTexture(TryAgainButtonTexture);
		}
		if (ExitButton.getTexture() == &ExitButtonNajechaneTexture) {
			ExitButton.setTexture(ExitButtonTexture);
		}
	}
}

int Koniec::Wyswietl(sf::RenderWindow& Window, bool WinOrLose, int wynik)
{
	if (WinOrLose)Window.draw(WinTlo);
	else Window.draw(LoseTlo);
	auto kursor = sf::Mouse::getPosition(Window);
	bool nacisk = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

	Najechane(Window, kursor.x, kursor.y,
		nacisk);
	this->wynik.setString(std::to_string(wynik));
	Window.draw(this->wynik);
	Window.draw(TryAgainButton);
	Window.draw(ExitButton);
	Window.display();
	return nac.KtoryWcisniety();
}
