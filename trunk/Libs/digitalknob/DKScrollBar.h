//// DKScrollBar.h ////

#pragma once
#ifndef DKScrollBar_H
#define DKScrollBar_H

#include "DKButton.h"
#include "DKSquare.h"
#include "DKDebug.h"
#include "scroll_left.xpm"
#include "scroll_right.xpm"
#include "scroll_up.xpm"
#include "scroll_down.xpm"

///////////////////////////////////////////////////
class DKScrollBar : public DKEvent//, public DKObject
{
public:
	DKScrollBar(){};
	DKScrollBar(DKObject *parent, int direction);
	void Create(DKObject *parent, int direction);
	~DKScrollBar();

	void OnMouseButtonDown(SDL_Event* event);
	void OnMouseButtonUp(SDL_Event* event);
	void OnMouseMotion(SDL_Event* event);
	void OnButton(DKEvent* event);

	//event info
	void LinkScrollBarEvent(void (*ScrollBarEvent)(void*, DKEvent*), void* arg, int id);
	void (*OnScrollBar)(void*, DKEvent*);
	void* m_arg;

	void UpdateGlide(int diff, int pos);
	void Display();

	int xy;
	DKSquare background;
	DKButton scroll_left;
	DKButton scroll_right;
	DKButton scroll_up;
	DKButton scroll_down;
	DKSquare glide;
	bool dragging;
	int drag_x;
	int drag_y;
};

#endif //DKScrollBar_H