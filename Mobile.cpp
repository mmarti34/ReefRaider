#include "Mobile.h"

Mobile::Mobile(string sheetPath) 
	:Entity(sheetPath),

	left(sheet.getSurface(), 0, 1, 16, true, false),
	right(sheet.getSurface(), 0, 0, 16, true, false),
	up(sheet.getSurface(), 0, 2, 16, true, false),
	down(sheet.getSurface(), 1, 0, 16, true, false),

	move_left(sheet.getSurface(), 1, 1, 16, true, false),
	move_right(sheet.getSurface(), 2, 1, 16, true, false),
	move_up1(sheet.getSurface(), 1, 2, 16, true, false),
	move_up2(sheet.getSurface(), 2, 2, 16, true, false),
	move_down1(sheet.getSurface(), 2, 0, 16, true, false),
	move_down2(sheet.getSurface(), 3, 0, 16, true, false)
{
	currentlySliding = false;
	direction = 2;
}

void Mobile::render(int xp, int yp, SDL_Surface* screen) {
		
	if(direction == 0) {
		if(((y % 32 > 4) && (y % 32 < 12)) || currentlySliding) {
			move_up1.render(xp, yp, screen);
		} 
		else if((y % 32 > 20) && (y % 32 < 28)) {
			move_up2.render(xp, yp, screen);
		} 
		else {
			up.render(xp, yp, screen);
		}
	} 
	
	else if(direction == 2) {
		if(((y % 32 > 4) && (y % 32 < 12)) || currentlySliding) {
			move_down1.render(xp, yp, screen);
		} 
		else if((y % 32 > 20) && (y % 32 < 28)) {
			move_down2.render(xp, yp, screen);
		} 
		else {
			down.render(xp, yp, screen);
		}
	}

	else if(direction == 3) {
		if(((x % 16 > 4) && (x % 16 < 12)) || currentlySliding) {
			move_left.render(xp, yp, screen);
		} 
		else {
			left.render(xp,yp,screen);
		}
	}

	else if(direction == 1) {
		if(((x % 16 > 4) && (x % 16 < 12)) || currentlySliding) {
			move_right.render(xp, yp, screen);
		} 
		else {
			right.render(xp,yp,screen);
		}
	}

}

Sprite* Mobile::getNextTile(Display* display) {
	Sprite* nextTile;
	int xColl = x + 8;
	int yColl = y + 8;

	switch(direction) {
	case 0:
		nextTile = display->getSprite((xColl >> 4), (yColl >> 4) - 1);
		break;
	case 2:
		nextTile = display->getSprite((xColl >> 4), (yColl >> 4) + 1);
		break;
	case 3:
		nextTile = display->getSprite((xColl >> 4) - 1, (yColl >> 4));
		break;
	case 1:
		nextTile = display->getSprite((xColl >> 4) + 1, (yColl >> 4));
		break;
	}

	return nextTile;
}

Sprite* Mobile::getCurrentTile(Display* display) {
	int xColl = x + 8;
	int yColl = y + 8;
	Sprite* currentTile = display->getSprite(xColl >> 4, yColl >> 4);
	return currentTile;
}

void Mobile::goToNext() {
	switch(direction) {
	case 0:
		y--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;
	case 1:
		x++;
		break;
	}
}

bool Mobile::isCollision(Display* display) {

	Sprite* nextTile = getNextTile(display);
	return nextTile->isSolid();

}

bool Mobile::isSliding(Display* display) {
	Sprite* currentTile;
	int xSlide = x + 8;
	int ySlide = y + 8;
	currentTile = display->getSprite(xSlide >> 4, ySlide >> 4);

	if(currentTile->isSliding() && !isCollision(display)) {

		currentlySliding = true;
		
		if(direction == 0) {
			y-=2;
		}
		
		if(direction == 2) {
			y+=2;
		}
		
		if(direction == 3) {
			x-=2;
		}

		if(direction == 1) {
			x+=2;
		}
		return true;
	} else {
		currentlySliding = false;
	}

	return false;
}

bool Mobile::continueMotion() {
	if((y % 16 != 0) && (direction == 0)) {
		y--;
		return true;
	} 
	else if ((y % 16 != 0) && (direction == 2)) {
		y++;
		return true;
	} 
	else if ((x % 16 != 0) && (direction == 3)) {
		x--;
		return true;
	} 
	else if ((x % 16 != 0) && (direction == 1)) {
		x++;
		return true;
	}

	return false;
}
