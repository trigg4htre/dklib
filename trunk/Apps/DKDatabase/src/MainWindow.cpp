#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h),  flags)
{

}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");
}

/////////////////////////
MainWindow::~MainWindow()
{
	DKDebug("App Exited\n");
	SDL_Quit();
}