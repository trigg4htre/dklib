#include "DKScrollPanel.h"

///////////////////////////////////////////////////////////////////////
DKScrollPanel::DKScrollPanel(DKObject *parent, DKPoint pos, DKSize siz)
{
	Create(parent, pos, siz);
}

/////////////////////////////////////////////////////////////////////
void DKScrollPanel::Create(DKObject *parent, DKPoint pos, DKSize siz)
{
	name = "DKPanel";
	par = parent;
	point = pos;
	size = siz;
	frame = par->frame;
	win = par->win;

	SetColor(DKColor(1,1,1,1));

	CalculateDraw();

	SetVisibility(true);

	scroll_x.Create(this,1);
	scroll_x.LinkScrollBarEvent(ScrollBarEvent, this, 1);
	scroll_y.Create(this,2);
	scroll_y.LinkScrollBarEvent(ScrollBarEvent, this, 2);
}

///////////////////////////////
DKScrollPanel::~DKScrollPanel()
{

}

//////////////////////////////////////////////////////////////////////////////////
DKObject* DKScrollPanel::NewScrollPanel(DKObject *parent, DKPoint pos, DKSize siz)
{
	objects.push_back(new DKScrollPanel(parent, pos, siz));
    return objects[objects.size() - 1];
}

///////////////////////////////////////////////////////
void DKScrollPanel::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	//Skipevent for everything outside of scrollpanel?
	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y){
		//int i = 0;
		SkipEvents();
	}
	else{

	}
}

///////////////////////////////////////////////
void DKScrollPanel::OnScrollBar(DKEvent* event)
{
	if(event->id2 == 1){ //scroll left
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				if(objects[i]->point.x < 0){
					objects[i]->SetPosition(DKPoint(objects[i]->point.x+1, objects[i]->point.y));
				}
			}
		}
	}
	if(event->id2 == 2){ //scroll right
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				if(objects[i]->point.x > size.x-objects[i]->size.x-16){
					objects[i]->SetPosition(DKPoint(objects[i]->point.x-1, objects[i]->point.y));
				}
			}
		}
	}
	if(event->id2 == 3){ //scroll up
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				if(objects[i]->point.y < 0){
					objects[i]->SetPosition(DKPoint(objects[i]->point.x, objects[i]->point.y+1));
				}
			}
		}
	}
	if(event->id2 == 4){ //scroll down
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				if(objects[i]->point.y > size.y-objects[i]->size.y-16){
					objects[i]->SetPosition(DKPoint(objects[i]->point.x, objects[i]->point.y-1));
				}
			}
		}
	}
	if(event->id2 == 5){ //glide x
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				
				int x = (int)objects[i]->point.x + event->value;
				if(x < 1 && x > size.x-objects[i]->size.x-17){
					objects[i]->SetPosition(DKPoint(x, objects[i]->point.y));
				}

			}
		}
	}
	if(event->id2 == 6){ //glide y
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name.compare("DKScrollBar") != 0){
				int y = (int)objects[i]->point.y + event->value;
				if(y < 1 && y > size.y-objects[i]->size.y-17){
					objects[i]->SetPosition(DKPoint(objects[i]->point.x, y));
				}

			}
		}
	}
	
}

/////////////////////////////
void DKScrollPanel::Display()
{
	//Display DKScrollPanel clipped.

	// 1. Display inner panel by position clipped
	// clip
	// inner_panel.Display();
	// endclip

	// 2. Display scrollbars
	// Get DKScrollPanel width/height and inner_panel width/height/position
	// Create scrollbars acordingly. Set their position. Accept scrollbar events.
	// Do updates, restart.

	if(NotVisible()){return;}	

	clip = true;
	if(clip == true){ DKClipStart(draw.x, draw.y, size.x, size.y, frame); }
	Display2DObjects(this); //This draws the scrollbars too..  don't need that to happen here.
	if(clip == true){ DKClipEnd(); }

	//are the contents bigger than the ScrollPanel
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this){
			if(objects[i]->size.x > size.x){
				scroll_x.SetVisibility(true);
				scroll_x.UpdateGlide((int)objects[i]->size.x-(int)size.x,(int)objects[i]->point.x);
				scroll_x.Display();
			}
			if(objects[i]->size.y > size.y){
				scroll_y.SetVisibility(true);
				scroll_y.UpdateGlide((int)objects[i]->size.y-(int)size.y,(int)objects[i]->point.y);
				scroll_y.Display();
			}
		}
	}
}