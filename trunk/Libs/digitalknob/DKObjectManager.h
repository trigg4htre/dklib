///// DKObjectManager.h /////

#pragma once
#ifndef DKOBJECTMANAGER_H
#define DKOBJECTMANAGER_H

#include "DKEvent.h"

//////////////////////////////////////
class DKObjectManager : public DKEvent
{
public:

	DKObjectManager();
	~DKObjectManager();

	static void Delete(unsigned int object_number);
	static void BringForward(unsigned int object_number);
	static void SendBackward(unsigned int object_number);
	static void BringToFront(unsigned int object_number);
	static void SendToBack(unsigned int object_number);

	void SetColor(DKColor color);
	void SetColor(float r, float g, float b, float a);
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetRotation(DKRotate rotate);
	void SetScale(DKScale scal);
	void SetDementions(int d);
	void SetVisibility(bool truefalse);

	static int current_object;
};


#endif //DKOBJECTMANAGER_H