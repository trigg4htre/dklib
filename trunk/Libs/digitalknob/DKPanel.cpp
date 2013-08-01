#include "DKPanel.h"

///////////////////////////////////////////////////////////
DKPanel::DKPanel(DKObject *parent, DKPoint pos, DKSize siz)
{
	Create(parent,pos,siz);
}

///////////////////////////////////////////////////////////////
void DKPanel::Create(DKObject *parent, DKPoint pos, DKSize siz)
{
	name = "DKPanel";
	par = parent;
	point = pos;
	size = siz;
	frame = par->frame;
	win = par->win;

	CalculateDraw();
	
	square = (DKSquare*)DKSquare::NewSquare(this, DKPoint(0,0), size);
	SetColor(DKColor(0,0,0,1));
	SetVisibility(true);
}

///////////////////
DKPanel::~DKPanel()
{

}

//////////////////////////////////////////////////////////////////////
DKObject* DKPanel::NewPanel(DKObject* parent, DKPoint pos, DKSize siz)
{
	objects.push_back(new DKPanel(parent, pos, siz));
	return objects[objects.size() - 1];
}

//////////////////////////////////////
void DKPanel::SetPosition(DKPoint pos)
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

/////////////////////////////////
void DKPanel::SetSize(DKSize siz)
{
	size = siz;
	square->SetSize(size);
}

//////////////////////////////////////////////////////////
void DKPanel::SetColor(float r, float g, float b, float a)
{
	color = DKColor(r,g,b,a);
	SetColor(color);
}


//////////////////////////////////////////////////////////
void DKPanel::SetColor(DKColor rgb)
{
	square->SetColor(rgb);
}

//////////////////////
void DKPanel::Center()
{
	point.x = par->size.x/2 - size.x/2;
	point.y = par->size.y/2 - size.y/2;
}

/*
/////////////////////////////////////////////////
void DKPanel::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y && event->button.button == SDL_BUTTON_LEFT){
		DKDebug("DKPanel clicked\n");
		SkipEvents();
	}
}

////////////////////////////////////////////
void DKPanel::OnFingerDown(SDL_Event* event)
{
    if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	int tX = event->tfinger.x * (int)frame->size.x / SDL_GetTouch(event->tfinger.touchId)->xres;
	int tY = event->tfinger.y * (int)frame->size.y / SDL_GetTouch(event->tfinger.touchId)->yres;
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){
		DKDebug("DKPanel clicked\n");
		SkipEvents();
	}
}
*/

///////////////////////
void DKPanel::Display()
{
	if(NotVisible()){return;}

	clip = true;
	if(clip == true){ DKClipStart(draw.x, draw.y, size.x, size.y, frame); }
	
	//We only update if an object asks us to. 
	//we must call Update() to refresh the frame. 
	if(update == true){

		//// Draw all 3D //////
		//Setup3D(size);
		//Display3DObjects(this);

		//// Draw all 2D //////
		//Setup2D(size);
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->dimensions == 2){
					objects[i]->Display();
			}
		}

		//update = false; //remember, you must call Update() to redraw.
	}

	if(clip == true){ DKClipEnd(); }
}