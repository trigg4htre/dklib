//// DKMenuBar.h /////

#pragma once
#ifndef DKMenuBar_H
#define DKMenuBar_H

#include "DKDropDown.h"

//////////////////////////////////////////////////
class DKMenuBar : public DKEvent//, public DKObject
{
public:
	DKMenuBar(){};
	DKMenuBar(DKObject *parent, DKFont *font, int eventID);
	void Create(DKObject *parent, DKFont *font, int eventID);
	~DKMenuBar();

	void OnTextButton(DKEvent* event);
	void OnDropDown(DKEvent* event);

	void Display();
	void AddItem(DKString string);
	void AddSelection(DKString item, DKString selection, int id);
	void SetColor(DKColor rgba);

	//event info
	void LinkMenuBarEvent(void (*MenuBarEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnMenuBar)(void*, DKEvent*);
	void* m_arg;

	DKSquare* square;
	DKFont *m_font;
	
	DKTextButton* button;
	std::vector<DKTextButton*> items;
	std::vector<DKDropDown*> selections;

	static DKObject* NewMenuBar(DKObject *parent, DKFont *font, int eventID);
};

#endif //DKMenuBar_H