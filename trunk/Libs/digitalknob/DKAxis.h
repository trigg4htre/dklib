/// DKAxis.h /////////

#pragma once
#ifndef DKAxis_H
#define DKAxis_H

class DKAxis;
typedef DKAxis DKPoint;
typedef DKAxis DKSize;
typedef DKAxis DKScale;
typedef DKAxis DKDraw;
typedef DKAxis DKRotate;

/////////////
class DKAxis
{
public :
	DKAxis(){};
	DKAxis(int x, int y);
	DKAxis(int x, float y);
	DKAxis(float x, int y);
	DKAxis(float x, float y);
	DKAxis(int x, int y, int z);
	DKAxis(float x, int y, int z);
	DKAxis(int x, float y, int z);
	DKAxis(int x, int y, float z);
	DKAxis(float x, float y, int z);
	DKAxis(float x, int y, float z);
	DKAxis(int x, float y, float z);
	DKAxis(float x, float y, float z);
	~DKAxis(){};
	
	float x;
	float y;
	float z;
};

#endif //DKAxis_H