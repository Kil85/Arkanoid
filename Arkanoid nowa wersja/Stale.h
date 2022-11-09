#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;
using namespace sf;
class Stale
{
public:
	unsigned int windowWidth{ 1100 }, windowHeight{ 1100 };
	unsigned int PlayWidth{ 800 }, PlayHeight{ 800 };
	const float ballRadius{ 30.f }, ballVelocity{ 7.5f };
	const float paddleWidth{ 150.f }, paddleHeight{ 20.f }, paddleVelocity{ 12.f };
	const float blockWidth{ 60.0f }, blockHeight{ 20.f };
	const int countBlocksX{ 10 }, countBlocksY{ 1 };
	unsigned int StartOkna{ 73 }, KoniecOkna{ 745 }, WysokoscOkna{ 70 };

	int LiczbaLosowa(int start, int end);
};


