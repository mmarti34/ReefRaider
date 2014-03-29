#include "Projectile.h"
#include "SDL.h"

Projectile::Projectile(string pathName) 
	:Entity(pathName),
	sprite(sheet.getSurface(), 0, 0, 16, true, false)
{
	z = 3;
	x = 0;
	y = 0;
	vxy = 0;
	vz = 0;
	fireState = false;
	direction = 0;
	lastTime = 0;
}

void Projectile::setElevation(double newHeight) {
	z = newHeight;
}

void Projectile::render(int xRender, int yRender, SDL_Surface* screen) {
	if(fireState) {
		sprite.render(xRender + x + (int)dx, yRender + y + (int)dy, screen);
	}
}

void Projectile::update(Display* display) {

	double dt;

	// Update Time
	if(lastTime) {
		dt = (double)(SDL_GetTicks() - lastTime) / 1000;
	} else {
		dt = 0;
	}
	lastTime = SDL_GetTicks();
	
	// Get z-Directional Change

	vz += g * dt;
	z += vz * dt;

	// Get xyPlane-Directional Change

	switch(direction) {
	case 0:
		dy -= vxy * dt;
		break;
	case 2:
		dy += vxy * dt;
		break;
	case 3:
		dx -= vxy * dt;
		break;
	case 1:
		dx += vxy * dt;
		break;
	}

	if(z <= 0) {
		fireState = false;
		z = 3;
		dx = 0; 
		dy = 0;
		vz = 0;
		lastTime = 0;
	}

}

void Projectile::fire() {
	fireState = true;
	vxy = 200;
}

bool Projectile::isActive() {
	return fireState;
}

void Projectile::setDirection(int newdir) {
	direction = newdir;
}
