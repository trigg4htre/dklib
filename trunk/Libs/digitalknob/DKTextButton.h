//// DKTextButton.h ////

#pragma once
#ifndef DKTEXTBUTTON_H
#define DKTEXTBUTTON_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKText.h"
#include "DKSquare.h"
#include "DKDebug.h"

///////////////////////////////////
class DKTextButton : public DKEvent
{
public:
	DKTextButton(){};
	DKTextButton(DKObject *parent, DKPoint pos, DKFont *font, DKString string, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKFont *font,DKString string, int eventID);
	~DKTextButton();
	
	void Display();
	void SetColor(DKColor rgba);
	void SetTextColor(DKColor rgba);
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetRotation(DKRotate rotate);
	DKString GetText();
	void SetText(DKString string);
	
	void OnMouseButtonDown(SDL_Event* event);
    void OnFingerDown(SDL_Event* event);

	//event info
	void LinkTextButtonEvent(void (*TextButtonEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnTextButton)(void*, DKEvent*);
	void* m_arg;

	DKSquare* square;
	DKText* text;

	static DKObject* NewTextButton(DKObject *parent, DKPoint pos, DKFont *font, DKString string, int eventID);
};

#endif //DKTEXTBUTTON_H