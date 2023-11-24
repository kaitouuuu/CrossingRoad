#include "Base.h"

Base::Base()
	: rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}

int Base::randomNumber(int l, int r) {
	return std::uniform_int_distribution<int>(l, r)(rng);
}

void Base::randomGame(int difficulty) {
}

Base::Base(std::mt19937_64 seed)
	: rng(seed) {}