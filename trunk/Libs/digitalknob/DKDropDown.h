//// DKDropDown.h ////

#pragma once
#ifndef DKDropDown_H
#define DKDropDown_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKFont.h"
#include "DKTextButton.h"

///////////////////////////////////////////////////
class DKDropDown : public DKEvent//, public DKObject
{
public:
	DKDropDown(){};
	DKDropDown(DKObject *parent, DKPoint pos, DKFont *font, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKFont *font, int eventID);
	~DKDropDown();

	void Show();
	void Display();

	//event info
	void LinkDropDownEvent(void (*DropDownEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnDropDown)(void*, DKEvent*);
	void* m_arg;

	void OnMouseButtonDown(SDL_Event* event);
	void OnTextButton(DKEvent* event);

	void AddSelection(DKString selection, int id);
	void SetColor(DKColor rgba);

	DKFont *m_font;
	std::vector<DKTextButton*> selections;

	static DKObject* NewDropDown(DKObject *parent, DKPoint pos, DKFont *font, int eventID);
};

#endif //DKDropDown_H