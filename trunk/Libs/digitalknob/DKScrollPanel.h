/// DKScrollPanel.h /////

#pragma once
#ifndef DKScrollPanel_H
#define DKScrollPanel_H

#include "DKPanel.h"
#include "DKEvent.h"
#include "DKScrollBar.h"
#include "DKGlobal.h"

////////////////////////////////////
class DKScrollPanel : public DKPanel
{
public:
	DKScrollPanel(){};
	DKScrollPanel(DKObject *parent, DKPoint pos, DKSize siz);
	void Create(DKObject *parent, DKPoint pos, DKSize siz);
	~DKScrollPanel();

	void OnMouseButtonDown(SDL_Event* event);
	void OnScrollBar(DKEvent* event);
	void Display();

	DKScrollBar scroll_x;
	DKScrollBar scroll_y;

	static DKObject* NewScrollPanel(DKObject *parent, DKPoint pos, DKSize siz);
	//TODO
	// DKScrollPanel should hold an inner panel (X,Y)
	// We place that panel in our DKScrollPanel
	// We generate scrollbars if the inner panel is bigger in any direction.
	// We calculate the size of the scrollbar to the "oversize" of the inner panel.
	// The inner panel is positioned acording to the scrollbars while clipped.
	
};

#endif //DKScrollPanel_H

