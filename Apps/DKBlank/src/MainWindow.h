///// MainWindow.h /////
//
//  Simple APP to prove an OpenGL or OpenGLES context with SDL events. 
//  press a key to change OPENGL background color

#pragma once
#ifndef MainWindow_H
#define MainWindow_H

#include "SDL.h"
#include "DK.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	virtual ~MainWindow();
	void Init();

	void OnButton(DKEvent* event);
	void OnTextButton(DKEvent* event);
	void OnColorPicker(DKEvent* event);
	void OnToggle(DKEvent* event);
	void OnSlider(DKEvent* event);
	void OnMenuBar(DKEvent* event);
	void OnDropDown(DKEvent* event);
};

#endif //MainWindow_H