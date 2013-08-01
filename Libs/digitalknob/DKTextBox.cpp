#include "DKTextBox.h"

//////////////////////////////////////////////////////////////////////////////////////////
DKTextBox::DKTextBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	Create(parent,pos,siz,font,eventID);
}

////////////////////////////////////////////////////////////////////////////////////////////
void DKTextBox::Create(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	name = "DKTextBox";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;

	CalculateDraw();
	
	size = siz;

	has_focus = false;
	square = (DKSquare*)DKSquare::NewSquare(this, DKPoint(0,0), size);
	square->SetColor(DKColor(0.9f,0.9f,0.9f,1));
	text = (DKText*)DKText::NewText(this,DKPoint(3,3),font,"");
	text->SetColor(DKColor(0,0,0,1));

	LinkTextBoxEvent(TextBoxEvent, par, eventID);
	SetVisibility(true);
}

///////////////////////
DKTextBox::~DKTextBox()
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKTextBox::NewTextBox(DKObject *parent, DKPoint pos, DKSize siz, DKFont *font, int eventID)
{
	objects.push_back(new DKTextBox(parent, pos, siz, font, eventID));
    return objects[objects.size() - 1];
}

//////////////////////////////////////////////
void DKTextBox::LinkWindow(SDL_Window *window)
{
	main_window = window;
}

//////////////////////////////////////////////////////////////////////////////////////////
void DKTextBox::LinkTextBoxEvent(void (*TextBoxEvent)(void*, DKEvent*), void* arg, int id)
{
	OnTextBox = TextBoxEvent;
	m_arg = arg;
	this->id = id;
}

////////////////////////////////////////
void DKTextBox::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();

	//Update Child Positions
	for(unsigned int i=0; i<objects.size(); ++i){
		if(objects[i]->par == this){
			objects[i]->SetPosition(objects[i]->point);
		}
	}
}

////////////////////////////////////////////
void DKTextBox::SetRotation(DKRotate rotate)
{
	rotation = rotate;
	//square.SetRotation(rotation);
	//text.SetRotation(rotation);
}

////////////////////////////////
DKString DKTextBox::GetText()
{
	return text->GetString();
}

///////////////////////////////////////////
void DKTextBox::SetText(DKString string)
{
	text->SetString(string);
}

//////////////////////////////////////////
void DKTextBox::OnKeyDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(has_focus){
		SendKeyEvent(event->key.keysym.sym);
		SkipEvents();
	}
}

///////////////////////////////////////////////////
void DKTextBox::OnMouseButtonDown(SDL_Event* event)
{
	if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	if(event->button.x >= draw.x && event->button.x <= draw.x+size.x && event->button.y >= draw.y && event->button.y <= draw.y+size.y && event->button.button == SDL_BUTTON_LEFT){
		has_focus = true;
		Update();
		SkipEvents();
	}
	else{
		has_focus = false;
	}
}

/////////////////////////////////////////////
void DKTextBox::OnFingerDown(SDL_Event* event)
{
    if(NotVisible()){return;}
	if(WrongWindow(event)){return;}

	int tX = (int)event->tfinger.x * (int)frame->size.x;
	int tY = (int)event->tfinger.y * (int)frame->size.y;
	if(tX >= draw.x && tX <= draw.x+size.x && tY >= draw.y && tY <= draw.y+size.y){
		has_focus = true;
		SkipEvents();
#ifdef IOS
		//SDL_iPhoneKeyboardShow(main_window);
#endif
	}
    else{
        has_focus = false;
    }
}

