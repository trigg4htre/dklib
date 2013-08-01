#include "DKEvent.h"

//define our static variables
std::vector<DKEvent*> DKEvent::events;
bool DKEvent::skip_events = false;

////////////////////
DKEvent::DKEvent()
{
	id = 0;
	id2 = 0;
	events.push_back(this);
}

///////////////////
DKEvent::~DKEvent()
{
	//remove this event object from the vector
	for(unsigned int i=0; i<events.size(); ++i){
		if(events[i] == this){
			events.erase(events.begin()+i);
		}
	}
}

////////////////////////////////////////
void DKEvent::OnEvent(SDL_Event* event)
{
	switch(event->type){
		case SDL_WINDOWEVENT:
			switch (event->window.event) {
				case SDL_WINDOWEVENT_SHOWN:
					OnWindowShown(event);
					break;
				case SDL_WINDOWEVENT_HIDDEN:
					OnWindowHidden(event);
					break;
				case SDL_WINDOWEVENT_EXPOSED:
					OnWindowExposed(event);
					break;
				case SDL_WINDOWEVENT_MOVED:
					OnWindowMoved(event);
					break;
				case SDL_WINDOWEVENT_RESIZED:
					OnWindowResized(event);
					break;
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					OnWindowSizeChanged(event);
					break;
				case SDL_WINDOWEVENT_MINIMIZED:
					OnWindowMinimized(event);
					break;
				case SDL_WINDOWEVENT_MAXIMIZED:
					OnWindowMaximized(event);
					break;
				case SDL_WINDOWEVENT_RESTORED:
					OnWindowRestored(event);
					break;
				case SDL_WINDOWEVENT_ENTER:
					OnWindowEnter(event);
					break;
				case SDL_WINDOWEVENT_LEAVE:
					OnWindowLeave(event);
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					OnWindowFocusGained(event);
					break;
				case SDL_WINDOWEVENT_FOCUS_LOST:
					OnWindowFocusLost(event);
					break;
				case SDL_WINDOWEVENT_CLOSE:
					OnWindowClose(event);
					break;
				default:
					OnUnknownWindowEvent(event);
					break;
			}break;
		case SDL_KEYUP:
			OnKeyUp(event);
			break;
		case SDL_KEYDOWN:
			OnKeyDown(event);
			break;
		case SDL_TEXTEDITING:
			OnTextEdit(event);
			break;
		case SDL_TEXTINPUT:
			OnTextInput(event);
			break;
#ifndef IOS           
		case SDL_MOUSEMOTION:
			OnMouseMotion(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			OnMouseButtonDown(event);         
			break;
		case SDL_MOUSEBUTTONUP:
			OnMouseButtonUp(event);
			break;
		case SDL_MOUSEWHEEL:
			OnMouseWheel(event);
			break;
#endif            
		case SDL_JOYAXISMOTION:
			OnJoyAxisMotion(event);
			break;
		case SDL_JOYBALLMOTION:
			OnJoyBallMotion(event);
			break;
		case SDL_JOYHATMOTION:
			OnJoyHatMotion(event);
			break;
		case SDL_JOYBUTTONDOWN:
			OnJoyButtonDown(event);
			break;
		case SDL_JOYBUTTONUP:
			OnJoyButtonUp(event);
			break;

		//FIXME INPUTS Broken
		/*
		case SDL_INPUTMOTION:
			OnInputMotion(event);
			break;
		case SDL_INPUTBUTTONDOWN:
			OnInputButtonDown(event);
			break;
		case SDL_INPUTBUTTONUP:
			OnInputButtonUp(event);
			break;
		case SDL_INPUTWHEEL:
			OnInputWheel(event);
			break;
		case SDL_INPUTPROXIMITYIN:
			OnInputProximityIn(event);
			break;
		case SDL_INPUTPROXIMITYOUT:
			OnInputProximityOut(event);
			break;
		*/
		case SDL_QUIT:
			OnQuit(event);
			break;
		case SDL_USEREVENT:  //through SDL_NUMEVENTS-1
			OnUserEvent(event);
			break;
		case SDL_SYSWMEVENT:
			OnSysWMEvent(event);
			break;
		case SDL_FINGERMOTION:
			OnFingerMotion(event);
			break;
		case SDL_FINGERDOWN:
			OnFingerDown(event);
			break;
		case SDL_FINGERUP:
			OnFingerUp(event);
			break;
		//FIXME Touch broken
		/*
		case SDL_TOUCHBUTTONDOWN:
			OnTouchButtonDown(event);
			break;
		case SDL_TOUCHBUTTONUP:
			OnTouchButtonUp(event);
			break;
		*/
		case SDL_MULTIGESTURE:
			OnMultiGesture(event);
			break;
		case SDL_DOLLARGESTURE:
			OnDollarGesture(event);
			break;
		case SDL_DOLLARRECORD:
			OnDollarRecord(event);
			break;
		case SDL_CLIPBOARDUPDATE:
			OnClipboardUpdate(event);
			break;
		case SDL_DROPFILE:
			OnDropFile(event);
			break;
		default:
			OnUnknownEvent(event);
			break;
	}
}

////////////////////////////////////////
void DKEvent::DoEvents(SDL_Event* event)
{
	skip_events = false;
	for(int i=events.size()-1; i>-1; --i){
		if(skip_events == false){events[i]->OnEvent(event);} //trigger OnEvent for all event objects
	}
}

//////////////////////////
void DKEvent::SkipEvents()
{
	skip_events = true;
}
