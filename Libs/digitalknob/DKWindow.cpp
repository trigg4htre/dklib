#include "DKWindow.h"


#ifdef DESKTOP
/////////////////////////////////////////////////////////////////////////////////////////////
DKWindow::DKWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	Create(parent, caption,pos,siz,flags);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void DKWindow::Create(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	name = "DKWindow";
	par = parent;
	frame = this;
	title = caption;
	point = pos;
	size = siz;
	win_flags = flags;
	fullscreen = false;
	//bpp = 16;

	win = SDL_CreateWindow(title.c_str(),(int)point.x,(int)point.y,(int)size.x,(int)size.y,win_flags);
	context = SDL_GL_CreateContext(win);

	int x,y;
	SDL_GetWindowPosition(win, &x, &y);
	point.x = (float)x;
	point.y = (float)y;
	int w,h;
    SDL_GetWindowSize(win, &w, &h);
	size.x = (float)w;
	size.y = (float)h;

	SetIcon("icon.ico");

	SetColor(DKColor(0,0,0,1)); //Background color

	SetVisibility(true);
}

/////////////////////
DKWindow::~DKWindow()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKWindow::NewWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	objects.push_back(new DKWindow(parent, caption, pos, siz, flags));
	return objects[objects.size() - 1];
}

//////////////////////////////////////////////
void DKWindow::OnWindowClose(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
}

void DKWindow::OnWindowMoved(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	//Update();
}

////////////////////////////////////////////////
void DKWindow::OnWindowResized(SDL_Event* event)
{
	if(WrongWindow(event)){return;}

	size.x = (float)event->window.data1;
	size.y = (float)event->window.data2;
	//Update();
}

/////////////////////////////////////////////////
void DKWindow::OnWindowRestored(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	//Update();
}

///////////////////////////////////////
void DKWindow::OnQuit(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
}

//////////////////////////////////////////
void DKWindow::OnKeyDown(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
}

/////////////////////////////////////
void DKWindow::SetIcon(DKString file)
{
#if defined (WIN32) || (WIN64)
	SDL_Surface* icon = IMG_Load(file.c_str());
	if(icon == NULL){
		return;
	}
	SDL_SetWindowIcon(win, icon);
#endif
}

///////////////////////////////////////
void DKWindow::SetPosition(DKPoint pos)
{
	point = pos;
	SDL_SetWindowPosition(win, (int)point.x, (int)point.y);
	//Update();
}

//////////////////////////////////
void DKWindow::SetSize(DKSize siz)
{
	size = siz;
	//Update();
}

/////////////////////////////////////
void DKWindow::SetColor(DKColor rgba)
{
	color = rgba;
	glClearColor(color.r, color.g, color.b, color.a);
	Update();
}

////////////////////////////////////
void DKWindow::Center(DKSize screen)
{
	point.x = screen.x/2 - size.x/2;
	point.y = screen.y/2 - size.y/2;
}

/////////////////////////////////////
void DKWindow::Fullscreen(DKSize siz)
{
#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	if(siz.x > 0 && siz.y > 0 && fullscreen == false){
		size = siz;
	}
	SDL_SetWindowFullscreen(win, SDL_TRUE);
	fullscreen = true;
	//Update();
#endif
}

//////////////////////////////////
void DKWindow::Windowed(DKSize siz)
{
#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	if(siz.x > 0 && siz.y > 0 && fullscreen == true){
		size = siz;
	}
	SDL_SetWindowFullscreen(win, SDL_FALSE);
	SDL_ShowWindow(win);
	fullscreen = false;
	//Update();
#endif
}

/////////////////////////
void DKWindow::Maximize()
{
	SDL_MaximizeWindow(win);
	//Update();
}

/////////////////////////
void DKWindow::Minimize()
{
	SDL_MinimizeWindow(win);
	//Update();
}

////////////////////////
void DKWindow::Restore()
{
	SDL_RestoreWindow(win);
	//Update();
}

////////////////////////
void DKWindow::Display()
{
	//We only update if an object asks us to. 
	//we must call Update() to refresh the frame. 
	if(update == true){
		SDL_GL_MakeCurrent(win, context);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//// Draw all 3D //////
		Setup3D(size);
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->name != "DKWindow" && objects[i]->dimensions == 3){
				objects[i]->Display();
			}
		}

		//// Draw all 2D //////
		Setup2D(size);
		for(unsigned int i=0; i<objects.size(); ++i){
			if(objects[i]->par == this && objects[i]->dimensions == 2){
					objects[i]->Display();
			}
		}

		SDL_GL_SwapWindow(win);
		//update = false; //remember, you must call Update() to redraw.
	}
}

#endif //DESKTOP



#ifdef DEVICE
/////////////////////////////////////////////////////////////////////////////////////////////
DKWindow::DKWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	Create(parent,caption,pos,siz,flags);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void DKWindow::Create(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	name = "DKPanel";
	par = parent;
	title = caption;
	point = pos;
	size = siz;
	win_flags = flags;
	frame = par->frame;
	win = par->win;
	//bpp = 16;

	CalculateDraw();

	SetColor(DKColor(0,0,0,1)); //Background color

	square = (DKSquare*)DKSquare::NewSquare(this, DKPoint(0,0), size);
	SetVisibility(true);
}

/////////////////////
DKWindow::~DKWindow()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKWindow::NewWindow(DKObject* parent, DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	objects.push_back(new DKWindow(parent, caption, pos, siz, flags));
	return objects[objects.size() - 1];
}

///////////////////////
void DKWindow::Display()
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


#endif //DEVICE