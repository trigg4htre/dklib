#include "DKObject.h"
#include "DKSquare.h"
//#include "DKObjectManager.h"

//define our static variables
std::vector<DKObject*> DKObject::objects;
int DKObject::current_object = 0;
bool DKObject::update = true;
bool DKObject::fullscreen;
DKObject* DKObject::dkframe = NULL;
//DKObjectManager DKObject::dko;

////////////////////
DKObject::DKObject()
{
	point.x = 0;
    point.y = 0;
	point.z = 0;
	size.x = 0;
	size.y = 0;
	size.z = 0;
	color.r = 0.5f;
	color.g = 0.5f;
	color.b = 0.5f;
	color.a = 1;
	draw.x = 0;
	draw.y = 0;
	draw.z = 0;
	scale.x = 1;
	scale.y = 1;
	scale.z = 1;
	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;
	dimensions = 2;
	clip = false;

	//align.x = 0; //left
	//align.y = 0; //top
	//align.z = 0; //front

	//Update();
}

////////////////////////////////////////////////////////
DKObject::DKObject(DKObject* parent, DKString className)
{
	Create(parent, className);
}

///////////////////////////////////////////////////////////
void DKObject::Create(DKObject* parent, DKString className)
{
	name = className;
	par = parent;

	//DKFrame and DKWindow keep their own self created window variable
	if(name.compare("DKFrame") != 0 && name.compare("DKWindow") != 0){
		frame = par->frame;
		win = par->win; //everything else gets the window from it's parent.
    }
	else{frame = this;}


	//I think the best idea here is to only insert ROOT objects, and let the object itself
	//store it's children objects.  I.E.  Frame->Button->Image.  Only button will get inserted. 
	//Then it's up to button to draw it's children when it is called to draw. 

	//But then that takes away our self loading objects, and we must insert them manually. 
	//But it will also be easier to sort the array without leaving children behind. 
	//Sorting the array is a good way to keep control of the drawing z-order.

	//Now do we use a multi-dimentional vector?  objects[window#][object#]  ???

	//In the long run, how will this effect events and their order of processing??

	//Last words:
	//
	// Object number 0 will always be a DKFrameBase (DKFrame or DKWindow). 
	// This vector should actually be called "display_list" because thats what it really is.
	// Only 1 instance of DKFrame should be allowed since it is the grand parent. 
	// Only DKFrame should be fullscreenable. 
	//
	//
	//
	//
	//
	// And now that I think about it, each windows whould have it's own update variable. 
	// It should also have it's own point to base frame. 
	//
	// should these vector arrays Actually be held in DKFrameBase ?
	//
	//  Example:
	//
	//  DKFrame -> DKFrameBase -> vector<> display_list
	//                         -> bool update
	//
	//  DKWindow -> DKFrameBase -> vector<> display_list
	//                          -> bool update
	//
	//  DKWindow -> DKFrameBase -> vector<> display_list
	//                          -> bool update
	//
	//  Then DKFrameBase can have a vector of DKFrameBases to push_back each window.
	//  Now we have a z-order for windows mabey? At least a draw order.
	//  And each windows can have it's own update variable.
	//
	//	Then we can have static DKFrameBase::DisplayObjects()
	//
	//  we can itterate through the DKFrameBase vector calling DisplayObjects for each window. 
	//  
	//

	
	//FIXME - this does not work on new windows
	if(objects.size() == 0){ dkframe = this; } //store the frame for easy access

	objects.push_back(this);
	Update();
}

////////////////////////////////////////////////////////////////////////////////////
void DKObject::Create(DKObject *parent, DKPoint pos, DKSize siz, DKString className)
{
	par = parent;
	point = pos;
	size = siz;
	name = className;

	//DKFrame and DKWindow keep their own self created window variable
	if(name.compare("DKFrame") != 0 && name.compare("DKWindow") != 0){
		frame = par->frame;
		win = par->win; //everything else gets the window from it's parent.
    }
	else{frame = this;}

	if(objects.size() == 0){ dkframe = this; } //store the frame for easy access

	objects.push_back(this);
	Update();
}

/////////////////////
DKObject::~DKObject()
{
	//Object deleted?  remove it from the vector
	for(unsigned int i = (objects.size() - 1); i > 0; --i){
		if(objects[i] == this){
			objects.erase(objects.begin()+i);
		}
	}
}

///////////////////////
void DKObject::Delete()
{

	for(unsigned int i = (objects.size() - 1); i > 0; --i){
		//if(objects[i] != 0){
			delete objects[i];
		//}
	}
	delete objects[0];
	objects.clear();
}

