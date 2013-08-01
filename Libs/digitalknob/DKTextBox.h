//// DKTextBox.h ////

#pragma once
#ifndef DKTEXTBOX_H
#define DKTEXTBOX_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKFont.h"
#include "DKSquare.h"
#include "DKText.h"

#ifdef IOS
//#include <uikit/SDL_uikitkeyboard.h>
#endif

////////////////////////////////
class DKTextBox : public DKEvent
{
public:
	DKTextBox(){};
	DKTextBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	void Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
	~DKTextBox();
	
	void Display();
	void SetPosition(DKPoint pos);
	void SetRotation(DKRotate rotate);
	DKString GetText();
	void SetText(DKString string);
	
	void LinkWindow(SDL_Window *window);
	void OnMouseButtonDown(SDL_Event* event);
    void OnFingerDown(SDL_Event* event);
	void OnKeyDown(SDL_Event* event);
	void SendKeyEvent(SDL_Keycode sym);
	DKString GetKey(SDL_Keycode sym);

	//event info
	void LinkTextBoxEvent(void (*TextBoxEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnTextBox)(void*, DKEvent*);
	void* m_arg;

	bool has_focus;
	DKSquare* square;
	DKText* text;

	SDL_Window *main_window;

	static DKObject* NewTextBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID);
};

#endif //DKTextBox_H
