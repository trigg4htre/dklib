///// Level1.h /////
#ifndef Level1_H
#define Level1_H

#include "DK.h"

/////////////////////////////
class Level1 : public DKPanel
{
public:
	Level1(DKObject *parent, int x, int y, int w, int h);
	~Level1(){};

	void OnWindowClose(SDL_Event* event);
	void OnMouseMotion(SDL_Event* event);
	void OnMouseButtonDown(SDL_Event* event);

	void Process();
	//void Display();

	DKFps fps;
	DKSquare paddle;
	DKCircle ball;
	DKSquare blocks[20];

	int angle;
	int yDirection;
	int xDirection;

	bool inMotion;
};

#endif //Level1_H