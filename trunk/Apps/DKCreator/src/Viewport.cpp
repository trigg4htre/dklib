#include "Viewport.h"

////////////////////////////////////////////////////////////////
Viewport::Viewport(DKObject *parent, int x, int y, int w, int h)
{
	Create(this,x,y,w,h);
}

///////////////////////////////////////////////////////////////////
void Viewport::Create(DKObject *parent, int x, int y, int w, int h)
{
	DKPanel::Create(parent, DKPoint(x,y), DKSize(w,h));
	SetColor(DKColor(0,0,0,1));

	main_drop.Create(this,DKPoint(0,0),DKFont::fonts[0]);
	main_drop.LinkDropDownEvent(DropDownEvent,this,0);
	main_drop.AddSelection("Set Background Color",1);
	main_drop.AddSelection("New Square",2);
	main_drop.AddSelection("New Text",3);
	main_drop.AddSelection("New Button",4);
	main_drop.AddSelection("New Circle",5);
	main_drop.AddSelection("New Image",6);
	main_drop.AddSelection("New Line",7);
	main_drop.AddSelection("New Listbox",8);
	main_drop.AddSelection("New Textbox",9);
	main_drop.AddSelection("New Textbutton",10);
	main_drop.AddSelection("New Toggle",11);
	main_drop.AddSelection("New Triange",12);
	
	object_drop.Create(this,DKPoint(0,0),DKFont::fonts[0]);
	object_drop.LinkDropDownEvent(DropDownEvent,this,0);
	object_drop.AddSelection("Set Color",101);
	object_drop.AddSelection("Bring Forward",102);
	object_drop.AddSelection("Send Backward",103);
	object_drop.AddSelection("Bring To Front",104);
	object_drop.AddSelection("Send To Back",105);
	object_drop.AddSelection("Delete",106);

	scroll_panel.Create(this, DKPoint(10,10), DKSize(90,90));
	scroll_image.Create(scroll_panel.object, DKPoint(0,0), DKFile::DataPath("checkers.png"));
	
	dragging = NULL;
	resizeing = NULL;
	rotating = NULL;
}

/////////////////////
Viewport::~Viewport()
{
	unsigned int b = v_objects.size();
	for(unsigned int i=0; i<b; ++i){
		Delete(0);
	}
}

///////////////////////////////////////////
void Viewport::OnTextButton(DKEvent* event)
{
	if(event->id==1){

	}
}

/////////////////////////////////////////
void Viewport::OnDropDown(DKEvent* event)
{
	if(event->id2==1){ //Set Background Color
		DKColorPicker *color_picker = new DKColorPicker();
		color_picker->LinkColorPickerEvent(ColorPickerEvent,this,1);
	}
	if(event->id2==2){ //New Square
		int x,y;
		SDL_GetMouseState(&x, &y);
		NewSquare(x-(int)draw.x,y-(int)draw.y);
	}
	if(event->id2==3){ //New Text
		int x,y;
		SDL_GetMouseState(&x, &y);
		NewText(x-(int)draw.x,y-(int)draw.y);
	}
	if(event->id2==5){ //New Square
		int x,y;
		SDL_GetMouseState(&x, &y);
		NewCircle(x-(int)draw.x,y-(int)draw.y);
	}
	if(event->id2==6){ //New Image
		DKFileDialog *fd = new DKFileDialog(this);
		fd->LinkFileDialogEvent(FileDialogEvent,this,1);
	}
	if(event->id2==101){ //Set Color
		DKColorPicker *color_picker = new DKColorPicker();
		color_picker->LinkColorPickerEvent(ColorPickerEvent,this,2);
	}
	if(event->id2==102){ //Bring Forward
		BringForward(current_object);
	}
	if(event->id2==103){ //Send Backward
		SendBackward(current_object);
	}
	if(event->id2==104){ //Bring To Front
		BringToFront(current_object);
	}
	if(event->id2==105){ //SendToBack
		SendToBack(current_object);
	}
	if(event->id2==106){ //Delete
		Delete(current_object);
	}

}

////////////////////////////////////////////
void Viewport::OnColorPicker(DKEvent* event)
{
	if(event->id == 1){
		SetColor( ((DKColorPicker*)event)->GetCurrentColor() );
	}
	if(event->id == 2){
		v_objects[current_object]->SetColor( ((DKColorPicker*)event)->GetCurrentColor() );
	}
}

///////////////////////////////////////////
void Viewport::OnFileDialog(DKEvent* event)
{
	if(event->id == 1){//New image file dialog
		NewImage( ((DKFileDialog*)event)->full_path );
	}
}

////////////////////////////////////////
void Viewport::OnKeyUp(SDL_Event* event)
{
	if(NotVisible()){return;}
	
	dragging = NULL;
	resizeing = NULL;
	rotating = NULL;
}

////////////////////////////////////////////////
void Viewport::OnMouseButtonUp(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y && event->button.button == SDL_BUTTON_RIGHT){
		
		//Check all objects
		for(int i=v_objects.size()-1; i>-1; --i){
			if(event->button.x >= v_objects[i]->draw.x && event->button.x <= v_objects[i]->draw.x+v_objects[i]->size.x && event->button.y >= v_objects[i]->draw.y && event->button.y <= v_objects[i]->draw.y+v_objects[i]->size.y && event->button.button == SDL_BUTTON_RIGHT){
				current_object = i;

				object_drop.SetPosition(DKPoint(event->button.x-draw.x, event->button.y-draw.y));
				object_drop.Show();
				
				SkipEvents();
				return;
			}
		}
		DKDebug("Right Clicked Viewport\n");
		main_drop.SetPosition(DKPoint(event->button.x-draw.x, event->button.y-draw.y, 0));
		main_drop.Show();
		SkipEvents();
		return;
	}
}

