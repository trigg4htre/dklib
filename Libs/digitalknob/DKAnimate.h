//// DKAnimate.h ////

#pragma once
#ifndef DKANIMATE_H
#define DKANIMATE_H

#include "DKObject.h"


#include <vector>
using namespace std;

struct AnimateObject{
	DKObject* object;
	int the_command; //0-NOTHING //1-Move //2-Scale //3-Rotate
	DKAxis start;
	DKAxis end;
	int x_direction;
	int y_direction;
	int z_direction;
	int start_time;
	int the_time;
	int pixels_per_second;
};

///////////////
class DKAnimate
{
public:
	DKAnimate();
	~DKAnimate();

	static std::vector<AnimateObject> animations; //keep a pointer to all event objects

	static void Move(DKObject *object, DKPoint pos, int pixels_per_second);
	static void Size(DKObject *object, DKSize siz, int time);
	static void Scale(DKObject *object, DKScale scale, int time);
	static void Rotate(DKObject *object, DKRotate rotation, int time);
	static void Animate();
	static void DeleteAll();

	static void DoMove(AnimateObject *theObject);
	static void DoSize(AnimateObject *theObject);
	static void DoRotate(AnimateObject *theObject);
	static void DoScale(AnimateObject *theObject);
};

#endif //DKANIMATE_H