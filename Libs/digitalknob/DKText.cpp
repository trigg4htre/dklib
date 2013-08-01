#include "DKText.h"

//////////////////////////////////////////////////////////////////////////
DKText::DKText(DKObject *parent, DKPoint pos, DKFont *font, DKString text)
{
	Create(parent,pos,font,text);
}

///////////////////////////////////////////////////////////////////////////////
void DKText::Create(DKObject *parent, DKPoint pos, DKFont *font, DKString text)
{
	name = "DKText";
	par = parent;
	point = pos;
	CalculateDraw();
	string = text;
	//font_size = 45;
	m_font = font;
	text_color[0] = 1.0f;
	text_color[1] = 1.0f;
	text_color[2] = 1.0f;
	text_color[3] = 1.0f;
	size.x = (float)m_font->GetWidth(text);
	size.y = (float)m_font->GetHeight();
	SetVisibility(true);
}

/////////////////
DKText::~DKText()
{

}

/////////////////////////////////////////////////////////////////////////////////////
DKObject* DKText::NewText(DKObject *parent, DKPoint pos, DKFont *font, DKString text)
{
	objects.push_back(new DKText(parent, pos, font, text));
	return objects[objects.size() - 1];
}

/////////////////////////////////////
void DKText::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();
}

////////////////////////////////
void DKText::SetSize(DKSize siz)
{
	
}

///////////////////////////////////
void DKText::SetColor(DKColor rgba)
{
	color = rgba;

	text_color[0] = color.r;
	text_color[1] = color.g;
	text_color[2] = color.b;
	text_color[3] = color.a;
}

///////////////////////////////
DKString DKText::GetString()
{
	return string;
}

////////////////////////////////////////
void DKText::SetString(DKString text)
{
	string = text;
}

//////////////////////
void DKText::Display()
{
	if(NotVisible()){return;}
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor4f(text_color[0], text_color[1], text_color[2], text_color[3]);

	//FIXME - causes weird stuff to happen in 3D view when we use z
	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,-scale.y,scale.z);
	glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	glTranslatef(draw.x, draw.y, 0);

	if(m_font->texture_font != NULL){
		m_font->texture_font->Render(string.c_str());
	}

    glPopMatrix();
}