//// DKFps.h ////

#pragma once
#ifndef DKFPS_H
#define DKFPS_H

#include "DKObject.h"
#include "DKFont.h"
#include "DKText.h"

/////////////////////////////
class DKFps : public DKObject
{
public:
	DKFps(){};
	DKFps(DKObject *parent, DKPoint pos, DKFont *font);
	void Create(DKObject *parent, DKPoint pos, DKFont *font);
	~DKFps();
	
	void SetPosition(DKPoint pos);
	void SetRotation(DKRotate rotate);
	void Display();
	int GetFps();

	int last_time;
	int frames;
	int fps;
	DKText text;
	char buffer[20];
};

#endif //FPS_H