///////////////////////////////////////////////////////////
void DKObject::MoveToSpot(DKObject *object, unsigned int n)
{
	if(n < 1){n=1;} //1 is the lowest allowed
	if(n > objects.size()-1){n=objects.size()-1;} //TESTME - objects size is the highest allowed
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i] == object){
			objects.insert(objects.begin()+n+1, object);
			if(n < i){
				objects.erase(objects.begin()+i+1);
			}
			else{
				objects.erase(objects.begin()+i);
			}
		}
	}
}

/////////////////////////////////////////////
void DKObject::BringForward(DKObject *object)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i] == object){
			if(i<objects.size()-1){
				objects.insert(objects.begin()+i+2, object);
				objects.erase(objects.begin()+i);
				return;
			}
			else{
				BringToFront(object);
				return;
			}
		}
	}
}

/////////////////////////////////////////////
void DKObject::SendBackward(DKObject *object)
{
	//FIXME - not working correctly
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i] == object){
			objects.insert(objects.begin()+i-1, object);
			objects.erase(objects.begin()+i+1);
			return;
		}
	}
}

/////////////////////////////////////////////
void DKObject::BringToFront(DKObject *object)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i] == object){
			objects.push_back(object);
			objects.erase(objects.begin()+i);
		}
	}
}

///////////////////////////////////////////
void DKObject::SendToBack(DKObject *object)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i] == object){
			objects.insert(objects.begin()+1, object);
			objects.erase(objects.begin()+i+1);
		}
	}
}

///////////////////////
void DKObject::Update()
{
	update = true;
}

///////////////////////////////////////////////
void DKObject::ProcessObjects(DKObject *parent)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == parent){
			objects[i]->Process();
		}
	}
}

/////////////////////////////////////////////////
void DKObject::Display2DObjects(DKObject *parent)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == parent && objects[i]->dimensions == 2){
				objects[i]->Display();
		}
	}
}

/////////////////////////////////////////////////
void DKObject::Display3DObjects(DKObject *parent)
{
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == parent && objects[i]->dimensions == 3){
			objects[i]->Display();
		}
	}
}

//////////////////////////////////
void DKObject::ReloadAllTextures()
{
	for(unsigned int i=0; i<objects.size(); ++i){
		objects[i]->Reload(); //trigger Reload for all event objects
	}
}

///////////////////////////////////////////////////////////
void DKObject::SetColor(float r, float g, float b, float a)
{
	SetColor(DKColor(r,g,b,a));
}

/////////////////////////////////////
void DKObject::SetColor(DKColor rgba)
{
	color = rgba;
	Update();
}

///////////////////////////////////////
void DKObject::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();

	//Update Child Positions
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this){
			objects[i]->SetPosition(objects[i]->point);
		}
	}
}

//////////////////////////////////
void DKObject::SetSize(DKSize siz)
{
	size = siz;
	Update();
}

///////////////////////////////////////////
void DKObject::SetRotation(DKRotate rotate)
{
	rotation = rotate;
	Update();
}

/////////////////////////////////////
void DKObject::SetScale(DKScale scal)   
{
	scale = scal;
	Update();
}

///////////////////////////////////
void DKObject::SetDementions(int d)
{
	dimensions = d;
}

////////////////////////////////////////////
void DKObject::SetVisibility(bool truefalse)
{
	visible = truefalse;

	//Update Child visibilities
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this){
			objects[i]->SetVisibility(truefalse);
		}
	}
	Update();
}

///////////////////////////
bool DKObject::NotVisible()
{
	if(visible != true){
		return true;
	}
	return false;
}

////////////////////////////////////////////
bool DKObject::WrongWindow(SDL_Event* event)
{
	if(SDL_GetWindowID(win) != event->window.windowID){
		return true;
	}
	return false;

}

//////////////////////////////
void DKObject::CalculateDraw()
{
	draw.x = par->draw.x + point.x;
	draw.y = par->draw.y + point.y;
	draw.z = par->draw.z + point.z;
}

//////////////////////////////////////////////////////////////////
bool DKObject::TestCollision(DKObject *object1, DKObject* object2)
{
	// http://www.gamedev.net/page/resources/_/technical/game-programming/collision-detection-algorithm-r754

	if(object2->point.y+object2->size.y < object1->point.y){ //BY2<AY1
		return false; //no collision
	}
	if(object1->point.y+object1->size.y < object2->point.y){ //AY2<BY1
		return false; //no collision
	}
	if(object2->point.x+object2->size.x < object1->point.x){ //BX2<AX1
		return false; //no collision
	}
	if(object1->point.x+object1->size.x < object2->point.x){ //AX2<BX1 
		return false; //no collision
	}
	return true;
}