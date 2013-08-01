#include "DKDropDown.h"

////////////////////////////////////////////////////////////////////////////////
DKDropDown::DKDropDown(DKObject *parent, DKPoint pos, DKFont *font, int eventID)
{
	Create(parent,pos,font,eventID);
}

/////////////////////////////////////////////////////////////////////////////////
void DKDropDown::Create(DKObject *parent, DKPoint pos, DKFont *font, int eventID)
{
	name = "DKDropDown";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;

	CalculateDraw();
	m_font = font;

	LinkDropDownEvent(DropDownEvent, par, eventID);
	SetVisibility(false);
}

/////////////////////////
DKDropDown::~DKDropDown()
{
	for(unsigned int s=0; s<selections.size(); ++s){
		//delete selections[s];
	}
}

DKObject* DKDropDown::NewDropDown(DKObject *parent, DKPoint pos, DKFont *font, int eventID)
{
	objects.push_back(new DKDropDown(parent, pos, font, eventID));
    return objects[objects.size() - 1];
}

/////////////////////////////////////////////////////////////////////////////////////////////
void DKDropDown::LinkDropDownEvent(void (*DropDownEvent)(void*, DKEvent*), void* arg, int id)
{
	OnDropDown = DropDownEvent;
	m_arg = arg;
	this->id = id;
}

/////////////////////////////////////////////
void DKDropDown::OnTextButton(DKEvent* event)
{
	if(NotVisible()){return;}
	//set extra DKEvent variable here
	id2 = event->id;
	OnDropDown(m_arg, this);
	SetVisibility(false);
}

//////////////////////////////////////////////////
void DKDropDown::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	SetVisibility(false);
}

///////////////////////
void DKDropDown::Show()
{
	BringToFront(this);
	SetVisibility(true);
}

/////////////////////////////////////////////////////////
void DKDropDown::AddSelection(DKString selection, int id)
{
	float total_height = 0;
	float total_width = 0;
	for(unsigned int s=0; s<selections.size(); ++s){
		total_height += selections[s]->size.y;
	}

	selections.push_back((DKTextButton*)DKTextButton::NewTextButton(this, DKPoint(total_width,total_height), m_font, selection, id));

	//correct the width 
	for(unsigned int s=0; s<selections.size(); ++s){
		if(selections[s]->size.x > total_width){
			total_width = selections[s]->size.x;
		}
	}

	for(unsigned int s=0; s<selections.size(); ++s){
		selections[s]->SetSize(DKSize(total_width,selections[s]->size.y,0));
	}

	size.x = total_width;
	size.y = total_height + selections[selections.size()-1]->size.y;
	SetColor(color);
	SetVisibility(false);
}

///////////////////////////////////////
void DKDropDown::SetColor(DKColor rgba)
{
	color = rgba;
	for(unsigned int s=0; s<selections.size(); ++s){
		selections[s]->SetColor(color);
	}
}

//////////////////////////
void DKDropDown::Display()
{
	if(NotVisible()){return;}
	Display2DObjects(this);
}