#include "Sprite.h"

//int Sprite::size = 16;
//int Sprite::expSize = 4;

Sprite::Sprite(SDL_Surface* spriteSheet, int xcoord, int ycoord, int sprSize, bool solidTile, bool slidingTile) {
	x = xcoord;
	y = ycoord;
	size = sprSize;
	solid = solidTile;
	sliding = slidingTile;
	sheet = spriteSheet;
	loadSprite();
}

bool Sprite::operator==(const Sprite &sprite) const {
	if((x == sprite.x) && (y == sprite.y) && (sheet == sprite.sheet)) {
		return true;
	}
	return false;
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

//int Sprite::getSize() {
//	return size;
//}

//int Sprite::getExpSize() {
//	return expSize;
//}

bool Sprite::isSolid() {
	return solid;
}

bool Sprite::isSliding() {
	return sliding;
}
