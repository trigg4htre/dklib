///// NewPanel.h /////
#ifndef NewPanel_H
#define NewPanel_H

#include "DK.h"

#include "NewWindow.h"

///////////////////////////////
class NewPanel : public DKPanel
{
public:	
	NewPanel(){};
	NewPanel(DKObject *parent, int x, int y, int w, int h);
	void Create(DKObject *parent, int x, int y, int w, int h);
	~NewPanel();

	void OnWindowClose(SDL_Event* event);
	void OnTextButton(DKEvent* event);
	void OnButton(DKEvent* event);
	void OnToggle(DKEvent* event);
	void OnSlider(DKEvent* event);
	void OnTextBox(DKEvent* event);

	DKXyz xyz;
	DKText text1;
	DKButton button1;
	DKText text2;
	DKButton button2;
	DKText text3;
	DKButton button3;
	DKTextButton button4;

	NewWindow *newWindow;
	NewPanel *newPanel;
};

#endif //NewPanel_H