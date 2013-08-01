#include "DKFps.h"

/////////////////////////////////////////////////////////
DKFps::DKFps(DKObject *parent, DKPoint pos, DKFont *font)
{
	Create(parent,pos,font);
}

///////////////////////////////////////////////////////////////
void DKFps::Create(DKObject *parent, DKPoint pos, DKFont *font)
{
	DKObject::Create(parent, "DKFps");
	point = pos;
	CalculateDraw();
	last_time = 0;
	frames = 0;
	fps = 0;

	text.Create(this,DKPoint(0,0),font, "FPS: ");
	text.SetColor(DKColor(1,0,0,1));
	SetVisibility(true);
}

///////////////
DKFps::~DKFps()
{

}

////////////////////////////////////
void DKFps::SetPosition(DKPoint pos)
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

////////////////////////////////////////
void DKFps::SetRotation(DKRotate rotate)
{
	rotation = rotate;
	text.SetRotation(rotation);
}

////////////////////
int DKFps::GetFps(){
	++frames;
	if((SDL_GetTicks() - last_time) >= 1000){
		fps = frames;
		last_time = SDL_GetTicks();
		frames = 0;
	}
	return fps;
}

/////////////////////
void DKFps::Display()
{
	text.SetString("FPS: " + toString(GetFps()));
	Display2DObjects(this);
}