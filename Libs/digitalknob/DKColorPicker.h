//// DKColorPicker.h ////

#pragma once
#ifndef DKColorPicker_H
#define DKColorPicker_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKWindow.h"
#include "DKFont.h"
#include "DKImage.h"
#include "DKTextButton.h"
#include "DKFile.h"
#include "colorpalette.xpm"
#include "checkers.xpm"

////////////////////////////////////
class DKColorPicker : public DKEvent
{
public:
	DKColorPicker(){};
	DKColorPicker(DKObject *parent, int eventID);
	void Create(DKObject *parent, int eventID);
	~DKColorPicker();

	void OnTextButton(DKEvent* event);
	void OnWindowClose(SDL_Event* event);
	void OnMouseButtonDown(SDL_Event* event);
	void OnMouseMotion(SDL_Event* event);

	//event info
	void LinkColorPickerEvent(void (*ColorPickerEvent)(void*, DKEvent* event), void* arg, int id);
	void (*OnColorPicker)(void*, DKEvent*);
	void* m_arg;

	DKWindow* thiswin;

	DKColor GetCurrentColor();

	DKFont *font;
	DKImage *palette;
	DKImage *alpha;
	DKImage *checkers1;
	DKSquare *current_color;
	DKImage *checkers2;
	DKSquare *selected_color;
	DKTextButton *ok;

	static DKObject* NewColorPicker(DKObject *parent, int eventID);
};

#endif //DKColorPicker_H