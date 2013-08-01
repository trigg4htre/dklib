#include "DKSlider.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
DKSlider::DKSlider(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID)
{
	Create(parent,pos,background,knob,eventID);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
void DKSlider::Create(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID)
{
	if(!DKFile::FileExists(background) || !DKFile::FileExists(knob)){
		DKDebug("Image File Does Not Exist\n");
		return;
	}
	name = "DKButton";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;

	CalculateDraw();

	back = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), background);
	front = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), knob);

	size.x = back->size.x;
	size.y = back->size.y;
	v_low = 0;
	v_hight = 100;
	value = 50;
	sliding = false;
	x_slide = 0;
	y_slide = 0;

	LinkSliderEvent(SliderEvent, par, eventID);
	SetVisibility(true);
}

/////////////////////
DKSlider::~DKSlider()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKSlider::NewSlider(DKObject *parent, DKPoint pos, DKString background, DKString knob, int eventID)
{
	objects.push_back(new DKSlider(parent, pos, background, knob, eventID));
    return objects[objects.size() - 1];
}

///////////////////////////////////////
void DKSlider::SetPosition(DKPoint pos)
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
void DKSlider::SetSize(DKSize siz)
{
	size = siz;
	back->SetSize(size);
	front->SetSize(size);
}

///////////////////////////////////////////
void DKSlider::SetRotation(DKRotate rotate)
{
	rotation = rotate;
	//back->SetRotation(rotation);
	//front->SetRotation(rotation);
}

/////////////////////////////////////
void DKSlider::SetScale(DKScale scal)
{
	scale = scal;
	//back->SetScale(scale);
	//front->SetScale(scale);
}

///////////////////////
void DKSlider::Reload()
{
	back->Reload();
	front->Reload();
}

//////////////////////////////////////////
void DKSlider::SetRange(int low, int high)
{
	v_low = low;
	v_hight = high;
}

////////////////////////////////
void DKSlider::SetValue(int val)
{
	value = val;
}

///////////////////////////////////////////////////////////////////////////////////////
void DKSlider::LinkSliderEvent(void (*SliderEvent)(void*, DKEvent*), void* arg, int id)
{
	OnSlider = SliderEvent;
	m_arg = arg;
	this->id = id;
}

//////////////////////////////////////////////////
void DKSlider::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= front->draw.x && event->button.x <= front->draw.x+front->size.x && event->button.y >= front->draw.y && event->button.y <= front->draw.y+front->size.y && event->button.button == SDL_BUTTON_LEFT){
		DKDebug("DKSlider clicked\n");
		OnSlider(m_arg, this);
		x_slide = (int)(event->button.x - front->draw.x + draw.x);
		y_slide = (int)(event->button.y - front->draw.y + draw.y);
		sliding = true;
		SkipEvents();
	}
}

/////////////////////////////////////////////
void DKSlider::OnFingerDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	int tX = (int)event->tfinger.x * (int)frame->size.x;
	int tY = (int)event->tfinger.y * (int)frame->size.y;
	if(tX >= front->draw.x && tX <= front->draw.x+front->size.x && tY >= front->draw.y && tY <= front->draw.y+front->size.y){
		DKDebug("DKSlider clicked\n");
		OnSlider(m_arg, this);
		x_slide = (int)(tX - front->draw.x+draw.x);
		y_slide = (int)(tY - front->draw.y+draw.y);
		sliding = true;
		SkipEvents();
	}
}

////////////////////////////////////////////////
void DKSlider::OnMouseButtonUp(SDL_Event* event)
{
	sliding = false;
}

///////////////////////////////////////////
void DKSlider::OnFingerUp(SDL_Event* event)
{
	sliding = false;
}

//////////////////////////////////////////////
void DKSlider::OnMouseMotion(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(sliding == true){
		//FIXME - we need to set the value
		int y = event->button.y - y_slide;
		if(y < 0){
			y = 0;
		}
		if(y > this->size.y - front->size.y){
			y = (int)this->size.y - (int)front->size.y;
		}
		front->SetPosition(DKPoint(0, y, point.z));
		int temp = y;//this->size.y / (v_high = v_low);
		SetValue(temp);
		OnSlider(m_arg, this);
		SkipEvents();
	}
}


///////////////////////////////////////////////
void DKSlider::OnFingerMotion(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(sliding == false){return;}

	//FIXME SDL_GetTouch Broken
	/*
	int tX = event->tfinger.x * (int)frame->size.x / SDL_GetTouch(event->tfinger.touchId)->xres;
	int tY = event->tfinger.y * (int)frame->size.y / SDL_GetTouch(event->tfinger.touchId)->yres;
	*/

	//FIXME - we need to restrict where the knob can go
	//FIXME - we need to set the value

	//FIXME SDL_GetTouch Broken
	//front->SetPosition(DKPoint(tX - x_slide, tY - y_slide, point.z));
	
	OnSlider(m_arg, this);
	SkipEvents();
}

////////////////////////
void DKSlider::Display()
{
	if(NotVisible()){return;}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	////  Transformations ////////////////////////////////////
	glTranslatef(point.x+size.x/2, point.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(point.x+size.x/2),-(point.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	Display2DObjects(this);
	glPopMatrix();
}