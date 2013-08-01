/// DKMessage.h ///

#pragma once
#ifndef DKMESSAGE_H
#define DKMESSAGE_H

#include "DKPanel.h"
#include "DKFont.h"
#include "DKText.h"
#include "DKTextButton.h"

////////////////////////////////
class DKMessage : public DKPanel
{
public:
	DKMessage(){};
	DKMessage(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, DKString text);
	void Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, DKString text);
	virtual ~DKMessage();

	void OnWindowClose(SDL_Event* event);
	void OnTextButton(DKEvent* event);

	DKText string;
	DKTextButton button;
};

#endif //DKMESSAGE_H