#include "Base.h"

using namespace sf;

int main()
{
	Base test = Base();
	test.randomGame(2);
	test.printAll();

	return 0;
}
