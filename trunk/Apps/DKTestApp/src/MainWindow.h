///// MainWindow.h /////
#ifndef MainWindow_H
#define MainWindow_H

#include "DK.h"

//#include "NewWindow.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	~MainWindow();
	void Init();

	void OnTextButton(DKEvent* event);
	//void OnFileDialog(DKEvent* event);

	DKXyz xyz;
	DKFont font;
	DKFps fps;
	DKText text;
	DKImage image;
	DKTextButton button1;

};

#endif //MainWindow_H