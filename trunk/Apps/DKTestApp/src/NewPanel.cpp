#include "NewPanel.h"

////////////////////////////////////////////////////////////////
NewPanel::NewPanel(DKObject *parent, int x, int y, int w, int h)
	: DKPanel(parent,DKPoint(x,y),DKSize(w,h))
{
	DKDebug("NewPanel initiated\n");

	SetColor(DKColor(0.1f,0.1f,0.1f,1));
	text1.Create(this,DKPoint(0,0),DKFont::fonts[0],"New Window");
	button1.Create(this,DKPoint(20,20),DKFile::DataPath("newwindow.png"));
	button1.LinkButtonEvent(&ButtonEvent, this, 1);
	text2.Create(this,DKPoint(30,145),DKFont::fonts[0],"New Window");

	button2.Create(this,DKPoint(150,20),DKFile::DataPath("newpanel.png"));
	button2.LinkButtonEvent(&ButtonEvent, this, 2);
	text3.Create(this,DKPoint(160,145),DKFont::fonts[0],"New Panel");

	button3.Create(this,DKPoint(size.x-18,0.0f),DKFile::DataPath("close.png"));
	button3.LinkButtonEvent(&ButtonEvent, this, 3);

	button4.Create(this,DKPoint(20,200),DKFont::fonts[0],"Move left 10");
	button4.LinkTextButtonEvent(&TextButtonEvent, this, 1);
}

/////////////////////
NewPanel::~NewPanel()
{
	
}

//////////////////////////////////////////////
void NewPanel::OnWindowClose(SDL_Event* event)
{
	//FIXME
	if(event->window.windowID == 1){
		delete this;
		return;
	}
}

///////////////////////////////////////////
void NewPanel::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		SetPosition(DKPoint(point.x-10,point.y,point.z));
	}
}

///////////////////////////////
void NewPanel::OnButton(DKEvent* event)
{
	if(event->id == 1){
		newWindow = new NewWindow(this, "New Window", 100, 100, 300, 300);
	}
	if(event->id == 2){
		newPanel = new NewPanel(this, 100,100,300,300);
	}
	if(event->id == 3){
		delete this;
	}
}

///////////////////////////////
void NewPanel::OnToggle(DKEvent* event)
{

}

///////////////////////////////
void NewPanel::OnSlider(DKEvent* event)
{

}

////////////////////////////////
void NewPanel::OnTextBox(DKEvent* event)
{

}