/////////////////////////
void DKTextBox::Display()
{
	if(NotVisible()){return;}
	if(has_focus){
		square->SetColor(DKColor(1,1,1,1));
	}
	else{
		square->SetColor(DKColor(0.9f,0.9f,0.9f,1)); 
	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	//glEnable(GL_SCISSOR_TEST);
	Display2DObjects(this);
	//glScissor(point.x,screenHeight-size.y-y_pos,size.x,size.y);
	//glDisable(GL_SCISSOR_TEST);
	glPopMatrix();
}

/////////////////////////////////////////////
void DKTextBox::SendKeyEvent(SDL_Keycode sym)
{
	DKString key = GetKey(sym);
	DKString string = text->GetString();

#ifdef IOS
	if(sym == SDLK_DELETE){sym = SDLK_BACKSPACE;} //IPhones delete is really backspace
#endif
	if(sym == SDLK_BACKSPACE){
		if(string.length() > 0){
			text->SetString(string.substr(0,string.length()-1));
			OnTextBox(m_arg, this);
			Update();
			return;
		}
	}
	else if(sym == SDLK_RETURN){
		OnTextBox(m_arg, this);
		return;
	}
	else if(key.length() > 1){ //ignore these keys
		return;
	}
	else{
		string.append(key);
		text->SetString(string);
		OnTextBox(m_arg, this);
		Update();
		return;
	}
}

///////////////////////////////////////////
DKString DKTextBox::GetKey(SDL_Keycode sym)
{
	//FIXME - if capslock is on and we hold shift, we still need to send special characters.
	// !@#$%^&*()_+|{}:"<>?~

	bool caps = false;
	bool shift = false;
	int mod = SDL_GetModState();
	if(mod == KMOD_CAPS){ caps = true; }
	if(mod == KMOD_LSHIFT || mod == KMOD_RSHIFT){ 
		shift = true; 
	}

	if(!caps && !shift){
		if(sym == SDLK_a){return "a";}
		if(sym == SDLK_b){return "b";}
		if(sym == SDLK_c){return "c";}
		if(sym == SDLK_d){return "d";}
		if(sym == SDLK_e){return "e";}
		if(sym == SDLK_f){return "f";}
		if(sym == SDLK_g){return "g";}
		if(sym == SDLK_h){return "h";}
		if(sym == SDLK_i){return "i";}
		if(sym == SDLK_j){return "j";}
		if(sym == SDLK_k){return "k";}
		if(sym == SDLK_l){return "l";}
		if(sym == SDLK_m){return "m";}
		if(sym == SDLK_n){return "n";}
		if(sym == SDLK_o){return "o";}
		if(sym == SDLK_p){return "p";}
		if(sym == SDLK_q){return "q";}
		if(sym == SDLK_r){return "r";}
		if(sym == SDLK_s){return "s";}
		if(sym == SDLK_t){return "t";}
		if(sym == SDLK_u){return "u";}
		if(sym == SDLK_v){return "v";}
		if(sym == SDLK_w){return "w";}
		if(sym == SDLK_x){return "x";}
		if(sym == SDLK_y){return "y";}
		if(sym == SDLK_z){return "z";}
	}
	if(shift){
		if(sym == SDLK_BACKQUOTE){return"~";}
		if(sym == SDLK_1){return "!";}
		if(sym == SDLK_2){return "@";}
		if(sym == SDLK_3){return "#";}
		if(sym == SDLK_4){return "$";}
		if(sym == SDLK_5){return "%";}
		if(sym == SDLK_6){return "^";}
		if(sym == SDLK_7){return "&";}
		if(sym == SDLK_8){return "*";}
		if(sym == SDLK_9){return "(";}
		if(sym == SDLK_0){return ")";}
		if(sym == SDLK_MINUS){return "_";}
		if(sym == SDLK_EQUALS){return "+";}
		if(sym == SDLK_BACKSLASH){return "|";}
		if(sym == SDLK_LEFTBRACKET){return "{";}
		if(sym == SDLK_RIGHTBRACKET){return "}";}
		if(sym == SDLK_SEMICOLON){return ":";}
		if(sym == SDLK_QUOTE){return "\"";}
		if(sym == SDLK_COMMA){return "<";}
		if(sym == SDLK_PERIOD){return ">";}
		if(sym == SDLK_SLASH){return "?";}
	}
	if(sym == SDLK_SPACE){return " ";}

	return SDL_GetKeyName(sym);
}