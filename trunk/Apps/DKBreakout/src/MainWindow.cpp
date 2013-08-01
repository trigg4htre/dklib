#include "MainWindow.h"


///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h), flags)
{

}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");

	font1.Create(this);
	
	title = new Title(this, 0, 0, (int)size.x, (int)size.y);

	SetColor(DKColor(0,0,0,1)); //Background color

	SDL_Delay(3000);
	level1 = new Level1(this,0,0,(int)size.x,(int)size.y);
	//Fullscreen(800, 600);
}

/////////////////////////
MainWindow::~MainWindow()
{	
	DKDebug("App Exited\n");
	SDL_Quit();
}

/////////////////////////////////////////////
void MainWindow::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		DKCamera::Rotate((DKFrame*)this, 1, 10000);
	}
}

////////////////////////////////
void MainWindow::OnButton(DKEvent* event)
{

}

////////////////////////////////
void MainWindow::OnToggle(DKEvent* event)
{

}

////////////////////////////////
void MainWindow::OnSlider(DKEvent* event)
{

}

/////////////////////////////////
void MainWindow::OnTextBox(DKEvent* event)
{

}