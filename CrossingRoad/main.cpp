#include <SFML/Graphics.hpp>
#include "Base.h"

using namespace sf;
using namespace std;

int main()
{
	Base test = Base();
	test.randomGame(10000);
	test.printAll();

	return 0;
}
