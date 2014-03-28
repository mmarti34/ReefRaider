#include "Entity.h"
#include "Display.h"
#include <string>
using namespace std;

#ifndef PROJECTILE_H
#define PROJECTILE_H

class Projectile : public Entity {
public:
	Projectile(string);
	void setElevation(double);
	void render(int, int, SDL_Surface*);
	void update(Display* display);
	void fire();
	bool isActive();
	void setDirection(int);
private:
	bool fireState;
	Uint32 lastTime;
	double vxy, vz;
	double z;
	double dx, dy;
	double maxDamage;
	int direction;
	Sprite sprite;
};

#endif
