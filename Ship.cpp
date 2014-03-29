#include "Ship.h"

Ship::Ship(shipType vessel, string pathName) 
	: Entity(pathName),
	left_1(sheet.getSurface(), 0, 0, 32, true, false),
	right_1(sheet.getSurface(), 1, 0, 32, true, false),
	up_1(sheet.getSurface(), 2, 0, 32, true, false),
	down_1(sheet.getSurface(), 3, 0, 32, true, false),
	left_2(sheet.getSurface(), 0, 1, 32, true, false),
	right_2(sheet.getSurface(), 0, 2, 32, true, false),
	up_2(sheet.getSurface(), 0, 3, 32, true, false),
	down_2(sheet.getSurface(), 0, 0, 32, true, false)
{

}

void Ship::render(int x, int y, SDL_Surface* screen) {
	left_1.render(x,y,screen);
}

void Ship::update(Display* display) {

}
