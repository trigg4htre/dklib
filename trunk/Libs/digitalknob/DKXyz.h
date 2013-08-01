//// DKXyz.h ////

#pragma once
#ifndef DKXyz_H
#define DKXyz_H

#include "DKObject.h"

/////////////////////////////
class DKXyz : public DKObject
{
public:
	DKXyz(){};
	DKXyz(DKObject* parent);
	void Create(DKObject* parent);
	~DKXyz();

	void Display();

	GLfloat lineX[6];
	GLfloat lineY[6];
	GLfloat lineZ[6];
	GLfloat colorX[16];
	GLfloat colorY[16];
	GLfloat colorZ[16];

	static DKObject* NewXyz(DKObject *parent);
};

#endif //DKXyz_H