//// DKSquare.h ////
//
// If we look close at the corners of an inlarged square, you can see gaps.
// I've tried to extend the outlines, it does not work. 
// I think you would have to play with the blending options to get that working.
//
// The resolution now should be just to fill in those spots with small Triangle_Strips
// Anti-aliased corners. Can it be done better?

#pragma once
#ifndef DKSQUARE_H
#define DKSQUARE_H

#include "DKObject.h"

////////////////////////////////
class DKSquare : public DKObject
{
public:
	DKSquare();
	DKSquare(DKObject *parent, DKPoint pos, DKSize siz);
	void Create(DKObject *parent, DKPoint pos, DKSize siz);
	~DKSquare();
	void Recalculate();
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetScale(DKScale scal);
	void SetColor(DKColor rgba);
	void SetTopLeftColor(DKColor rgba);
	void SetTopRightColor(DKColor rgba);
	void SetBottomLeftColor(DKColor rgba);
	void SetBottomRightColor(DKColor rgba);
	void Display();

	GLfloat square_vectors[8];
	GLfloat square_colors[16];
	GLfloat outline[8];
	GLfloat outline_color[16];
	GLfloat outline2[8];
	GLfloat outline_color2[16];
	GLfloat outline3[8];
	GLfloat outline_color3[16];
	GLfloat outline4[8];
	GLfloat outline_color4[16];
	int softness;

	static DKObject* NewSquare(DKObject *parent, DKPoint pos, DKSize siz);
};

#endif //DKSQUARE_H