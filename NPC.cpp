#include "NPC.h"
#include <cstdlib>
#include <ctime>

NPC::NPC(string sheetName, int maxRange, int xi, int yi) 
	:Mobile(sheetName)
{
	srand(time(NULL));
	range = maxRange * 16;
	xInit = xi * 16;
	yInit = yi * 16;
	x = xInit;
	y = yInit;

	xMax = xInit + range;
	xMin = xInit - range;
	yMax = yInit + range;
	yMin = yInit - range;
}

void NPC::update(Display* display) {
	if(isSliding(display)) {

	} 
	else if(continueMotion()) {

	}
	else if(toMove()) {
		move(display);
	}
}

bool NPC::toMove() {
	if(rand() % 2 == 0) {
		return true;
	}
	return false;
}

void NPC::move(Display* display) {
	direction = rand() % 4;
	if((direction == 0) && (!isCollision(display)) && (y > yMin)) {
		y--;
	} 
	else if((direction == 2) && (!isCollision(display)) && (y < yMax)) {
		y++;
	}
	else if((direction == 3) && (!isCollision(display)) && (x > xMin)) {
		x--;
	}
	else if((direction == 1) && (!isCollision(display)) && (x < xMax)) {
		x++;
	}
}
