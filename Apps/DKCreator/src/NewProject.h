///// NewProject.h /////

#ifndef NewProject_H
#define NewProject_H

#include "DK.h"

//////////////////////////////////
class NewProject : public DKWindow
{
public:	
	NewProject(DKObject *parent, float x, float y, float w, float h);
	~NewProject();

	void OnTextButton(DKEvent* event);
	void OnFileDialog(DKEvent* event);

	DKFont font;
	DKText text1;
	DKText text2;
	DKText path;
	DKTextButton button1;
	DKTextBox name;
	DKTextButton button2;

};

#endif //NewProject_H