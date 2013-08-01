#include "DKScrollBar.h"

/////////////////////////////////////////////////////////
DKScrollBar::DKScrollBar(DKObject *parent, int direction)
{
	Create(parent, direction);
}

/////////////////////////////////////////////////////////
void DKScrollBar::Create(DKObject *parent, int direction)
{
	DKObject::Create(parent, "DKScrollBar");
	xy = direction;

	point.x = 0;
	point.y = 0;
	size.x = par->size.x;
	size.y = par->size.y;
	CalculateDraw();

	if(xy == 1){
		background.Create(this, DKPoint(0,size.y-16), DKSize(size.x, 16));
		background.SetColor(DKColor(0.5f,0.5f,0.5f,1));
		scroll_left.Create(this, DKPoint(0,size.y-16), scroll_left_xpm);
		scroll_left.LinkButtonEvent(ButtonEvent, this, 1);
		scroll_right.Create(this, DKPoint(size.x-32,size.y-16), scroll_right_xpm);
		scroll_right.LinkButtonEvent(ButtonEvent, this, 2);
		glide.Create(this, DKPoint(0,0), DKSize(0,0));
		glide.SetColor(DKColor(1,1,1,1));
	}
	if(xy == 2){
		background.Create(this, DKPoint(size.x-16,0), DKSize(16, size.y));
		background.SetColor(DKColor(0.5f,0.5f,0.5f,1));
		scroll_up.Create(this, DKPoint(size.x-16,0), scroll_up_xpm);
		scroll_up.LinkButtonEvent(ButtonEvent, this, 3);
		scroll_down.Create(this, DKPoint(size.x-16,size.y-32), scroll_down_xpm);
		scroll_down.LinkButtonEvent(ButtonEvent, this, 4);
		glide.Create(this, DKPoint(0,0), DKSize(0,0));
		glide.SetColor(DKColor(1,1,1,1));
	}
	
	dragging = false;
	SetVisibility(false);
}

///////////////////////////
DKScrollBar::~DKScrollBar()
{

}

/////////////////////////////////////////////////////
void DKScrollBar::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= glide.draw.x && event->button.x <= glide.draw.x+glide.size.x && event->button.y >= glide.draw.y && event->button.y <= glide.draw.y+glide.size.y && event->button.button == SDL_BUTTON_LEFT){
		DKDebug("ScrollBar glide clicked");
		drag_x = event->button.x;
		drag_y = event->button.y;
		dragging = true;
		SkipEvents();
	}
}

///////////////////////////////////////////////////
void DKScrollBar::OnMouseButtonUp(SDL_Event* event)
{
	dragging = false;
}

/////////////////////////////////////////////////
void DKScrollBar::OnMouseMotion(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(dragging == true){
		if(xy == 1){
			//glide.SetPosition(DKPoint(event->button.x - drag_x, glide.point.y, glide.point.z));
			value = drag_x - event->button.x;
			id2 = 5;
		}
		if(xy == 2){
			//glide.SetPosition(DKPoint(glide.point.x, event->button.y - drag_y, glide.point.z));
			value = drag_y - event->button.y;
			id2 = 6;
		}
		drag_x = event->button.x;
		drag_y = event->button.y;
		OnScrollBar(m_arg, this);
		SkipEvents();
	}
}

//////////////////////////////////////////
void DKScrollBar::OnButton(DKEvent* event)
{
	if(event->id == 1){
		DKDebug("Scroll left\n");
		id2 = event->id;
		OnScrollBar(m_arg, this);
	}
	if(event->id == 2){
		DKDebug("Scroll right\n");
		id2 = event->id;
		OnScrollBar(m_arg, this);
	}
	if(event->id == 3){
		DKDebug("Scroll up\n");
		id2 = event->id;
		OnScrollBar(m_arg, this);
	}
	if(event->id == 4){
		DKDebug("Scroll down\n");
		id2 = event->id;
		OnScrollBar(m_arg, this);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
void DKScrollBar::LinkScrollBarEvent(void (*ScrollBarEvent)(void*, DKEvent*), void* arg, int id)
{
	OnScrollBar = ScrollBarEvent;
	m_arg = arg;
	this->id = id;
}

////////////////////////////////////////////////
void DKScrollBar::UpdateGlide(int diff, int pos)
{
	//diff = innerPanel size - scrollpanel size
	//position = innerPanel position

	size.x = par->size.x;
	size.y = par->size.y;

	//FIXME - there should be a minimum size the scroll bar can be
	int xSize = (int)size.x-64-diff;
	int ySize = (int)size.y-64-diff;
	if(xSize < 1){xSize = 16;}
	if(ySize < 1){ySize = 16;}
	if(xy == 1){
		glide.SetSize(DKSize(xSize,16));
		glide.SetPosition(DKPoint(16-pos, size.y-16));
	}
	if(xy == 2){
		glide.SetSize(DKSize(16,ySize));
		glide.SetPosition(DKPoint(size.y-16, 16-pos));
	}
}

///////////////////////////
void DKScrollBar::Display()
{
	if(NotVisible()){return;}
	Display2DObjects(this);
}

