#include "DKMenuBar.h"

/////////////////////////////////////////////////////////////////
DKMenuBar::DKMenuBar(DKObject *parent, DKFont *font, int eventID)
{
	Create(parent,font,eventID);
}

///////////////////////////////////////////////////////////////////
void DKMenuBar::Create(DKObject *parent, DKFont *font, int eventID)
{
	name = "DKButton";
	par = parent;
	frame = par->frame;
	win = par->win;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	CalculateDraw();
	
	size.x = par->size.x;
	size.y = 20;
	size.z = 0;
	m_font = font;

	square = (DKSquare*)DKSquare::NewSquare(this, point, size);
	SetColor(DKColor(0.8f,0.8f,0.8f,1));

	LinkMenuBarEvent(MenuBarEvent, par, eventID);
	SetVisibility(true);
}

///////////////////////
DKMenuBar::~DKMenuBar()
{
	for(unsigned int i=0; i<items.size(); ++i){
		//delete items[i];
	}
	for(unsigned int i=0; i<selections.size(); ++i){
		//delete selections[i];
	}
}

////////////////////////////////////////////////////////////////////////////
DKObject* DKMenuBar::NewMenuBar(DKObject *parent, DKFont *font, int eventID)
{
	objects.push_back(new DKMenuBar(parent, font, eventID));
    return objects[objects.size() - 1];
}

//////////////////////////////////////////////////////////////////////////////////////////
void DKMenuBar::LinkMenuBarEvent(void (*MenuBarEvent)(void*, DKEvent*), void* arg, int id)
{
	OnMenuBar = MenuBarEvent;
	m_arg = arg;
	this->id = id;
}

////////////////////////////////////////////
void DKMenuBar::OnTextButton(DKEvent* event)
{
	selections[event->id-1]->SetVisibility(true);
}

//////////////////////////////////////////
void DKMenuBar::OnDropDown(DKEvent* event)
{
	id2 = event->id2;
	OnMenuBar(m_arg, this);
}

////////////////////////////////////////
void DKMenuBar::AddItem(DKString string)
{
	//Calculate the next x position
	int next_x_pos = 0;
	for(unsigned int i=0; i<items.size(); ++i){
		next_x_pos += (int)items[i]->size.x;
	}
	items.push_back((DKTextButton*)DKTextButton::NewTextButton(this, DKPoint(next_x_pos,0), m_font, string, items.size()));
	selections.push_back((DKDropDown*)DKDropDown::NewDropDown(this,DKPoint(items[items.size()-1]->point.x, items[items.size()-1]->point.y+items[items.size()-1]->size.y+2),m_font,selections.size()));
	SetColor(DKColor(0.5f,0.5f,0.5f,1));
}

///////////////////////////////////////////////////////////////////////
void DKMenuBar::AddSelection(DKString item, DKString selection, int id)
{
	for(unsigned int i=0; i<items.size(); ++i){
		if(items[i]->text->string == item){
			selections[i]->AddSelection(selection, id);
		}
	}
}

//////////////////////////////////////
void DKMenuBar::SetColor(DKColor rgba)
{
	color = rgba;
	square->SetColor(color);
	for(unsigned int i=0; i<items.size(); ++i){
		items[i]->SetColor(color);
		selections[i]->SetColor(color);
	}
}

/////////////////////////
void DKMenuBar::Display()
{
	if(NotVisible()){return;}
	size.x = par->size.x; //update to window size
	square->SetSize(DKSize(size.x,20));
	Display2DObjects(this);
}