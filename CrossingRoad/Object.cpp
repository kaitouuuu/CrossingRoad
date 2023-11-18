
#include "Object.h"
FloatRect StableObject::getglobalBounds() {
	return sprite.getGlobalBounds();
}

bool StableObject::doesIntersect( StableObject *other)  {
	return this->sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds());
}
void StableObject::draw(RenderWindow& window) {
	window.draw(sprite);
}

//void Tree::draw(RenderWindow& window) {
//	window.draw(sprite);
//}
//
//FloatRect Tree::getglobalBounds() {
//		return sprite.getGlobalBounds();
//}
//
//bool Tree::doesIntersect(  Stableobject& other) {
//	
//	return this->sprite.getGlobalBounds().intersects(other.getglobalBounds());
//}
//
//
// void Bigtree::draw(RenderWindow& window) {
//	 window.draw(sprite);
// }
// FloatRect Bigtree::getglobalBounds() {
//	 return sprite.getGlobalBounds();
// }
// bool Bigtree::doesIntersect(Stableobject& other) {
//
//	 return this->sprite.getGlobalBounds().intersects(other.getglobalBounds());
// }

void Lawn::draw(RenderWindow& window){
	window.draw(sprite);
}

void Lawn::drawobject(RenderWindow& window) {
	for (const auto& object : stableobject) {
		object->draw(window);
	}
}

void Lawn::randomobejct(RenderWindow& window) {
	bool stop = false;
	while (!stop) {
		float randomX = static_cast<float>(rand() % static_cast<int>(width));
		float randomY = y + static_cast<float>(rand() % static_cast<int>(height));
		std::srand(static_cast<unsigned>(std::time(0)));
		int choice= 1 + std::rand() % 2;
		
		StableObject* arr = nullptr;
		if (choice == 1) {
			arr = new StableObject(randomX, randomY, Tree);
		}
		else if (choice == 2) {
			arr = new StableObject(randomX, randomY, Bigtree);
		}
	
		for (int i = 0; i < stableobject.size(); i++) {
			if (arr->doesIntersect(stableobject[i]) ){
				stableobject.push_back(arr);
				stop = true;
				break;
			}
		}
	}
	

}