//////////////////////////////////////////
void Viewport::OnKeyDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	
	int x,y;
	SDL_GetMouseState(&x, &y);

	for(int i=v_objects.size()-1; i>-1; --i){
		if(x >= v_objects[i]->draw.x 
		&& x <= v_objects[i]->draw.x+v_objects[i]->size.x 
		&& y >= v_objects[i]->draw.y 
		&& y <= v_objects[i]->draw.y+v_objects[i]->size.y){
		
			if(event->key.keysym.sym == SDLK_d && event->key.repeat == 0){ // D Key = drag;
				drag_x = x - (int)v_objects[i]->draw.x;
				drag_y = y - (int)v_objects[i]->draw.y;
				dragging = v_objects[i];
				return;
			}
			if(event->key.keysym.sym == SDLK_s && event->key.repeat == 0){ // S Key = size;
				drag_x = x;
				drag_y = y;
				size_x = (int)v_objects[i]->size.x;
				size_y = (int)v_objects[i]->size.y;
				resizeing = v_objects[i];
				return;
			}
			if(event->key.keysym.sym == SDLK_r && event->key.repeat == 0){ // R Key = rotate;
				drag_y = y;
				rot_z = (int)v_objects[i]->rotation.z;
				rotating = v_objects[i];
				return;
			}
		}
	}
}

//////////////////////////////////////////////
void Viewport::OnMouseMotion(SDL_Event* event)
{
	//FIXME - we need to get the mouse offset to the object moves according. 
	if(NotVisible()){return;}
	if(dragging != NULL){
		dragging->SetPosition(DKPoint(event->button.x-draw.x-drag_x,event->button.y-draw.y-drag_y));
		Update();
	}
	if(resizeing != NULL){
		resizeing->SetSize(DKSize(size_x+event->button.x-drag_x,size_y+event->button.y-drag_y));
		Update();
	}
	if(rotating != NULL){
		rotating->SetRotation(DKRotate(0,0,rot_z+event->button.y-drag_y));
		Update();
	}
}

//////////////////////////////////////
void Viewport::NewSquare(int x, int y)
{
	v_objects.push_back(new DKSquare(this, DKPoint(x,y), DKSize(100,100)));
}

//////////////////////////////////////
void Viewport::NewCircle(int x, int y)
{
	v_objects.push_back(new DKCircle(this, DKPoint(x,y), DKSize(100,100)));
}

////////////////////////////////////
void Viewport::NewText(int x, int y)
{
	v_objects.push_back(new DKText(this, DKPoint(x,y), DKFont::fonts[0], "Text"));
	((DKText*)v_objects[v_objects.size()-1])->SetColor(DKColor(1,1,1,1));
}

//////////////////////////////////////////
void Viewport::NewTextButton(int x, int y)
{
	v_objects.push_back(new DKTextButton(this, DKPoint(x,y), DKFont::fonts[0], "NewTextButton"));
	((DKTextButton*)v_objects[v_objects.size()-1])->LinkTextButtonEvent(TextButtonEvent, this, v_objects.size());
}

//////////////////////////////////////
void Viewport::NewImage(DKString file)
{
	v_objects.push_back(new DKImage(this, DKPoint(size.x/2-100,size.y/2-100), file));
}

/////////////////////////////////////////////////
void Viewport::Delete(unsigned int object_number)
{
	if(v_objects[object_number]->name == "DKSquare"){
		delete (DKSquare*)v_objects[object_number];
	}
	else if(v_objects[object_number]->name == "DKCircle"){
		delete (DKCircle*)v_objects[object_number];
	}
	else if(v_objects[object_number]->name == "DKText"){
		delete (DKText*)v_objects[object_number];
	}
	else if(v_objects[object_number]->name == "DKTextButton"){
		delete (DKTextButton*)v_objects[object_number];
	}
	else if(v_objects[object_number]->name == "DKImage"){
		delete (DKImage*)v_objects[object_number];
	}
	v_objects.erase(v_objects.begin()+object_number);
}

///////////////////////////////////////////////////////
void Viewport::BringForward(unsigned int object_number)
{
	DKObject::BringForward(v_objects[current_object]);
	if(object_number < v_objects.size()-1){
		v_objects.insert(v_objects.begin()+object_number+2, v_objects[current_object]);
		v_objects.erase(v_objects.begin()+object_number);
		return;
	}
	else{
		BringToFront(current_object);
		return;
	}
}

///////////////////////////////////////////////////////
void Viewport::SendBackward(unsigned int object_number)
{
	DKObject::SendBackward(v_objects[current_object]);
	v_objects.insert(v_objects.begin()+current_object-1, v_objects[current_object]);
	v_objects.erase(v_objects.begin()+current_object+1);
}

////////////////////////////////////////////////////////
void Viewport::BringToFront(unsigned  int object_number)
{
	DKObject::BringToFront(v_objects[current_object]);
	v_objects.push_back(v_objects[object_number]);
	v_objects.erase(v_objects.begin()+object_number);
}

/////////////////////////////////////////////////////
void Viewport::SendToBack(unsigned int object_number)
{
	for(unsigned int i=0; i<objects.size(); i++){
		if(objects[i] == this){
			DKObject::MoveToSpot(v_objects[current_object], i+1);
			v_objects.insert(v_objects.begin(), v_objects[current_object]);
			v_objects.erase(v_objects.begin()+object_number+1);
			int b=0;
		}
	}	
}