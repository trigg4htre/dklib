//// DKTextEdit.h ////

#pragma once
#ifndef DKTextEdit_H
#define DKTextEdit_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKFont.h"
#include "DKSquare.h"
#include "DKText.h"

/////////////////////////////////
class DKTextEdit : public DKEvent
{
public:
	DKTextEdit(){};
	DKTextEdit(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	~DKTextEdit();

	void OnMouseButtonDown(SDL_Event* event);
	void OnKeyDown(SDL_Event* event);
	void SendKeyEvent(SDL_Keycode sym);
	DKString GetKey(SDL_Keycode sym);

	void Display();

	bool has_focus;
	DKSquare* square;
	DKText* text;

	static DKObject* NewTextEdit(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
};

#endif //DKTextEdit_H
