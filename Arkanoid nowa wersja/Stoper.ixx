export module Stoper;

export import <time.h>;
export import <iostream>;
export import <vector>;
export import <ranges>;
export import <regex>;

clock_t Start;
bool Zaczete = 0;

export void Poczatek() {
	if (!Zaczete) {
		Start = clock();
		Zaczete = 1;
	}

}

export int Stan() {
	clock_t Koniec = clock();
	return (int)(Koniec - Start) / CLOCKS_PER_SEC;
}

export void StoperReset() {
	Start = clock();
}

