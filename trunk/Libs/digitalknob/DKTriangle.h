//// DKTRIANGLE.h ////

#pragma once
#ifndef DKTRIANGLE_H
#define DKTRIANGLE_H

#include "DKObject.h"

//////////////////////////////////
class DKTriangle : public DKObject
{
public:
	DKTriangle(){};
	DKTriangle(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3);
	void Create(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3);
	~DKTriangle();
	
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetColor(DKColor rgba);
	void SetPoint1Color(DKColor rgba);
	void SetPoint2Color(DKColor rgba);
	void SetPoint3Color(DKColor rgba);
	void Update();
	void Display();

	GLfloat tri_vectors[9];
	GLfloat tri_colors[12];

	static DKObject* NewTriangle(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3);
};

#endif //DKTRIANGLE_H