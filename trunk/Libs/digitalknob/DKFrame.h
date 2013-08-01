//// DKFrame.h ////

#pragma once
#ifndef DKFRAME_H
#define DKFRAME_H

//#include "DKObjectManager.h"
#include "DKDebug.h"
#include "DKEvent.h"
#include "DKObject.h"
#include "DKFrameBase.h"
#include "DKCamera.h"
#include "DKAnimate.h"


#include "SDL_image.h" //used to set icon


//////////////////////////////////////////////////
class DKFrame : public DKEvent, public DKFrameBase
{
public:
	DKFrame(){};
	DKFrame(DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	void Create(DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	~DKFrame();
	void Delete();
	

	void OnQuit(SDL_Event* event);
	void OnWindowClose(SDL_Event* event);
	void OnWindowMoved(SDL_Event* event);
	void OnWindowResized(SDL_Event* event);
	void OnWindowRestored(SDL_Event* event);
	//void OnMouseButtonDown(SDL_Event* event);
	//void OnFingerDown(SDL_Event* event);
	void OnKeyDown(SDL_Event* event);

	void Exit();
	void SetIcon(DKString file);
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetColor(DKColor rgba);
	void Center(DKSize screen);
	void Fullscreen(DKSize siz);
	void Windowed(DKSize siz);
	void Maximize();
	void Minimize();
	void Restore();
	void Loop();
	
	DKString title;
	Uint32 win_flags;
	int bpp;

	int currTime;
	int prevTime;
	bool active;
};


#endif //DKFRAME_H