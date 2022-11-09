#include "Nacisniety.h"

Nacisniety::Nacisniety() {
	this->start = 0;
	this->scoreboard = 0;
	this->exit = 0;
}

int Nacisniety::KtoryWcisniety()
{
	if (this->start == 1)return 1;
	if (this->scoreboard == 1)return 2;
	if (this->exit == 1)return 3;
	return 0;
}
