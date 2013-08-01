///// DKObject.h /////

//Take notes from wxWidgets hierarchy
//http://www.wxwidgets.org/docs/hierarchy_stable_image.htm

#pragma once
#ifndef DKOBJECT_H
#define DKOBJECT_H

#include "DKString.h"
#include "DKColor.h"
#include "DKAxis.h"

#include "SDL.h"
#include <vector>

// defines for center
#define DKCENTERX -1
#define DKCENTERY -1

//class DKObjectManager;
class DKFrame;
class DKFont;

//////////////
class DKObject
{
public:

	DKObject();
	DKObject(DKObject* parent, DKString className);
	void Create(DKObject* parent, DKString className);
	void Create(DKObject *parent, DKPoint pos, DKSize siz, DKString className);
	virtual ~DKObject();
	void Delete();
	
	//Static functions and variables 
	static void Update();
	static void Display2DObjects(DKObject *parent);
	static void Display3DObjects(DKObject *parent);
	static void ProcessObjects(DKObject *parent);
	static void ReloadAllTextures();
	static bool TestCollision(DKObject *object1, DKObject* object2);

	// Z-order functions
	static void MoveToSpot(DKObject *object, unsigned int n);
	static void BringForward(DKObject *object);
	static void SendBackward(DKObject *object);
	static void BringToFront(DKObject *object);
	static void SendToBack(DKObject *object);

	static std::vector<DKObject*> objects; //keep a pointer to all objects
	static int current_object;
	static bool update;
	static bool fullscreen;
	static DKObject *dkframe;
	
	//Virtual functions
	virtual void Display(){};
	virtual void Process(){};
	virtual void Reload(){};

	virtual void SetColor(DKColor rgba);
	virtual void SetColor(float r, float g, float b, float a);
	virtual void SetPosition(DKPoint pos);
	virtual void SetSize(DKSize siz);
	virtual void SetRotation(DKRotate rotate);
	virtual void SetScale(DKScale scal);
	virtual void SetDementions(int d);
	virtual void SetVisibility(bool truefalse);
	virtual bool NotVisible();
	virtual bool WrongWindow(SDL_Event* event);
	virtual void CalculateDraw();

	
	DKObject *frame; //Frame
	DKObject *par; //Parent
	//DKObject *object; //Self
	SDL_Window *win; //window
	SDL_GLContext context; //FIXME - this should be a pointer.
	int dimensions;
	DKString name;
	DKColor color;
	DKPoint point;
	DKSize size;
	DKDraw draw;
	DKScale scale;
	DKRotate rotation;
	
	//FIXME
	// Remove these
	float x_pos2;
	float y_pos2;
	float z_pos2;
	float x_pos3;
	float y_pos3;
	float z_pos3;

	//FIXME - we can only clip one object in a chain at a time.
	//  example:  (Panel1) can clip it's child (panel2)
	//            (panel2) can NOT clip it's child (panel3) at the same time.
	//  we need to code in cliping ability all the way down the parent<->child chain.
	bool clip;
	
	//For lines and triangles
	DKPoint point2;
	DKPoint point3;


private:
	bool visible;

	//DKAlign align; // X: 0(left) 1(center) 2(right)
	                 // Y: 0(top) 1(center) 2(bottom)
	                 // Z: 0(front) 1(middle) 2(back)

	//virtual void AlignLeft(){align.x = 0;};
	//virtual void AlignRight(){align.x = 2;};
	//virtual void AlignTop(){align.y = 0;};
	//virtual void AlignBottom(){align.y = 2;};
	//virtual void AlignXCenter(){align.x = 1;};
	//virtual void AlignYCenter(){align.y = 1;};	
};



#endif //DKOBJECT_H
