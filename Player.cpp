#include "Player.h"

Player::Player() 
	:playerSprites("Player3.png", 256),

	left(playerSprites.getSurface(), 0, 1),
	right(playerSprites.getSurface(), 0, 0),
	up(playerSprites.getSurface(), 0, 2),
	down(playerSprites.getSurface(), 1, 0),

	move_left(playerSprites.getSurface(), 1, 1),
	move_right(playerSprites.getSurface(), 2, 1),
	move_up1(playerSprites.getSurface(), 1, 2),
	move_up2(playerSprites.getSurface(), 2, 2),
	move_down1(playerSprites.getSurface(), 2, 0),
	move_down2(playerSprites.getSurface(), 3, 0)
{
	x = 0; 
	y = 0;
	direction = 1; 
	keyboard = new Keyboard();
}

Player::~Player() {
	delete keyboard;
}

void Player::render(int xp, int yp, SDL_Surface* screen) {
	
	if(direction == 0) {
		if((y % 32 > 4) && (y % 32 < 12)) {
			move_up1.render(xp, yp, screen);
		} 
		else if((y % 32 > 20) && (y % 32 < 28)) {
			move_up2.render(xp, yp, screen);
		} 
		else {
			up.render(xp, yp, screen);
		}
	} 
	
	else if(direction == 1) {
		if((y % 32 > 4) && (y % 32 < 12)) {
			move_down1.render(xp, yp, screen);
		} 
		else if((y % 32 > 20) && (y % 32 < 28)) {
			move_down2.render(xp, yp, screen);
		} 
		else {
			down.render(xp, yp, screen);
		}
	}

	else if(direction == 2) {
		if((x % 16 > 4) && (x % 16 < 12)) {
			left.render(xp, yp, screen);
		} 
		else {
			move_left.render(xp,yp,screen);
		}
	}

	else if(direction == 3) {
		if((x % 16 > 4) && (x % 16 < 12)) {
			right.render(xp, yp, screen);
		} 
		else {
			move_right.render(xp,yp,screen);
		}
	}

}

void Player::update() { 
	keyboard->update();
	if(keyboard->getState(SDLK_UP)) { 
		y--; 
		direction = 0;
	}
	else if(keyboard->getState(SDLK_DOWN)) {
		y++; 
		direction = 1;
	}
	
	else if(keyboard->getState(SDLK_LEFT)) {
		x--; 
		direction = 2;
	}
	
	else if(keyboard->getState(SDLK_RIGHT)) {
		x++; 
		direction = 3;
	}
}

void Player::setLocation(int newX, int newY) {
	x = newX;
	y = newY;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}
