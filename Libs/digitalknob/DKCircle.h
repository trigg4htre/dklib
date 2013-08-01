//// DKCircle.h ////

#pragma once
#ifndef DKCIRCLE_H
#define DKCIRCLE_H

#include "DKObject.h"

#include <math.h>
#define DEGREES_TO_RADIANS(x) (3.14159265358979323846 * x / 180.0)

////////////////////////////////
class DKCircle : public DKObject
{
public:
	DKCircle(){};
	DKCircle(DKObject *parent, DKPoint pos, DKSize siz);
	void Create(DKObject *parent, DKPoint pos, DKSize siz);
	~DKCircle();
	
	void Display();
	void SetSize(DKSize siz);
	void SetColor(DKColor rgba);

	GLfloat circle_vectors[200]; //segments * 2
	GLfloat circle_colors[400]; //segments * 4
	//GLfloat circle2[12];
	bool filled;
	int segments;

	static DKObject* NewCircle(DKObject *parent, DKPoint pos, DKSize siz);
};

#endif //DKCIRCLE_H