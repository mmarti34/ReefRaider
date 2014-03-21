#include "SpriteSheet.h"
#include "Keyboard.h"
#include "Sprite.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player();
	~Player();
	void render(int, int, SDL_Surface*);
	void update();
	void setLocation(int, int);
	int getX();
	int getY(); 
private:
	int x, y;
	int direction;
	Keyboard* keyboard;
	SpriteSheet playerSprites;
	Sprite left;
	Sprite right;
	Sprite up;
	Sprite down;
	Sprite move_left;
	Sprite move_right;
	Sprite move_down1;
	Sprite move_down2;
	Sprite move_up1;
	Sprite move_up2;
};

#endif
