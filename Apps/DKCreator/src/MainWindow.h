///// MainWindow.h /////

#ifndef MainWindow_H
#define MainWindow_H

#include "DK.h"

#include "NewProject.h"
#include "Viewport.h"
#include "SourceCode.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	~MainWindow();
	void Init();

	void OnMenuBar(DKEvent* event);
	void OnButton(DKEvent* event);
	void OnTextButton(DKEvent* event);

	DKFont font;
	DKObjectManager dko;
	DKMenuBar menu;
	DKButton windows;
	DKButton mac;
	DKButton linux;
	DKButton android;
	DKButton iphone;
	DKTextButton fs;
	
	Viewport viewport;
	NewProject *new_project;
};

#endif //MainWindow_H