#include "DKTextButton.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
DKTextButton::DKTextButton(DKObject *parent, DKPoint pos, DKFont *font, DKString string, int eventID)
{
	Create(parent,pos,font,string,eventID);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
void DKTextButton::Create(DKObject *parent, DKPoint pos, DKFont *font,  DKString string, int eventID)
{
	name = "DKTextButton";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	CalculateDraw();
	size.x = (float)font->GetWidth(string)+7;
	size.y = (float)font->GetHeight()+7;
	//square.Create(this, DKPoint(0,0), size);
	//text.Create(this, DKPoint(3,3), font, string);
	square = (DKSquare*)DKSquare::NewSquare(this, DKPoint(0,0), size);
	text = (DKText*)DKText::NewText(this, DKPoint(3,3), font, string);
	SetColor(DKColor(0.8f,0.8f,0.8f,1));
	SetTextColor(DKColor(0,0,0,1));
	LinkTextButtonEvent(TextButtonEvent, par, eventID);
	SetVisibility(true);
}

/////////////////////////////
DKTextButton::~DKTextButton()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKTextButton::NewTextButton(DKObject *parent, DKPoint pos, DKFont *font, DKString string, int eventID)
{
	objects.push_back(new DKTextButton(parent, pos, font, string, eventID));
    return objects[objects.size() - 1];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void DKTextButton::LinkTextButtonEvent(void (*TextButtonEvent)(void*, DKEvent*), void* arg, int id)
{
	OnTextButton = TextButtonEvent;
	m_arg = arg;
	this->id = id;
}

/////////////////////////////////////////
void DKTextButton::SetColor(DKColor rgba)
{
	square->SetColor(rgba);
}

/////////////////////////////////////////////
void DKTextButton::SetTextColor(DKColor rgba)
{
	text->SetColor(rgba);
}

///////////////////////////////////////////
void DKTextButton::SetPosition(DKPoint pos)
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

//////////////////////////////////////
void DKTextButton::SetSize(DKSize siz)
{
	size = siz;
	square->SetSize(size);
}

///////////////////////////////////////////////
void DKTextButton::SetRotation(DKRotate rotate)
{
	rotation = rotate;
	//square.SetRotation(rotation);
	//text.SetRotation(rotation);
}

////////////////////////////////
DKString DKTextButton::GetText()
{
	return text->GetString();
}

///////////////////////////////////////////
void DKTextButton::SetText(DKString string)
{
	text->SetString(string);
}

//////////////////////////////////////////////////////
void DKTextButton::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && 
	event->button.y >= draw.y && event->button.y <= draw.y+size.y
	/* && event->button.button == SDL_BUTTON_LEFT*/){
		DKDebug("DKTextButton clicked\n");
		OnTextButton(m_arg, this);
		SkipEvents();
	}
}

/////////////////////////////////////////////////
void DKTextButton::OnFingerDown(SDL_Event* event)
{
    if(NotVisible()){return;}
	//if(WrongWindow(event)){return;}

	int tX = (int)event->tfinger.x * (int)frame->size.x;
	int tY = (int)event->tfinger.y * (int)frame->size.y;
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){
		DKDebug("DKTextButton clicked\n");
		OnTextButton(m_arg, this);
		SkipEvents();
	}
}

////////////////////////////
void DKTextButton::Display()
{
	if(NotVisible()){return;}
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

	//glEnable(GL_SCISSOR_TEST);
	Display2DObjects(this);
	//glScissor(point.x,screenHeight-size.y-y_pos,size.x,size.y);
	//glDisable(GL_SCISSOR_TEST);

	glPopMatrix();
}