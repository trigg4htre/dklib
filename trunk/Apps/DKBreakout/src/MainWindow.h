///// MainWindow.h /////
#ifndef MainWindow_H
#define MainWindow_H

#include "DK.h"

#include "Title.h"
#include "Level1.h"

/////////////////////////////////
class MainWindow : public DKFrame
{
public:	
	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);
	~MainWindow();
	void Init();

	void OnTextButton(DKEvent* event);
	void OnButton(DKEvent* event);
	void OnToggle(DKEvent* event);
	void OnSlider(DKEvent* event);
	void OnTextBox(DKEvent* event);

	DKFont font1;
	Title *title;
	Level1 *level1;
};

#endif //MainWindow_H