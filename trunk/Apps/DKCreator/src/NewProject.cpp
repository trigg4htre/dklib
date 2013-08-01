#include "NewProject.h"

////////////////////////////////////////////////////////////////////////////
NewProject::NewProject(DKObject *parent, float x, float y, float w, float h)
	: DKWindow(parent, "New Project", DKPoint(x,y), DKSize(w,h))
{
	DKDebug("NewPanel initiated\n");
	SetColor(DKColor(.5,.5,.5,1));

	font.Create(this);

	text1.Create(this, DKPoint(20,20),&font, "Project Name");
	name.Create(this,DKPoint(140,16),DKSize(200,20),&font);
	name.LinkTextBoxEvent(TextBoxEvent,this,1);

	text2.Create(this, DKPoint(30,40),&font, "Location");
	path.Create(this, DKPoint(140,40),&font, "");
	button1.Create(this, DKPoint(250,40), &font, "Choose");
	button1.LinkTextButtonEvent(TextButtonEvent, this, 1);

	button2.Create(this, DKPoint(250,150), &font, "OK");
	button2.LinkTextButtonEvent(TextButtonEvent, this, 2);
}

/////////////////////////
NewProject::~NewProject()
{
	
}

/////////////////////////////////////////////
void NewProject::OnTextButton(DKEvent* event)
{
	if(event->id == 1){ //choose
		DKFileDialog *fd = new DKFileDialog(this);
		fd->LinkFileDialogEvent(FileDialogEvent, this, 1);
	}
	if(event->id == 2){ //ok
		//send event
		delete this;
	}
}

/////////////////////////////////////////////
void NewProject::OnFileDialog(DKEvent* event)
{
	DKDebug( ((DKFileDialog*)event)->full_path );
}