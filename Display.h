#include "SpriteSheet.h"
#include "Sprite.h"
#include "Area.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
using namespace std;

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
	Display(int, int);
	int getWidth();
	int getHeight();
	void setOffsets(int, int);
	void render(SDL_Surface*);
	char* getCurrentTile();
	Sprite* getSprite(int x, int y);
	void getOffsets();
	void ctrIncrement();
	Sprite* getWaterHandle(int);
private:
	void renderTile(int, int, Sprite*, SDL_Surface*);
	int width, height;
	int xOffset, yOffset;
	int ctr;
	SpriteSheet terrainSheet;
	Sprite ice, grass, bush, flower, sand;
	Sprite water1, water2, fence_front, fence_left, fence_right;
	Area mainArea;
};

#endif
