#include "DKColorPicker.h"

///////////////////////////////////////////////////////////
DKColorPicker::DKColorPicker(DKObject *parent, int eventID)
{
	Create(parent, eventID);
}

/////////////////////////////////////////////////////////
void DKColorPicker::Create(DKObject *parent, int eventID)
{
	name = "DKColorPicker";
	par = parent;
	frame = par->frame;
	
	thiswin = (DKWindow*)DKWindow::NewWindow(parent, "Choose a color", DKPoint(parent->size.x/2-205,parent->size.y/2-140), DKSize(460,280), SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	thiswin->SetColor(DKColor(0.5f,0.5f,0.5f,1));
	win = thiswin->win;

	font = (DKFont*)DKFont::NewFont(thiswin);
	palette = (DKImage*)DKImage::NewImage(thiswin, DKPoint(10,10), colorpalette_xpm);
	alpha = (DKImage*)DKImage::NewImage(thiswin, DKPoint(310,10), DKFile::DataPath("alpha.png"));
	checkers1 = (DKImage*)DKImage::NewImage(thiswin,DKPoint(350,10),checkers_xpm);
	current_color = (DKSquare*)DKSquare::NewSquare(thiswin, DKPoint(350,10), DKSize(100,100));
	checkers2 = (DKImage*)DKImage::NewImage(thiswin,DKPoint(350,120),checkers_xpm);
	selected_color = (DKSquare*)DKSquare::NewSquare(thiswin, DKPoint(350,120), DKSize(100,100));
	ok = (DKTextButton*)DKTextButton::NewTextButton(thiswin, DKPoint(380,250), font, "OK", 1);
	ok->LinkTextButtonEvent(TextButtonEvent, this, 1);

	LinkColorPickerEvent(ColorPickerEvent, par, eventID);
	SetVisibility(true);
}

///////////////////////////////
DKColorPicker::~DKColorPicker()
{

}

//////////////////////////////////////////////////////////////////////
DKObject* DKColorPicker::NewColorPicker(DKObject *parent, int eventID)
{
	objects.push_back(new DKColorPicker(parent, eventID));
    return objects[objects.size() - 1];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void DKColorPicker::LinkColorPickerEvent(void (*ColorPickerEvent)(void*, DKEvent* event), void* arg, int id)
{
	OnColorPicker = ColorPickerEvent;
	m_arg = arg;
	this->id = id;
}


////////////////////////////////////////
DKColor DKColorPicker::GetCurrentColor()
{
	return selected_color->color; 
}

////////////////////////////////////////////////
void DKColorPicker::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		delete thiswin;
		delete this;
		Update();
	}
}


///////////////////////////////////////////////////
void DKColorPicker::OnWindowClose(SDL_Event* event)
{
	//If we closed this window or the main windows, delete this
	//if(event->window.windowID == 1 || SDL_GetWindowID(win) == event->window.windowID){
		delete thiswin;
		delete this;
		Update();
	//}
}


///////////////////////////////////////////////////////
void DKColorPicker::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	//if(WrongWindow(event)){return;}

	if(event->button.x >= palette->draw.x && event->button.x < palette->draw.x+palette->size.x 
	&& event->button.y > palette->draw.y && event->button.y <= palette->draw.y+palette->size.y 
	&& event->button.button == SDL_BUTTON_LEFT){
		Uint8 r,g,b,a;
		Uint32 pixel = palette->GetPixel(event->button.x - (int)palette->draw.x, event->button.y - (int)palette->draw.y);
		SDL_GetRGBA(pixel, palette->surface->format, &r, &g, &b, &a);
		
		//FIXME - some black colors are off
		float r_color = (float)r/256;
		float g_color = (float)g/256;
		float b_color = (float)b/256;
		
		selected_color->SetColor(DKColor(r_color,g_color,b_color,selected_color->color.a));
		OnColorPicker(m_arg, this);
		SkipEvents();
		Update();
		return;
	}

	if(event->button.x >= alpha->draw.x && event->button.x < alpha->draw.x+alpha->size.x
	&& event->button.y > alpha->draw.y && event->button.y <= alpha->draw.y+alpha->size.y 
	&& event->button.button == SDL_BUTTON_LEFT){
		
		Uint8 r,g,b,a;
		Uint32 pixel = alpha->GetPixel(event->button.x - (int)alpha->draw.x, event->button.y - (int)alpha->draw.y);
		SDL_GetRGBA(pixel, alpha->surface->format, &r, &g, &b, &a);
		float alph = (float)a/256;
		if(a<1){alph = 1;}

		selected_color->SetColor(DKColor(selected_color->color.r,selected_color->color.g,selected_color->color.b,alph));
		OnColorPicker(m_arg, this);
		SkipEvents();
		Update();
		return;
	}
	//thiswin.OnMouseButtonDown(event);
}

///////////////////////////////////////////////////
void DKColorPicker::OnMouseMotion(SDL_Event* event)
{
	if(NotVisible()){return;}
	//if(WrongWindow(event)){return;}
	
	if(event->button.x >= palette->draw.x && event->button.x < palette->draw.x+palette->size.x
	&& event->button.y > palette->draw.y && event->button.y <= palette->draw.y+palette->size.y){
		Uint8 r,g,b,a;
		Uint32 pixel = palette->GetPixel(event->button.x - (int)palette->draw.x, event->button.y - (int)palette->draw.y);
		SDL_GetRGBA(pixel, palette->surface->format, &r, &g, &b, &a);
		
		//FIXME - some black colors are off
		float r_color = (float)r/256;
		float g_color = (float)g/256;
		float b_color = (float)b/256;

		current_color->SetColor(DKColor(r_color,g_color,b_color,selected_color->color.a));
		SkipEvents();
		Update();
		return;
	}

	if(event->button.x >= alpha->draw.x && event->button.x < alpha->draw.x+alpha->size.x
	&& event->button.y > alpha->draw.y && event->button.y <= alpha->draw.y+alpha->size.y){
		Uint8 r,g,b,a;
		Uint32 pixel = alpha->GetPixel(event->button.x - (int)alpha->draw.x, event->button.y - (int)alpha->draw.y);
		SDL_GetRGBA(pixel, alpha->surface->format, &r, &g, &b, &a);
		float alph = (float)a/256;
		if(a<1){alph = 1;}
		
		current_color->SetColor(DKColor(selected_color->color.r,selected_color->color.g,selected_color->color.b,alph));
		SkipEvents();
		Update();
		return;
	}
	//thiswin->OnMouseMotion(event);
}
