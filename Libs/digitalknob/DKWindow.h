//// DKWindow.h ////

#pragma once
#ifndef DKWINDOW_H
#define DKWINDOW_H

#include "DKFrame.h"
#include "DKPanel.h"

#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	#define DESKTOP
#endif
#if defined (IOS) || (ANDROID)
	#define DEVICE
#endif 

//DEBUG
//#define DESKTOP
//#define DEVICE

#ifdef DESKTOP
///////////////////////////////////////////////////
class DKWindow : public DKEvent, public DKFrameBase
{
public:
	DKWindow(){};
	DKWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	void Create(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	~DKWindow();
	
	void OnQuit(SDL_Event* event);
	void OnWindowClose(SDL_Event* event);
	void OnWindowMoved(SDL_Event* event);
	void OnWindowResized(SDL_Event* event);
	void OnWindowRestored(SDL_Event* event);
	//void OnMouseButtonDown(SDL_Event* event);
	//void OnFingerDown(SDL_Event* event);
	void OnKeyDown(SDL_Event* event);

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
	void Display();
	
	DKString title;
	Uint32 win_flags;
	int bpp;

	static DKObject* NewWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
};
#endif //DESKTOP


#ifdef DEVICE
///////////////////////////////
class DKWindow : public DKEvent
{
public:
	DKWindow(){};
	DKWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	void Create(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);
	~DKWindow();
	static DKObject* NewWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags);

	void Display();

	DKString title;
	Uint32 win_flags;

	DKSquare* square;
};
#endif //DEVICE

#endif //DKWINDOW_H