///// DKEvent.h /////

#pragma once
#ifndef DKEvent_H
#define DKEvent_H

#include "SDL.h"
#include "DKObject.h"

#include <vector>
using namespace std;

///////////////////////////////
class DKEvent : public DKObject
{
public:
	DKEvent();
	~DKEvent();

	static void DoEvents(SDL_Event* event);
	static void SkipEvents();
	
	static std::vector<DKEvent*> events; //keep a pointer to all event objects
	static bool skip_events;

	//we can pass DKEvent as a pointer to all recieving events.
	//id is the primary variable passed.
	int id;
	int id2;
	unsigned int value;
	//DKColor color;
	//DKPoint point;


	SDL_Event event;
	virtual void OnEvent(SDL_Event* event);
	virtual void OnWindowShown(SDL_Event* event){Update();};
	virtual void OnWindowHidden(SDL_Event* event){Update();};
	virtual void OnWindowExposed(SDL_Event* event){Update();};
	virtual void OnWindowMoved(SDL_Event* event){Update();};
	virtual void OnWindowResized(SDL_Event* event){Update();};
	virtual void OnWindowSizeChanged(SDL_Event* event){Update();};
	virtual void OnWindowMinimized(SDL_Event* event){Update();};
	virtual void OnWindowMaximized(SDL_Event* event){Update();};
	virtual void OnWindowRestored(SDL_Event* event){Update();};
	virtual void OnWindowEnter(SDL_Event* event){};
	virtual void OnWindowLeave(SDL_Event* event){};
	virtual void OnWindowFocusGained(SDL_Event* event){Update();};
	virtual void OnWindowFocusLost(SDL_Event* event){Update();};
	virtual void OnWindowClose(SDL_Event* event){Update();};
	virtual void OnKeyUp(SDL_Event* event){};
	virtual void OnKeyDown(SDL_Event* event){};
	virtual void OnTextEdit(SDL_Event* event){};
	virtual void OnTextInput(SDL_Event* event){};
	virtual void OnMouseMotion(SDL_Event* event){};
	virtual void OnMouseButtonDown(SDL_Event* event){};
	virtual void OnMouseButtonUp(SDL_Event* event){};
	virtual void OnMouseWheel(SDL_Event* event){};
	virtual void OnJoyAxisMotion(SDL_Event* event){};
	virtual void OnJoyBallMotion(SDL_Event* event){};
	virtual void OnJoyHatMotion(SDL_Event* event){};
	virtual void OnJoyButtonDown(SDL_Event* event){};
	virtual void OnJoyButtonUp(SDL_Event* event){};
	virtual void OnInputMotion(SDL_Event* event){};
	virtual void OnInputButtonDown(SDL_Event* event){};
	virtual void OnInputButtonUp(SDL_Event* event){};
	virtual void OnInputWheel(SDL_Event* event){};
	virtual void OnInputProximityIn(SDL_Event* event){};
	virtual void OnInputProximityOut(SDL_Event* event){};
	virtual void OnQuit(SDL_Event* event){};
	virtual void OnUserEvent(SDL_Event* event){};
	virtual void OnSysWMEvent(SDL_Event* event){};
	virtual void OnFingerMotion(SDL_Event* event){};
	virtual void OnFingerDown(SDL_Event* event){};
	virtual void OnFingerUp(SDL_Event* event){};
	virtual void OnTouchButtonDown(SDL_Event* event){};
	virtual void OnTouchButtonUp(SDL_Event* event){};
	virtual void OnMultiGesture(SDL_Event* event){};
	virtual void OnDollarGesture(SDL_Event* event){};
	virtual void OnDollarRecord(SDL_Event* event){};
	virtual void OnClipboardUpdate(SDL_Event* event){};
	virtual void OnDropFile(SDL_Event* event){};
	virtual void OnUnknownWindowEvent(SDL_Event* event){};
	virtual void OnUnknownEvent(SDL_Event* event){};
	
	//virtual void LinkButtonEvent(void (*ButtonEvent)(void*, DKEvent*), void* arg, int id){};
	static void ButtonEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnButton(event);}; 
	virtual void OnButton(DKEvent* event){};

	//virtual void LinkToggleEvent(void (*ToggleEvent)(void*, DKEvent*), void* arg, int id){};
	static void ToggleEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnToggle(event);}; 
	virtual void OnToggle(DKEvent* event){};

	//virtual void LinkTextBoxEvent(void (*TextBoxEvent)(void*, DKEvent*), void* arg, int id){};
	static void TextBoxEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnTextBox(event);}; 
	virtual void OnTextBox(DKEvent* event){};
	
	//virtual void LinkSliderEvent(void (*SliderEvent)(void*, DKEvent*), void* arg, int id){};
	static void SliderEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnSlider(event);}; 
	virtual void OnSlider(DKEvent* event){};

	//virtual void LinkListBoxEvent(void (*ListBoxEvent)(void*, DKEvent*), void* arg, int id){};
	static void ListBoxEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnListBox(event);}; 
	virtual void OnListBox(DKEvent* event){};

	//virtual void LinkTextButtonEvent(void (*TextButtonEvent)(void*, DKEvent*), void* arg, int id){};
	static void TextButtonEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnTextButton(event);}; 
	virtual void OnTextButton(DKEvent* event){};

	//virtual void LinkMenuBarEvent(void (*MenuBarEvent)(void*, DKEvent*), void* arg, int id){};
	static void MenuBarEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnMenuBar(event);}; 
	virtual void OnMenuBar(DKEvent* event){};

	//virtual void LinkDropDownEvent(void (*DropDownEvent)(void*, DKEvent*), void* arg, int id){};
	static void DropDownEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnDropDown(event);}; 
	virtual void OnDropDown(DKEvent* event){};

	//virtual void LinkColorPickerEvent(void (*ColorPickerEvent)(void*, DKEvent*), void* arg, int id){};
	static void ColorPickerEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnColorPicker(event);}; 
	virtual void OnColorPicker(DKEvent* event){};

	//virtual void LinkFileDialogEvent(void (*FileDialogEvent)(void*, DKEvent*), void* arg, int id){};
	static void FileDialogEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnFileDialog(event);}; 
	virtual void OnFileDialog(DKEvent* event){};

	//virtual void LinkScrollBarEvent(void (*ScrollBarEvent)(void*, DKEvent*), void* arg, int id){};
	static void ScrollBarEvent(void* arg, DKEvent *event){static_cast<DKEvent*>(arg)->OnScrollBar(event);}; 
	virtual void OnScrollBar(DKEvent* event){};
};

#endif //DKEvent_H
