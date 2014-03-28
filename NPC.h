#include "Mobile.h"
#include "Display.h"
#include <string>
using namespace std;

#ifndef NPC_H
#define NPC_H

class NPC : public Mobile {
public:
	NPC(string, int, int, int);
	void update(Display*);
	void setRange(int);
private:
	bool toMove();
	void move(Display* display);
	int range;
	int xInit, yInit;
	int xMax, yMax;
	int xMin, yMin;
};

#endif
