//// APP.CPP ////


#if defined (WIN32) && (DEBUG)
	#define INIT_LEAK_FINDER
	#include "LeakFinder.h"
#endif

#include "SDL.h"
#include "DKDebug.h"
#include "MainWindow.h"
MainWindow *mainwindow;

////////////////////////////////
int main(int argc, char *argv[]) 
{
	DKDebug("App Started\n");
	mainwindow = new MainWindow("DKBlank",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,
		SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	mainwindow->Init();
	mainwindow->Loop(); //Create Main Loop
	delete mainwindow; //cleanup

	exit(0); //FIXME - we need to return a value according to a possible error.
}