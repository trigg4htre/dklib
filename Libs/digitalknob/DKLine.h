//// DKLINE.h ////

#pragma once
#ifndef DKLINE_H
#define DKLINE_H

#include "DKObject.h"

//https://encrypted-tbn1.google.com/images?q=tbn:ANd9GcQ0S-b79_SMmIrNrDPtImbAHXhopdWE_DYf4YcnNDXkcOFsAeuYlA

//////////////////////////////
class DKLine : public DKObject
{
public:
	DKLine(){};
	DKLine(DKObject *parent, DKPoint pos, int x2, int y2, int linewidth);
	void Create(DKObject *parent, DKPoint pos, int x2, int y2, int linewidth);
	~DKLine();
	
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetColor(DKColor rgba);
	void SetPoint1Color(DKColor rgba);
	void SetPoint2Color(DKColor rgba);
	void Update();
	void Display();

	GLfloat line_vectors[24];
	GLfloat line_colors[32];
	int line_width;
	int filter_width;
};

#endif //DKLINE_H