//// DKKeyboard.h ////

#pragma once
#ifndef DKKeyboard_H
#define DKKeyboard_H

#include "DKPanel.h"

class DKKeyboard : public DKPanel
{
	DKKeyboard(){};
	DKKeyboard(DKObject *parent);
	void Create(DKObject *parent);
	~DKKeyboard(){};
};
#endif //DKKeyboard_h