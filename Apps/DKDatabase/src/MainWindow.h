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
#include "DKDatabase.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	~MainWindow();
	void Init();
};

#endif //MainWindow_H