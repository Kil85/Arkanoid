#include "Game.h"

void Game::Gra()
{
	if (IleKlockow == 0)Win = 1;
	pilka->update(Lose);
	platforma->update();
	Kolizja(*platforma, *pilka);
	for (auto i = std::ranges::begin(klocki); i < std::ranges::end(klocki); i++)
	{
		Kolizja(*i, *pilka);
	}
	this->Window->draw(this->Tlo);
	this->WyswietlStoper();
	this->Window->draw(this->pilka->shape);
	this->Window->draw(this->platforma->shape);
	this->punkty->wyswietl(*this->Window);
	for (auto& brick : klocki) {

		if (!brick.Zniszczony)
			this->Window->draw(brick.shape);
	}
	if (Win)
	{
		this->Window->clear();
		odpowiedz = 1;
		if (odpowiedz == 1) {
			this->Poziom++;
			this->Reset();
			this->punkty->RundUp();
		}
		this->WyborPrzycisku(odpowiedz);
		
	}
	if (Lose)
	{
		if (!this->Scboard->Dodany)this->Scboard->DodanieDoListy(this->Nazwa, this->punkty->getPoints(), Stan());
		this->Window->clear();
		odpowiedz = this->koniec->Wyswietl(*this->Window, 0, this->punkty->getPoints());
		if (odpowiedz == 1) {
			this->Poziom = 1;
			this->Reset();
			this->punkty->reset();
			StoperReset();
			this->PotrzebnaNazwa = 1;
		}
		this->WyborPrzycisku(odpowiedz);
	}
}


Game::Game()
{
	this->Poziom = 1;
	this->Window = new sf::RenderWindow{ {stala.windowWidth, stala.windowHeight}, "Arkanoid", sf::Style::Close | sf::Style::Titlebar };
	this->Window->setFramerateLimit(60);
	this->pilka = new Ball(stala.windowWidth / 2, stala.windowHeight / 2);
	this->platforma = new Platforma(stala.windowWidth / 2, stala.windowHeight - 50);
	this->menu = new Menu;
	this->PoziomTextura.loadFromFile("imiges/Poziom.png");
	this->Level.setTexture(PoziomTextura);
	this->IleKlockow = stala.countBlocksX * stala.countBlocksY * this->Poziom;
	this->TloTextura.loadFromFile("imiges/Tlo_gra.jpg");
	this->Tlo.setTexture(TloTextura);
	this->StoperFont.loadFromFile("fonts/KdamThmorPro-Regular.ttf");
	this->Stoper.setFont(StoperFont);
	this->Stoper.setFillColor(sf::Color::White);
	this->Stoper.setPosition(1000.0f, 1.0f);
	this->Stoper.setCharacterSize(30);
	this->NrPoziomu.setFont(this->StoperFont);
	this->NrPoziomu.setCharacterSize(120);
	this->NrPoziomu.setPosition(525.0f, 575.0f);
	this->DoPodaniaNazwy.loadFromFile("imiges/Ramka.png");
	this->DoNazwy.setTexture(this->DoPodaniaNazwy);
	this->WpisanaNazwa.setFont(StoperFont);
	this->WpisanaNazwa.setCharacterSize(55);
	this->WpisanaNazwa.setPosition(215.f, 600.f);
	this->STexture.loadFromFile("imiges/Strzalka.png");
	this->Strzalka.setTexture(STexture);
	this->Scboard = new Scoreboard;
	this->koniec = new Koniec;
	this->punkty = new Punkty;
	this->Lose = 0;
	this->Win = 0;
	this->PotrzebnaNazwa = 1;
	this->DobraNazwa = 0;
	this->NowyPoziom = 1;
	this->Inicjacja = 0;
}

Game::~Game()
{
	delete this->Window;
	delete this->pilka;
	delete this->platforma;
	delete this->menu;
	delete this->Scboard;
	delete this->koniec;
	delete this->punkty;
}

