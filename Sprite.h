#include "SDL.h"
#include "SpriteSheet.h"

#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
public:
	Sprite(SDL_Surface*, int, int);
	void render(int, int, SDL_Surface*);
	int getSize();
private:
	void loadSprite();
	static int size;
	int x, y;					// x and y are the coordinates on the sheet, not pixel coordinates
	SDL_Surface* sheet;
	SDL_Rect sprite;
};

#endif
