#include "DKFrame.h"

/////////////////////////////////////////////////////////////////////////
DKFrame::DKFrame(DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	Create(caption,pos,siz,flags);
}

/////////////////////////////////////////////////////////////////////////////
void DKFrame::Create(DKString caption, DKPoint pos, DKSize siz, Uint32 flags)
{
	DKDebug("DK App Started\n");
	DKObject::Create(NULL, "DKFrame");
	par = NULL;
#if defined (IOS) || (ANDROID)
		pos.x = 0;
		pos.y = 0;
		siz.x = 0;
		siz.y = 0;
		flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
#endif
#if defined (WIN32) || (WIN64) || (MAC) || (ANDROID) || (LINUX)
	//if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {return;}
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {return;}
#endif
#if defined (IOS)
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {return;}
#endif


#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
#if defined (ANDROID) || (IOS)
	fullscreen = true;
	SDL_GL_LoadLibrary(NULL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
#endif
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	//SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,        32);
    //SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,      8);
    //SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
    //SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,     8);
    //SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
    //SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);
	SDL_GL_SetSwapInterval(1); //sync with vsync if possible

	title = caption;
	point = pos;
	size = siz;
	win_flags = flags;
	fullscreen = false;
	//bpp = 16;

#if defined (IOS) || (ANDROID) || (WII) || (PS3) || (NDS) || (X360)
	SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    size.x = displayMode.w;
    size.y = displayMode.h;
	fullscreen = true;
#endif

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
	currTime = SDL_GetTicks();
	prevTime = 0;
	active = true;

	SetVisibility(true);
}

///////////////////
DKFrame::~DKFrame()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(win);
	SDL_Quit();
	DKDebug("DK App Exited\n");
}

void DKFrame::Delete()
{
	DKObject::Delete();
}

////////////////////////////////////////////////
void DKFrame::OnWindowClose(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	active = false;
}

///////////////////////////////////////////////
void DKFrame::OnWindowResized(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	size.x = (float)event->window.data1;
	size.y = (float)event->window.data2;
	//Update();
}

void DKFrame::OnWindowMoved(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	//Update();
}

////////////////////////////////////////////////
void DKFrame::OnWindowRestored(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	//Update();
}

//////////////////////////////////////
void DKFrame::OnQuit(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	active = false;
}

/////////////////////////////////////////
void DKFrame::OnKeyDown(SDL_Event* event)
{
	if(WrongWindow(event)){return;}
	if(event->key.keysym.sym == SDLK_AC_BACK){
		active = false; //FIXME - make this only hide and pause the app
	}
}

/*
//////////////////////////////////////////////////
void DKFrame::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y && event->button.button == SDL_BUTTON_LEFT){
		DKDebug("DKFrame clicked\n");
		SkipEvents();
	}
}

/////////////////////////////////////////////
void DKFrame::OnFingerDown(SDL_Event* event)
{
    if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	int tX = (int)(event->tfinger.x * frame->size.x / SDL_GetTouch(event->tfinger.touchId)->xres);
	int tY = (int)(event->tfinger.y * frame->size.y / SDL_GetTouch(event->tfinger.touchId)->yres);
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){
		DKDebug("DKFrame clicked\n");
		SkipEvents();
	}
}
*/

////////////////////
void DKFrame::Exit()
{
	active = false;
}

////////////////////////////////////
void DKFrame::SetIcon(DKString file)
{
#if defined (WIN32) || (WIN64)
	SDL_Surface* icon = IMG_Load(file.c_str());
	if(icon == NULL){
		return;
	}
	SDL_SetWindowIcon(win, icon);
#endif
}

//////////////////////////////////////
void DKFrame::SetPosition(DKPoint pos)
{
	point = pos;
	SDL_SetWindowPosition(win, (int)point.x, (int)point.y);
	Update();
}

/////////////////////////////////
void DKFrame::SetSize(DKSize siz)
{
	size = siz;
	Update();
}

////////////////////////////////////
void DKFrame::SetColor(DKColor rgba)
{
	color = rgba;
	glClearColor(color.r, color.g, color.b, color.a);
	Update();
}

///////////////////////////////////
void DKFrame::Center(DKSize screen)
{
	point.x = screen.x/2 - size.x/2;
	point.y = screen.y/2 - size.y/2;
}

////////////////////////////////////
void DKFrame::Fullscreen(DKSize siz)
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
void DKFrame::Windowed(DKSize siz)
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

////////////////////////
void DKFrame::Maximize()
{
	SDL_MaximizeWindow(win);
	//Update();
}

////////////////////////
void DKFrame::Minimize()
{
	SDL_MinimizeWindow(win);
	//Update();
}

///////////////////////
void DKFrame::Restore()
{
	SDL_RestoreWindow(win);
	//Update();
}

////////////////////
void DKFrame::Loop()
{
	//THIS IS IMPORTANT
	//
	// Everything is triggered by this loop.
	//  Time,Events,FPS Delay,Animation,Camera,Drawing, etc.
	//
	// Do NOT change this code unless you know what your doing.

	while(active){
		prevTime = currTime;
		currTime = SDL_GetTicks();

		//Limit frame rate at 60fps
		int delay = prevTime + 33 - currTime;
		if(delay > 0) SDL_Delay(delay);

		//Poll for events
		while(SDL_PollEvent(&event)){
			DoEvents(&event);
		}

		//Process Object movement and Camera movement.
		DKCamera::Animate();
		DKAnimate::Animate();

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
				if(objects[i]->par == this && objects[i]->name != "DKWindow" && objects[i]->dimensions == 2){
					objects[i]->Display();
				}
			}

			SDL_GL_SwapWindow(win);

			//Display all objects for child DKWindows
			for(unsigned int i=0; i<objects.size(); ++i){
				if(objects[i]->par == this && objects[i]->name == "DKWindow" && objects[i]->dimensions == 2){
					objects[i]->Display();
				}
			}

			update = false; //remember, you must call Update() to redraw.
		}
	}
}