/// DKColor.h /////////

#pragma once
#ifndef DKColor_H
#define DKColor_H

/////////////
class DKColor
{
public :
	DKColor(){};
	DKColor(float r, float g, float b, float a);
	~DKColor(){};
	
	float r;
	float g;
	float b;
	float a;
};

#endif //DKColor_H