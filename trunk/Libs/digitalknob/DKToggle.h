//// DKToggle.h ////

#pragma once
#ifndef DKTOGGLE_H
#define DKTOGGLE_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKImage.h"
#include "DKDebug.h"

/////////////////////////////////////////////////
class DKToggle : public DKEvent//, public DKObject
{
public:
	DKToggle(){};
	DKToggle(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID);
	~DKToggle();
	
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetScale(DKScale scal);
	void Reload();
	void Display();
	void OnMouseButtonDown(SDL_Event* event);
	void OnFingerDown(SDL_Event* event);

	//event info
	void LinkToggleEvent(void (*ToggleEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnToggle)(void*, DKEvent*);
	void* m_arg;

	DKImage* image_off;
	DKImage* image_on;
	bool state;

	static DKObject* NewToggle(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID);
};

#endif //DKTOGGLE_H