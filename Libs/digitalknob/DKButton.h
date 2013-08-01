//// DKButton.h ////

#pragma once
#ifndef DKButton_H
#define DKButton_H

#include "DKImage.h"
#include "DKEvent.h"
#include "DKFile.h"

///////////////////////////////
class DKButton : public DKEvent
{
public:
	DKButton(){};
	DKButton(DKObject *parent, DKPoint pos, DKString file, int eventID);
	DKButton(DKObject *parent, DKPoint pos, const char* const* xpm);
	void Create(DKObject *parent, DKPoint pos, DKString file, int eventID);
	void Create(DKObject *parent, DKPoint pos, const char* const* xpm);
	~DKButton();
	
	void SetFile(DKString file);
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetScale(DKScale scal);
	void Reload();
	void Display();
	void OnMouseButtonDown(SDL_Event* event);
	void OnFingerDown(SDL_Event* event);

	//event info
	void LinkButtonEvent(void (*ButtonEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnButton)(void*, DKEvent*);
	void* m_arg;

	DKImage *image;

	static DKObject* NewButton(DKObject *parent, DKPoint pos, DKString file, int eventID);
};

#endif //DKButton_H