#include "SDL.h"
#include "SDL_image.h"
#include "Keyboard.h"
#include "TextWriter.h"
#include "AudioHandler.h"
#include "Player.h"
#include "NPC.h"
#include "Entity.h"
#include "Display.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

////////////////////////// GLOBALS //////////////////////////////////////////////

SDL_Event event;
SDL_Surface* screen = NULL;
Uint32 startTime = 0;

////////////////////////// ENGINE INTERFACE /////////////////////////////////////

class Engine {
public:
	Engine();
	~Engine();
	void close();
	void run();
	void update();
	void render();
	bool start();
private:
	const int WIDTH, HEIGHT, BPP;
	Keyboard *keyboard;
	Display *display;
	TextWriter *textWriter;
	AudioHandler* audio;
	Player *player;
	Mobile *rando;
};

////////////////////////// ENGINE FUNCTIONS /////////////////////////////////////

Engine::Engine() 
	: WIDTH(640),
	HEIGHT(480),
	BPP(32) {

	if(!start()) {
		close();
	}

	keyboard = new Keyboard();
	display = new Display(WIDTH, HEIGHT);
	textWriter = new TextWriter(30);
	player = new Player("Player3.png");
	player->setLocation(WIDTH, HEIGHT);
	rando = new NPC("Player3.png", 5, WIDTH / 16, HEIGHT / 16);
	audio = new AudioHandler();

	audio->initialize();
	audio->play(LANDMUSIC);
}

Engine::~Engine() {
	delete keyboard;
	delete display;
	delete textWriter;
	delete player;
}

bool Engine::start() {

	// Open SDL

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	// Setup Window

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(!screen) {
		return false;
	}
	
	SDL_WM_SetCaption("Reef Raider", NULL);

	return true;
}

void Engine::close() {
	SDL_Quit();
	delete this;
}

void Engine::run() {
	bool quit = false;
	startTime = SDL_GetTicks();
	Uint32 last = SDL_GetTicks();
	Uint32 timer = last;
	Uint32 now;
	int upsPerSecond = 70;
	int frames = 0;

	while(!quit) {
		now = SDL_GetTicks();

		if((now - last) > (1000/upsPerSecond)) {
			update();
			last = now;
			display->ctrIncrement();
		}

		render();
		frames++;

		if(timer - now >= 1000) {
			stringstream fps;
			fps << "Reef Raider   |   " << frames << " FPS";
			SDL_WM_SetCaption(fps.str().c_str(), NULL);
			timer += 1000;
			frames = 0;
		}

		if(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}

	}

}

void Engine::update() {

	player->update(display);
	rando->update(display);

	int xp = player->getX();
	int yp = player->getY();

	display->setOffsets(xp - WIDTH / 2, yp - HEIGHT / 2);

	if(player->isSailing()) {
		audio->switchTo(BOATMUSIC);
	} 
	else if(!(player->isSailing())) {
		audio->switchTo(LANDMUSIC);
	}

}

void Engine::render() {
	SDL_FillRect(screen, NULL, 0x000000);
	display->render(screen);
	player->render(WIDTH/2, HEIGHT/2, screen);
	player->renderAttrib(screen, display);
	int xR = (WIDTH/2) + (rando->getX() - player->getX());
	int yR = (HEIGHT/2) + (rando->getY() - player->getY());
	rando->render(xR, yR, screen);
	//textWriter->write(display->getCurrentTile(), 50, 50, screen);
	//textWriter->write(display->getOffsets(), 50, 50, screen);
	//display->getOffsets();
	SDL_Flip(screen);
}

////////////////////////// DRIVER /////////////////////////////////////

int main(int argc, char **args) {
	Engine *engine = new Engine;

	if(!engine->start()) {
		return 1;
	}

	engine->run();

	engine->close();
}
