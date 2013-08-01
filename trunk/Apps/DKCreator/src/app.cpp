//// APP.CPP ////
//
//   APP ENTRY POINT
//   SDL / OPENGL || OPENGL ES 
//
//  ********** NOTES **********
//  *
//	*	We open a basic SDL window with an opengl context alike for all systems.
//  *   We use OpenGL or OpenGLES for the corosponding system.
//	*   We use SDL for Windowing system, events, threads, and file system.
//	*
//	*   SDL or other libraries will be used for other needed features. 
//	*
//
//
//  ********** TODO **********
//	*
//	*	Error handling
//  *   http://www.parashift.com/c++-faq-lite/exceptions.html
//  *
//	*
//	*
//
//  ********** TODO FUTURE APP TYPES **********
//	*	Terminate and Stay Resident (TSR) Apps.
//	*	DLL style apps like VSTs, RSTAs, and plugins.
//  *	Services
//	*	Drivers

#define INIT_LEAK_FINDER
#include "LeakFinder.h"

#include "MainWindow.h"
MainWindow *mainwindow;

////////////////////////////////
int main(int argc, char *argv[]) 
{
	DKDebug("DK App Started\n");
	mainwindow = new MainWindow("DK Creator",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,
		SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	mainwindow->Init();
	mainwindow->Loop(); //Create Main Loop
	delete mainwindow; //cleanup

	exit(0); //FIXME - we need to return a value according to a possible error.
}