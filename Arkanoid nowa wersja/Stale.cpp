#include "Stale.h"

int Stale::LiczbaLosowa(int start, int end)
{
	return (std::rand() % end - start + 1) + start;
}
