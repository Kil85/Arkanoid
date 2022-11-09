export module Wygrana;

import <SFML/Graphics.hpp>;
import <iostream>;
import "Nacisniety.h";

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
Nacisniety nac;

void Konstruktor() {
	WinTexture.loadFromFile("imiges/Win_Tlo.png");
	LoseTexture.loadFromFile("imiges/Lose_Tlo.png");
	TryAgainButtonTexture.loadFromFile("imiges/Try_Again.png");
	TryAgainButtonNajechaneTexture.loadFromFile("imiges/Try_Again_Najechane.png");
	ExitButtonTexture.loadFromFile("imiges/Win_Exit.png");
	ExitButtonTexture.loadFromFile("imiges/Win_Exit_Najechane.png");
	ExitButton.setTexture(ExitButtonTexture);
	WinTlo.setTexture(WinTexture);
	LoseTlo.setTexture(LoseTexture);
	TryAgainButton.setTexture(TryAgainButtonTexture);
	TryAgainButton.setPosition(300.0f, 600.0f);
	ExitButton.setPosition(300.0f, 780.0f);
}


void Najechane(sf::RenderWindow& Window, int x, int y, bool nacisk, Nacisniety& n) {
	if ((x > 300.0f && x < 800.0f) && (y > 600.0f && y < 750.0f)) {
		if (TryAgainButton.getTexture() == &TryAgainButtonTexture) {
			TryAgainButton.setTexture(TryAgainButtonNajechaneTexture);
		}
		if (nacisk)n.start = 1;
	}
	if ((x > 300.0f && x < 800.0f) && (y > 780.0f && y < 930.0f)) {
		if (ExitButton.getTexture() == &ExitButtonTexture) {
			ExitButton.setTexture(ExitButtonNajechaneTexture);
		}
		if (nacisk)n.exit = 1;
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


export int Wyswietl(sf::RenderWindow& Window, bool WinOrLose) {
	Konstruktor();
	if (WinOrLose)Window.draw(WinTlo);
	else Window.draw(LoseTlo);
	auto kursor = sf::Mouse::getPosition(Window);
	bool nacisk = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
	std::cout << "x: " << kursor.x << " y: " << kursor.y << std::endl;

	Najechane(Window, kursor.x, kursor.y,
		nacisk, nac);
		Window.draw(TryAgainButton);
	Window.draw(ExitButton);
	Window.display();
	return nac.KtoryWcisniety();
	
}

