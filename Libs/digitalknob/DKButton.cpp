#include "DKButton.h"
#include "DKWindow.h"

/////////////////////////////////////////////////////////////////////////////
DKButton::DKButton(DKObject *parent, DKPoint pos, DKString file, int eventID)
{
	Create(parent,pos,file,eventID);
}

/////////////////////////////////////////////////////////////////////////
DKButton::DKButton(DKObject *parent, DKPoint pos, const char* const* xpm)
{
	Create(parent,pos,xpm);
}

////////////////////////////////////////////////////////////////////
void DKButton::Create(DKObject *parent, DKPoint pos, DKString file, int eventID)
{
	if(!DKFile::FileExists(file)){
		DKDebug("Image File Does Not Exist\n");
		return;
	}
	name = "DKButton";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	CalculateDraw();
	//image.Create(this, DKPoint(0,0), file);
	image = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), file);
	size.x = image->size.x;
	size.y = image->size.y;
	LinkButtonEvent(ButtonEvent, par, eventID);
	SetVisibility(true);
}

////////////////////////////////////////////////////////////////////////////
void DKButton::Create(DKObject *parent, DKPoint pos, const char* const* xpm)
{
	name = "DKButton";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	CalculateDraw();
	//image = (DKImage*)DKImage::NewImage(this, DKPoint(0,0), xpm);
	size.x = image->size.x;
	size.y = image->size.y;
	SetVisibility(true);
}

/////////////////////
DKButton::~DKButton()
{

}

///////////////////////////////////////////////////////////////////////////////////
DKObject* DKButton::NewButton(DKObject *parent, DKPoint pos, DKString file, int eventID)
{
	objects.push_back(new DKButton(parent, pos, file, eventID));
    return objects[objects.size() - 1];
}

////////////////////////////////////////
void DKButton::SetFile(DKString file)
{
	image->SetFile(file);
	size.x = image->size.x;
	size.y = image->size.y;
}

///////////////////////////////////////
void DKButton::SetPosition(DKPoint pos)
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
void DKButton::SetSize(DKSize siz)
{
	size = siz;
	image->SetSize(size);
}

/////////////////////////////////////
void DKButton::SetScale(DKScale scal)
{
	scale = scal;
	//image.SetScale(scale);
}

///////////////////////
void DKButton::Reload()
{
	image->Reload();
}

///////////////////////////////////////////////////////////////////////////////////////
void DKButton::LinkButtonEvent(void (*ButtonEvent)(void*, DKEvent*), void* arg, int id)
{
	OnButton = ButtonEvent;
	m_arg = arg;
	this->id = id;
}

//////////////////////////////////////////////////
void DKButton::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y && event->button.button == SDL_BUTTON_LEFT){
		
		Uint8 r,g,b,a;
		Uint32 pixel = image->GetPixel(event->button.x - (int)draw.x, event->button.y - (int)draw.y);
		SDL_GetRGBA(pixel, image->surface->format, &r, &g, &b, &a);

		if(a > 0){ //if pixel is not completley transparent
			DKDebug("DKButton clicked\n");
			OnButton(m_arg, this);
			SkipEvents();
		}
	}
}

/////////////////////////////////////////////
void DKButton::OnFingerDown(SDL_Event* event)
{
    if(NotVisible()){return;}

	//TODO - we need to determin if the pixel clicked is transparent.

	int tX = (int)event->tfinger.x * (int)frame->size.x;
	int tY = (int)event->tfinger.y * (int)frame->size.y;
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){

		Uint8 r,g,b,a;
		Uint32 pixel = image->GetPixel(tX - (int)draw.x, tY - (int)draw.y);
		SDL_GetRGBA(pixel, image->surface->format, &r, &g, &b, &a);

		if(a > 0){ //if pixel is not completley transparent
			DKDebug("DKButton clicked\n");
			OnButton(m_arg, this);
			SkipEvents();
		}
	}
}

////////////////////////
void DKButton::Display()
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

	Display2DObjects(this);
	glPopMatrix();
}