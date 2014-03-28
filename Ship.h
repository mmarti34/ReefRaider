#include "Entity.h"
#include "Display.h"
#include "Sprite.h"
#include <string>
using namespace std;

#ifndef SHIP_H
#define SHIP_H

enum shipType { CUTTER, WARSHIP, FRIGATE };

class Ship : public Entity {
public:
	Ship(shipType, string);
	void render(int x, int y, SDL_Surface* screen);
	void update(Display* display);
	void setDirection(int);
private:
	int direction;
	int maxHealth;
	int currentHealth;
	Sprite left_1, left_2;
	Sprite right_1, right_2;
	Sprite up_1, up_2;
	Sprite down_1, down_2;
};

#endif
