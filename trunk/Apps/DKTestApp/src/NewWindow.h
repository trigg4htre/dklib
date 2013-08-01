///// NewWindow.h /////
#ifndef NewWindow_H
#define NewWindow_H

#include "DK.h"

//////////////////////////////////
class NewWindow : public DKWindow
{
public:	
	NewWindow(){};
	NewWindow(DKObject *parent, DKString caption, int x, int y, int w, int h);
	void Create(DKObject *parent, DKString caption, int x, int y, int w, int h);
	~NewWindow();
	
	void OnTextButton(DKEvent* event);

	DKXyz xyz;
	DKTextButton button1;
};

#endif //NewWindow_H