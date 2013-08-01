//// DKSlider.h ////

#pragma once
#ifndef DKSLIDER_H
#define DKSLIDER_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKImage.h"
#include "DKFile.h"

//////////////////////////////////////////////////
class DKSlider : public DKEvent//, public DKObject
{
public:
	DKSlider(){};
	DKSlider(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID);
	~DKSlider();
	
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetRotation(DKRotate rotate);
	void SetScale(DKScale scal);
	void Reload();
	void Display();
	void OnMouseButtonDown(SDL_Event* event);
	void OnMouseButtonUp(SDL_Event* event);
	void OnMouseMotion(SDL_Event* event);
	void OnFingerDown(SDL_Event* event);
	void OnFingerUp(SDL_Event* event);
	void OnFingerMotion(SDL_Event* event);
	void SetRange(int low, int high);
	void SetValue(int value);

	//event info
	void LinkSliderEvent(void (*SliderEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnSlider)(void*, DKEvent*);
	void* m_arg;

	DKString file_background;
	DKString file_knob;
	DKImage* back;
	DKImage* front;
	int v_low;
	int v_hight;
	int value;
	bool sliding;
	int x_slide;
	int y_slide;

	static DKObject* NewSlider(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID);
};

#endif //DKSLIDER_H