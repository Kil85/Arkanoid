#include "Menu.h"


Menu::Menu() {
	this->Ttexture.loadFromFile("imiges/Tlo.png");
	this->Stexture.loadFromFile("imiges/Start.png");
	this->SNajechanetexture.loadFromFile("imiges/Start_Najechane.png");
	this->Sbtexture.loadFromFile("imiges/Scoreboard.png");
	this->SbNajechanetexture.loadFromFile("imiges/Scoreboard_Najechane.png");
	this->Etexture.loadFromFile("imiges/Exit.png");
	this->ENajechanetexture.loadFromFile("imiges/Exit_Najechane.png");
	this->Tlo.setTexture(this->Ttexture);
	this->Start.setTexture(this->Stexture);
	this->Scoreboard.setTexture(this->Sbtexture);
	this->Exit.setTexture(this->Etexture);
	this->Start.setPosition(300.0f, 500.0f);
	this->Scoreboard.setPosition(300.0f, 680.0f);
	this->Exit.setPosition(300.0f, 860.0f);
}

void Menu::Najechane(int x, int y, bool& nacisk, Nacisniety& n)
{
	if ((x > 300.0f && x < 800.0f) && (y > 500.0f && y < 650.0f)) {
		if (this->Start.getTexture() == &this->Stexture) {
			this->Start.setTexture(this->SNajechanetexture);
		}
		if (nacisk)n.start = 1;
	}
	else if ((x > 300.0f && x < 800.0f) && (y > 680.0f && y < 830.0f)) {
		if (this->Scoreboard.getTexture() == &this->Sbtexture) {
			this->Scoreboard.setTexture(this->SbNajechanetexture);
		}
		if (nacisk)n.scoreboard = 1;
	}
	else if ((x > 300.0f && x < 800.0f) && (y > 860.0f && y < 1010.0f)) {
		if (this->Exit.getTexture() == &this->Etexture) {
			this->Exit.setTexture(this->ENajechanetexture);
		}
		if (nacisk)n.exit = 1;

	}

	else {
		if (this->Start.getTexture() == &this->SNajechanetexture) {
			this->Start.setTexture(this->Stexture);
		}
		else if (this->Scoreboard.getTexture() == &this->SbNajechanetexture) {
			this->Scoreboard.setTexture(this->Sbtexture);
		}
		else if (this->Exit.getTexture() == &this->ENajechanetexture) {
			this->Exit.setTexture(this->Etexture);
		}
	}
}




