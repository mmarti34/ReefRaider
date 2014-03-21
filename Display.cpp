#include "Display.h"
#include <math.h>
#include <string>

Display::Display(int WIDTH, int HEIGHT) 
	:terrainSheet( "Terrain.png", 256),

	ice(terrainSheet.getSurface(), 0, 0),
	grass(terrainSheet.getSurface(), 0, 1),
	flower(terrainSheet.getSurface(), 1, 1),
	bush(terrainSheet.getSurface(), 2, 1), 

	mainArea(70,50) {

		width = WIDTH;
		height = HEIGHT;

}

void Display::setOffsets(int x, int y) {
	xOffset = x;
	yOffset = y;
}

void Display::render(SDL_Surface* screen) {
	int xScreen;
	int yScreen;

	for(int y = (yOffset - 16) >> 4; y < ((yOffset + height + 16) >> 4); y++) {
		for(int x = (xOffset - 16) >> 4; x < ((xOffset + width + 16) >> 4); x++) {

			xScreen = x - (xOffset >> 4);
			yScreen = y - (yOffset >> 4);
			
			if(x >= mainArea.getWidth() || y >= mainArea.getHeight() || y < 0 || x < 0) {
				grass.render((xScreen * 16) - (xOffset % 16), (yScreen * 16) - (yOffset % 16), screen);
			}
			else {

				switch(mainArea.getTile(x,y)) {
				case 'G':
					grass.render((xScreen * 16) - (xOffset % 16), (yScreen * 16) - (yOffset % 16), screen);
					break;
				case 'I':
					ice.render((xScreen * 16) - (xOffset % 16), (yScreen * 16) - (yOffset % 16), screen);
					break;
				case 'A':
					flower.render((xScreen * 16) - (xOffset % 16), (yScreen * 16) - (yOffset % 16), screen);
					break;
				}
			}
		}
	}
}
