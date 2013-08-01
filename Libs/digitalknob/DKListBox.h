//// DKListBox.h ////

#pragma once
#ifndef DKListBox_H
#define DKListBox_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKTextButton.h"

////////////////////////////////
class DKListBox : public DKEvent
{
public:
	DKListBox(){};
	DKListBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	~DKListBox();

	void OnTextButton(DKEvent* event);

	void Display();	
	void AddSelection(DKString selection);
	void AddSelections(DKStringArray strings);
	void ClearSelections();
	void SetPosition(DKPoint pos);
	void SetColor(DKColor rgba);
	
	//event info
	void LinkListBoxEvent(void (*ListBoxEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnListBox)(void*, DKEvent*);
	void* m_arg;

	DKFont *m_font;
	DKSquare *square;
	std::vector<DKTextButton*> selections;
	int current_selection;

	static DKObject* NewListBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
};

#endif //DKLISTBOX_H