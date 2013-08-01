#include "DKAxis.h"

////////////////////////////
DKAxis::DKAxis(int x, int y)
{
	this->x = (float)x;
	this->y = (float)y;
	this->z = 0;
}

//////////////////////////////
DKAxis::DKAxis(int x, float y)
{
	this->x = (float)x;
	this->y = y;
	this->z = 0;
}

//////////////////////////////
DKAxis::DKAxis(float x, int y)
{
	this->x = x;
	this->y = (float)y;
	this->z = 0;
}

////////////////////////////////
DKAxis::DKAxis(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

///////////////////////////////////
DKAxis::DKAxis(int x, int y, int z)
{
	this->x = (float)x;
	this->y = (float)y;
	this->z = (float)z;
}

/////////////////////////////////////
DKAxis::DKAxis(float x, int y, int z)
{
	this->x = x;
	this->y = (float)y;
	this->z = (float)z;
}

/////////////////////////////////////
DKAxis::DKAxis(int x, float y, int z)
{
	this->x = (float)x;
	this->y = y;
	this->z = (float)z;
}

/////////////////////////////////////
DKAxis::DKAxis(int x, int y, float z)
{
	this->x = (float)x;
	this->y = (float)y;
	this->z = z;
}

///////////////////////////////////////
DKAxis::DKAxis(float x, float y, int z)
{
	this->x = x;
	this->y = y;
	this->z = (float)z;
}	

///////////////////////////////////////
DKAxis::DKAxis(float x, int y, float z)
{
	this->x = x;
	this->y = (float)y;
	this->z = z;
}

///////////////////////////////////////
DKAxis::DKAxis(int x, float y, float z)
{
	this->x = (float)x;
	this->y = y;
	this->z = z;
}

/////////////////////////////////////////
DKAxis::DKAxis(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}