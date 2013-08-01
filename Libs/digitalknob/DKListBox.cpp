#include "DKListBox.h"

//////////////////////////////////////////////////////////////////////////////////////////
DKListBox::DKListBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	Create(parent,pos,siz,font,eventID);
}

////////////////////////////////////////////////////////////////////////////////////////////
void DKListBox::Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	name = "DKListBox";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	CalculateDraw();
	
	size = siz;
	m_font = font;

	square = (DKSquare*)DKSquare::NewSquare(this, DKPoint(0,0), size);
	SetColor(DKColor(1,1,1,1));

	LinkListBoxEvent(ListBoxEvent, par, eventID);
	SetVisibility(true);
}

///////////////////////
DKListBox::~DKListBox()
{
	ClearSelections();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKListBox::NewListBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	objects.push_back(new DKListBox(parent, pos, siz, font, eventID));
    return objects[objects.size() - 1];
}

/////////////////////////////////////////////
void DKListBox::OnTextButton(DKEvent* event)
{
	current_selection = event->id;
	OnListBox(m_arg, this);
}

//////////////////////////////////////////////////////////////////////////////////////////
void DKListBox::LinkListBoxEvent(void (*ListBoxEvent)(void*, DKEvent*), void* arg, int id)
{
	OnListBox = ListBoxEvent;
	m_arg = arg;
	this->id = id;
}

////////////////////////////////////////
void DKListBox::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();

	//Update Child Positions
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this){
			objects[i]->SetPosition(objects[i]->point);
		}
	}

	Update();
}

//////////////////////////////////////
void DKListBox::SetColor(DKColor rgba)
{
	color = rgba;
	square->SetColor(color);
	for(unsigned int s=0; s<selections.size(); ++s){
		selections[s]->SetColor(color);
	}
}

////////////////////////////////////////////////////
void DKListBox::AddSelections(DKStringArray strings)
{
	for(unsigned int i=0; i<strings.size(); ++i){
		AddSelection(strings[i]);
	}
}

////////////////////////////////////////////////
void DKListBox::AddSelection(DKString selection)
{
	float total_height = 0;
	float total_width = 0;
	for(unsigned int s=0; s<selections.size(); ++s){
		total_height += selections[s]->size.y;
	}

	selections.push_back((DKTextButton*)DKTextButton::NewTextButton(this, DKPoint(total_width,total_height), m_font, selection, selections.size()));
	//selections.push_back(new DKTextButton(this, DKPoint(total_width,total_height), m_font, selection));
	//selections[selections.size()-1]->LinkTextButtonEvent(TextButtonEvent,this,selections.size());

	

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
}

/////////////////////////////////
void DKListBox::ClearSelections()
{
	for(unsigned int s=0; s<selections.size(); ++s){
		delete selections[s];
	}
	selections.clear();
}

/////////////////////////
void DKListBox::Display()
{
	if(NotVisible()){return;}
	//glEnable(GL_SCISSOR_TEST);
	Display2DObjects(this);
	//glScissor(point.x,screenHeight-size.y-y_pos,size.x,size.y);
	//glDisable(GL_SCISSOR_TEST);
}