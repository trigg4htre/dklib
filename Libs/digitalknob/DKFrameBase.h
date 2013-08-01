//// DKFrameBase.h ////

#pragma once
#ifndef DKFrameBase_H
#define DKFrameBase_H

#include "DKEvent.h"
#include "DKObject.h"
#include "DKAxis.h"
#include "DKOpengl.h"

#include "SDL.h"
#include <math.h>

/////////////////
class DKFrameBase
{
public:
	DKFrameBase();
	~DKFrameBase(){};

	void Setup2D(DKSize size);
	void Setup3D(DKSize size);
	void Perspective(double fovy, double aspect, double zNear, double zFar);
	void LookAt(GLfloat eyex, GLfloat eyey, GLfloat eyez,
           GLfloat centerx, GLfloat centery, GLfloat centerz,
           GLfloat upx, GLfloat upy, GLfloat upz);

	//CAMERA
	GLfloat eye_x;
	GLfloat eye_y;
	GLfloat eye_z;
	GLfloat target_x;
	GLfloat target_y;
	GLfloat target_z;
	GLfloat up_x;
	GLfloat up_y;
	GLfloat up_z;
	GLfloat rot_x;
	GLfloat rot_y;
	GLfloat rot_z;
	GLfloat trans_x; //Blue Line    (Line Horizontal through center of table longways)
	GLfloat trans_y; //Green Line   (Line Horizontal through center of table shortways)
	GLfloat trans_z; //Red Line     (Line Verticle through Center of table)
	GLfloat distance;

	//SDL_GLContext context;
};

#endif //DKFrameBase.h