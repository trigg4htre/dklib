#include "NewWindow.h"

////////////////////////////////////////////////////////////////////////////////////
NewWindow::NewWindow(DKObject *parent, DKString caption, int x, int y, int w, int h)
{
	Create(parent,caption,x,y,w,h);
}

//////////////////////////////////////////////////////////////////////////////////////
void NewWindow::Create(DKObject *parent, DKString caption, int x, int y, int w, int h)
{
	DKWindow::Create(parent, caption, DKPoint(x,y), DKSize(w,h));

	xyz.Create(this);
	button1.Create(this,DKPoint(10,10),DKFont::fonts[0], "Spin XYZ");
	button1.LinkTextButtonEvent(TextButtonEvent, this, 1);
}

///////////////////////
NewWindow::~NewWindow()
{
	
}

////////////////////////////////////
void NewWindow::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		DKCamera::Rotate(this,1,10000);
	}
}