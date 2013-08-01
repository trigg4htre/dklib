///// Title.h /////
#ifndef Title_H
#define Title_H

#include "DK.h"

////////////////////////////
class Title : public DKPanel
{
public:	
	//Title(){};
	Title(DKObject *parent, int x, int y, int w, int h);
	//void Create(DKObject *parent, int x, int y, int w, int h);
	~Title(){};

	void OnWindowClose(SDL_Event* event);

	DKImage logo;
};

#endif //Title_H