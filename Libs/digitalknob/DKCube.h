//// DKCube.h ////

#pragma once
#ifndef DKCUBE_H
#define DKCUBE_H

#include "DKObject.h"
#include "DKSquare.h"

//////////////////////////////
class DKCube : public DKObject
{
public:
	DKCube(){};
	DKCube(DKObject *parent, DKPoint pos, DKSize siz);
	void Create(DKObject *parent, DKPoint pos, DKSize siz);
	~DKCube();
	
	void Display();
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);	

	DKSquare front;
	DKSquare back;
	DKSquare right;
	DKSquare left;
	DKSquare top;
	DKSquare bottom;

	static DKObject* NewCube(DKObject *parent, DKPoint pos, DKSize siz);
};

#endif //DKCUBE_H