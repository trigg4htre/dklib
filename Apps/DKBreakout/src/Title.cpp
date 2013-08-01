#include "Title.h"

//////////////////////////////////////////////////////////
Title::Title(DKObject *parent, int x, int y, int w, int h)
	: DKPanel(parent, DKPoint(x,y), DKSize(w,h))
{
	logo.Create(this, DKPoint(w/2-128,h/2-128), DKFile::DataPath("DKBreakoutLogo.png"));
}

///////////////////////////////////////////
void Title::OnWindowClose(SDL_Event* event)
{
	if(event->window.windowID == 1){
		delete this;
		return;
	}
}