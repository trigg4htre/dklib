//// DKPanel.h ////

#pragma once
#ifndef DKPANEL_H
#define DKPANEL_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKSquare.h"
#include "DKGlobal.h"

//////////////////////////////
class DKPanel : public DKEvent
{
public:
	DKPanel(){};
	DKPanel(DKObject *parent, DKPoint pos, DKSize siz);
	void Create(DKObject *parent, DKPoint pos, DKSize siz);
	~DKPanel();

	//virtual void OnMouseButtonDown(SDL_Event* event){};
	//void OnFingerDown(SDL_Event* event);

	virtual void Display();
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetColor(float r, float g, float b, float a);
	virtual void SetColor(DKColor rgba);
	void Center();

	DKSquare* square;

	static DKObject* NewPanel(DKObject* parent, DKPoint pos, DKSize siz);
};

#endif //DKPANEL_H