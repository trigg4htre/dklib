//// DKCamera.h ////

#pragma once
#ifndef DKCamera_H
#define DKCamera_H

#include "DKFrameBase.h"
#include "DKObject.h"


#include <vector>
using namespace std;

struct CameraObject{
	DKFrameBase* the_frame;
	int the_command; //0-NOTHING //1-Move //2-Scale //3-Rotate
	int axis; //1=X, 2=Y, 3=Z
	float angle;
	int start_time;
	int time;
};

class DKCamera
{
public:
	DKCamera();
	~DKCamera();

	static std::vector<CameraObject> cameras; //keep a pointer to all event objects

	static void Rotate(DKFrameBase *frame, int axis, int time);
	static void Animate();

	static void DoRotate(CameraObject *theframe);
};

#endif //DKCamera_H