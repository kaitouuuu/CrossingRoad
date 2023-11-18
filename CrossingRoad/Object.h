#pragma once
#include <vector>
#include "character.h"
enum typeobj {
	Tree, Bigtree
};

class StableObject {
private:
	float PositionX;
	float PositionY;
	Texture texture;
	Sprite sprite;
public:
	StableObject(float positionX, float positionY,const typeobj& type) : PositionX(positionX), PositionY(positionY) {
		string filename= "Content/Image/basic_grass.png";
		float x, y, width, height;
		if (type == Tree) {
			 x = 0; y = 0; width = 16; height = 32;
		}
		else if (type == Bigtree) {
			x = 16; y = 0; width = 32; height = 32;
		}
		if (!texture.loadFromFile(filename))
		{
			cout << "Failed to load grass spritesheet!" << endl;
			exit(0);
		}
		IntRect rectangle(x, y, width, height);
		sprite.setTexture(texture);
		sprite.setTextureRect(rectangle);
		sprite.setPosition(Vector2f(positionX, positionY));
	}

	FloatRect getglobalBounds();
	bool doesIntersect( StableObject *other)  ;
	void draw(RenderWindow& window) ;
};
//class Stableobject {
//public:
//	virtual FloatRect getglobalBounds() = 0;
//	virtual bool doesIntersect(  Stableobject& other) = 0;
//	virtual void draw(RenderWindow& window)=0;
//	
//};
//
//class Tree: public Stableobject {
//private:
//	Texture texture;
//	Sprite sprite;
//public:
//	Tree(float positionX, float positionY)  {
//		string filename = "Content/Image/basic_grass.png";
//		float x = 0, y = 0, width = 16, height=32;
//
//		if (!texture.loadFromFile(filename))
//		{
//			cout << "Failed to load grass spritesheet!" << endl;
//			exit(0);
//		}
//
//		IntRect rectangle(x, y, width, height);
//		sprite.setTexture(texture);
//		sprite.setTextureRect(rectangle);
//		sprite.setPosition(Vector2f(positionX, positionY));
//	}
//	FloatRect getglobalBounds() override;
//	bool doesIntersect( Stableobject& other) override;
//	void draw(RenderWindow& window) override;
//};
//class Bigtree : public Stableobject {
//private:
//	Texture texture;
//	Sprite sprite;
//public:
//	Bigtree(float positionX, float positionY){
//		string filename = "Content/Image/basic_grass.png";
//		if (!texture.loadFromFile(filename))
//		{
//			cout << "Failed to load grass spritesheet!" << endl;
//			exit(0);
//		}
//		float x = 16, y = 0, width = 32, height = 32;
//		IntRect rectangle(x, y, width, height);
//		sprite.setTexture(texture);
//		sprite.setTextureRect(rectangle);
//		sprite.setPosition(Vector2f(positionX, positionY));
//	}
//	FloatRect getglobalBounds() override;
//	bool doesIntersect(Stableobject& other) override;
//	void draw(RenderWindow& window) override;
//};


class Superlane {
protected:
	float y;
	float x;
	float width;
	float height;

public:
	Superlane(const float& x, const float& y, const float& width, const float& height) : x(x), y(y),width(width),height(height){}
	virtual void draw(RenderWindow& window)=0;
	virtual void drawobject(RenderWindow& window) = 0;
	virtual void randomobejct(RenderWindow& window) = 0;
};
class Lawn: public Superlane  {
private:
	std::vector<StableObject*> stableobject;
	Texture texture;
	Sprite sprite;
public:
	Lawn(const float& x, const float& y, const float& width, const float& height,string filename) : Superlane(x, y, width, height){
		if (!texture.loadFromFile(filename)) {
			cout << "Failed to load grass spritesheet!" << endl;
			exit(0);
		}
		IntRect rectangle(x, y, width, height);
		sprite.setTexture(texture);
		sprite.setTextureRect(rectangle);
	}
	void draw(RenderWindow& window) override;
	void drawobject(RenderWindow& window) override;
	void randomobejct(RenderWindow& window) override;
};
class Road: public Superlane {
private:
	// vehicle class 
};

class Background {
private:
	vector<Superlane*> background;
public:
	
};
