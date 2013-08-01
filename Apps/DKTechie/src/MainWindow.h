///// MainWindow.h /////
//
//  Simple APP to prove an OpenGL or OpenGLES context with SDL events. 
//  press a key to change OPENGL background color

#pragma once
#ifndef MainWindow_H
#define MainWindow_H

#include "SDL.h"
#include "DKDebug.h"
#include "DKFile.h"
#include "DKFrame.h"
#include "DKFont.h"
#include "DKText.h"
#include "DKOsInfo.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	~MainWindow();
	void Init();

	DKFont font;
	DKText title;

	DKText os_company;
	DKText os_name;
	DKText os_version;
	DKText os_servicepack;
	DKText os_build;
	DKText os_architecture;
	DKText gl_vendor;
	DKText gl_renderer;
	DKText gl_version;
};

#endif //MainWindow_H