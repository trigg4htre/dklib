#include "DKMessage.h"


////////////////////////////////////////////////////////////////////////////////////////////
DKMessage::DKMessage(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, DKString text)
{
	Create(parent,pos,siz,font,text);
}

//////////////////////////////////////////////////////////////////////////////////////////////
void DKMessage::Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, DKString text)
{
	DKObject::Create(parent, "DKMessage");
	DKPanel::Create(parent, pos, siz);
	SetColor(DKColor(.5,.5,.5,1));
	string.Create(this, DKPoint(20,20),font,text);
	//button.Create(this, DKPoint(size.x/2,size.y-40),font,"OK");
	button.LinkTextButtonEvent(&TextButtonEvent, this, 1);
	SetVisibility(true);
}

///////////////////////
DKMessage::~DKMessage()
{

}

///////////////////////////////////////////////
void DKMessage::OnWindowClose(SDL_Event* event)
{
	//FIXME
	if(event->window.windowID == 1){
		delete this;
		return;
	}
}

////////////////////////////////////
void DKMessage::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		delete this;
	}
}