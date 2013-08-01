#include "DKToggle.h"

//////////////////////////////////////////////////////////////////////////////////////////////
DKToggle::DKToggle(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID)
{
	Create(parent,pos,file1,file2,eventID);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void DKToggle::Create(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID)
{
	name = "DKToggle";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;

	CalculateDraw();

	state = false;
	image_off = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), file1);
	image_on = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), file2);
	size.x = image_off->size.x;
	size.y = image_off->size.y;

	LinkToggleEvent(ToggleEvent, par, eventID);
	SetVisibility(true);
}

/////////////////////
DKToggle::~DKToggle()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKToggle::NewToggle(DKObject *parent, DKPoint pos, DKString file1, DKString file2, int eventID)
{
	objects.push_back(new DKToggle(parent, pos, file1, file2, eventID));
    return objects[objects.size() - 1];
}

///////////////////////////////////////
void DKToggle::SetPosition(DKPoint pos)
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

///////////////////////////////////////////
void DKToggle::SetSize(DKSize siz)
{
	size = siz;
	image_off->SetSize(size);
	image_on->SetSize(size);
}

/////////////////////////////////////
void DKToggle::SetScale(DKScale scal)
{
	scale = scal;
	//image_off.SetScale(scale);
	//image_on.SetScale(scale);
}

////////////////////////
void DKToggle::Display()
{
	if(NotVisible()){return;}
	if(state == false){
		image_off->SetVisibility(true);
		image_on->SetVisibility(false);
	}
	else{
		image_off->SetVisibility(false);
		image_on->SetVisibility(true);
	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this && objects[i]->dimensions == 2){
			objects[i]->Display();
		}
	}

	glPopMatrix();
}

///////////////////////
void DKToggle::Reload()
{
	image_off->Reload();
	image_on->Reload();
}

///////////////////////////////////////////////////////////////////////////////////////
void DKToggle::LinkToggleEvent(void (*ToggleEvent)(void*, DKEvent*), void* arg, int id)
{
	OnToggle = ToggleEvent;
	m_arg = arg;
	this->id = id;
}

//////////////////////////////////////////////////
void DKToggle::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && 
	event->button.y >= draw.y && event->button.y <= draw.y+size.y && 
	event->button.button == SDL_BUTTON_LEFT){
		DKDebug("DKToggle Clicked\n");
		if(state == true){state = false;}
		else{state = true;}
		OnToggle(m_arg, this);
		SkipEvents();
		Update(); //Refresh
	}
}

/////////////////////////////////////////////
void DKToggle::OnFingerDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	int tX = (int)event->tfinger.x * (int)frame->size.x;
	int tY = (int)event->tfinger.y * (int)frame->size.y;
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){
		DKDebug("DKToggle Clicked\n");
		if(state == true){state = false;}
		else{state = true;}
		OnToggle(m_arg, this);
		SkipEvents();
	}
}