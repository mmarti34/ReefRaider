#include "Display.h"
#include "Sprite.h"
#include "Entity.h"

#ifndef MOBILE_H
#define MOBILE_H

class Mobile : public Entity {
public:
	Mobile(string);
	void render(int, int, SDL_Surface*);
	virtual void update(Display*) = 0;
	Sprite* getNextTile(Display*);
	Sprite* getCurrentTile(Display*);
	bool isCollision(Display*);
	bool isSliding(Display*);
protected:
	void goToNext();
	bool continueMotion();
	bool currentlySliding;
	int direction;
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
