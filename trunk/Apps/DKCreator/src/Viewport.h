///// Viewport.h /////

#ifndef Viewport_H
#define Viewport_H

#include "DK.h"


///////////////////////////////
class Viewport : public DKPanel
{
public:	
	Viewport(){};
	Viewport(DKObject *parent, int x, int y, int w, int h);
	void Create(DKObject *parent, int x, int y, int w, int h);
	~Viewport();

	std::vector<DKObject*> v_objects; //keep a pointer to all objects

	void OnTextButton(DKEvent* event);
	void OnDropDown(DKEvent* event);
	void OnColorPicker(DKEvent* event);
	void OnFileDialog(DKEvent* event);
	void OnKeyDown(SDL_Event* event);
	void OnKeyUp(SDL_Event* event);
	void OnMouseButtonUp(SDL_Event* event);
	void OnMouseMotion(SDL_Event* event);

	void NewSquare(int x, int y);
	void NewCircle(int x, int y);
	void NewText(int x, int y);
	void NewTextButton(int x, int y);
	void NewImage(DKString file);
	void Delete(unsigned int object_number);
	void BringForward(unsigned int object_number);
	void SendBackward(unsigned int object_number);
	void BringToFront(unsigned int object_number);
	void SendToBack(unsigned int object_number);

	DKDropDown main_drop;
	DKDropDown object_drop;
	DKDropDown button_drop;
	DKDropDown circle_drop;
	DKDropDown image_drop;
	DKDropDown line_drop;
	DKDropDown listbox_drop;
	DKDropDown text_drop;
	DKDropDown textbox_drop;
	DKDropDown textbutton_drop;
	DKDropDown toggle_drop;
	DKDropDown triange_drop;
	DKDropDown square_drop;
	
	DKScrollPanel scroll_panel;
	DKImage scroll_image;

	int drag_x;
	int drag_y;
	DKObject *dragging;
	int size_x;
	int size_y;
	DKObject *resizeing;
	int rot_z;
	DKObject *rotating;


	int current_object;
};

#endif //Viewport_H