void Game::Run()
{
	LadowanieKlockow();

	while (this->Window->isOpen())
	{
		this->Window->clear(Color::Black);

		while (this->Window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				this->Window->close();
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;

		this->WyswietlTlo();
		auto kursor = sf::Mouse::getPosition(*this->Window);
		bool nacisk = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		this->menu->Najechane(kursor.x, kursor.y, nacisk, n);

		this->WyborPrzycisku(n.KtoryWcisniety());
	}

}
template<class T1, class T2>
inline bool Game::Interakcja(T1& mA, T2& mB) noexcept
{
	return mA.right() >= mB.left() && mA.left() <= mB.right() &&
		mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void Game::Kolizja(Platforma& mPlatforma, Ball& mBall) noexcept {
	if (!Interakcja(mPlatforma, mBall)) return;

	mBall.velocity.y = -stala.ballVelocity;


	if (mBall.x() < mPlatforma.x()) {
		mBall.velocity.x = -stala.ballVelocity + (mPlatforma.x() - mBall.x()) / 20;
		mBall.velocity.y -= (mPlatforma.x() - mBall.x()) / 50;
	}
	else {
		mBall.velocity.x = stala.ballVelocity - (mBall.x() - mPlatforma.x()) / 20;
		mBall.velocity.y -= (mBall.x() - mPlatforma.x()) / 50;
	}
}

void Game::Kolizja(Brick& mBrick, Ball& mBall) noexcept
{
	if (mBrick.Zniszczony)return;
	if (!Interakcja(mBrick, mBall)) return;
	mBrick.Zniszczony = true;
	this->IleKlockow--;
	this->punkty->update();

	float overlapLeft{ mBall.right() - mBrick.left() };
	float overlapRight{ mBrick.right() - mBall.left() };
	float overlapTop{ mBall.bottom() - mBrick.top() };
	float overlapBottom{ mBrick.bottom() - mBall.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.velocity.x = ballFromLeft ? -stala.ballVelocity :stala.ballVelocity;
	else
		mBall.velocity.y = ballFromTop ? -stala.ballVelocity : stala.ballVelocity;
}

void Game::WyswietlTlo()
{
	this->Window->draw(this->menu->Tlo);
	this->Window->draw(this->menu->Start);
	this->Window->draw(this->menu->Scoreboard);
	this->Window->draw(this->menu->Exit);
}

void Game::LadowanieKlockow()
{
	for (int i = 0; i < stala.countBlocksX; ++i)
	{
		for (int j = 0; j < (stala.countBlocksY * this->Poziom); ++j) {
			klocki.emplace_back(
				(i + 1) * (stala.blockWidth + 3) + 60, (j + 2) * (stala.blockHeight + 3) + 55, j % 4);
		}
	}
}

void Game::WyswietlStoper()
{
	int czas = Stan();
	int minuty = czas / 60;
	int sekundy = czas % 60;
	if (minuty < 10) {
		if (sekundy < 10) {
			Stoper.setString("0" + std::to_string(minuty) + ":0" + std::to_string(sekundy));
		}
		else
		{
			Stoper.setString("0" + std::to_string(minuty) + ":" + std::to_string(sekundy));
		}
	}
	else
	{
		if (sekundy < 10) {
			Stoper.setString(std::to_string(minuty) + ":0" + std::to_string(sekundy));
		}
		else
		{
			Stoper.setString(std::to_string(minuty) + ":" + std::to_string(sekundy));
		}
	}
	this->Window->draw(Stoper);
}

void Game::TabelaWynikow()
{
	this->Window->clear(sf::Color::Black);
	this->Window->draw(this->Scboard->Tlo);
	this->Window->draw(this->Strzalka);
	this->Scboard->WyswietlListe(*this->Window);
	auto pos = sf::Mouse::getPosition(*this->Window);
	if ((pos.x > 0 && pos.x < 150) && (pos.y > 0 && pos.y < 100) && sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
		this->Window->clear();
		this->n.scoreboard = 0;
		this->WyswietlTlo();
		this->Window->display();
		auto kursor = sf::Mouse::getPosition(*this->Window);
		bool nacisk = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
		this->menu->Najechane(kursor.x, kursor.y, nacisk, n);

		this->WyborPrzycisku(n.KtoryWcisniety());
	}
}

void Game::WyborPrzycisku(int a)
{
	switch (a) {
	case 1:
		this->Window->clear();
		if (this->PotrzebnaNazwa) {
			this->PodajNazwe();
		}
		if (!DobraNazwa) {
			break;
		}
		this->PotrzebnaNazwa = 0;
		if (this->NowyPoziom) {
			this->NowyPoziom = 0;
			this->LevelUp();
		}
		Poczatek();
		this->Gra();
		break;
	case 2:
		this->TabelaWynikow();
		break;

	case 3:
		this->Window->close();
		break;

	}
	this->Window->display();

}

void Game::Reset()
{
	Win = 0;
	Lose = 0;
	this->pilka->reset();
	odpowiedz = 0;
	delete this->koniec;
	this->koniec = new Koniec;
	this->platforma->Reset();
	this->LadowanieKlockow();
	this->IleKlockow = stala.countBlocksX * stala.countBlocksY * this->Poziom;
	this->NowyPoziom = 1;
	this->Scboard->Dodany = 0;


}

void Game::LevelUp()
{
	this->NrPoziomu.setString(std::to_string(this->Poziom));
	this->Window->draw(Level);
	this->Window->draw(this->NrPoziomu);
	this->Window->display();
	sf::sleep(sf::seconds(2));
	this->Window->clear();
}

void Game::PodajNazwe() {

	this->Window->draw(DoNazwy);

	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 127 && event.text.unicode>31)
		{
			if (Nazwa.size() < 11) {
				Nazwa += static_cast<char>(event.text.unicode);
				WpisanaNazwa.setString(Nazwa);
				sf::sleep(sf::milliseconds(150));
			}

		}
		if (event.text.unicode == 13) {
			if (std::regex_match(Nazwa, std::regex("[a-zA-Z0-9]{3,10}"))) {
				DobraNazwa = 1;
			}
		}
		if (event.text.unicode == 8) {
			if (!Nazwa.empty()) {
				Nazwa.erase(Nazwa.end() - 1);
				WpisanaNazwa.setString(Nazwa);
				sf::sleep(sf::milliseconds(200));
			}
		}
	}

	this->Window->draw(this->WpisanaNazwa);
}