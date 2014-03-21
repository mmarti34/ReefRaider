#include "Sprite.h"

int Sprite::size = 16;

Sprite::Sprite(SDL_Surface* spriteSheet, int xcoord, int ycoord) {
	x = xcoord;
	y = ycoord;
	sheet = spriteSheet;
	loadSprite();
}

void Sprite::loadSprite() {
	sprite.x = x * size;					// converts to pixel precision
	sprite.y = y * size;					// converts to pixel precision
	sprite.w = size;
	sprite.h = size;
}

void Sprite::render(int xScreen, int yScreen, SDL_Surface* destination) {
	SDL_Rect screenOffset;
	
	screenOffset.x = xScreen;
	screenOffset.y = yScreen;

	SDL_BlitSurface(sheet, &sprite, destination, &screenOffset);
}

int Sprite::getSize() {
	return size;
}
