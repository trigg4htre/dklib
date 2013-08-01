#include "DKSquare.h"

////////////////////
DKSquare::DKSquare()
{

}

/////////////////////////////////////////////////////////////
DKSquare::DKSquare(DKObject *parent, DKPoint pos, DKSize siz)
{
	Create(parent,pos,siz);
}

////////////////////////////////////////////////////////////////
void DKSquare::Create(DKObject *parent, DKPoint pos, DKSize siz)
{
	name = "DKSquare";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	
	CalculateDraw();
	
	size = siz;

	softness = 1;
	Recalculate();
	SetColor(DKColor(0.5,0.5,0.5,1));
	SetVisibility(true);
}


/////////////////////
DKSquare::~DKSquare()
{

}

///////////////////////////////////////////////////////////////////
DKObject* DKSquare::NewSquare(DKObject *parent, DKPoint pos, DKSize siz)
{
	objects.push_back(new DKSquare(parent, pos, siz));
	return objects[objects.size() - 1];
}


////////////////////////////
void DKSquare::Recalculate()
{
	square_vectors[0] = (float)draw.x; //left,bottom
	square_vectors[1] = (float)draw.y+size.y;
	//color[0] = 1;
	//color[1] = 1;
	//color[2] = 1;
	//color[3] = 1;
	square_vectors[2] = (float)draw.x; //left,top
	square_vectors[3] = (float)draw.y;
	//color[4] = 1;
	//color[5] = 1;
	//color[6] = 1;
	//color[7] = 1;
	square_vectors[4] = (float)draw.x+size.x; //right, bottom
	square_vectors[5] = (float)draw.y+size.y;
	//color[8] = 1;
	//color[9] = 1;
	//color[10] = 1;
	//color[11] = 1;
	square_vectors[6] = (float)draw.x+size.x; //right, top
	square_vectors[7] = (float)draw.y;
	//color[12] = 1;
	//color[13] = 1;
	//color[14] = 1;
	//color[15] = 1;

	//Left outline
	outline[0] = (float)draw.x-softness; //bottom,alpha
	outline[1] = (float)draw.y+size.y;
	//outline_color[0] = 1;
	//outline_color[1] = 1;
	//outline_color[2] = 1;
	//outline_color[3] = 0;
	outline[2] = (float)draw.x-softness; //top,alpha
	outline[3] = (float)draw.y;
	//outline_color[4] = 1;
	//outline_color[5] = 1;
	//outline_color[6] = 1;
	//outline_color[7] = 0;
	outline[4] = (float)draw.x;          //top,color
	outline[5] = (float)draw.y+size.y;
	//outline_color[8] = 1;
	//outline_color[9] = 1;
	//outline_color[10] = 1;
	//outline_color[11] = 1;
	outline[6] = (float)draw.x;         //bottom color
	outline[7] = (float)draw.y;
	//outline_color[12] = 1;
	//outline_color[13] = 1;
	//outline_color[14] = 1;
	//outline_color[15] = 1;

	//right outline
	outline2[0] = (float)draw.x+size.x; //color
	outline2[1] = (float)draw.y+size.y;
	//outline_color2[0] = 1;
	//outline_color2[1] = 1;
	//outline_color2[2] = 1;
	//outline_color2[3] = 1;
	outline2[2] = (float)draw.x+size.x; //color
	outline2[3] = (float)draw.y;
	//outline_color2[4] = 1;
	//outline_color2[5] = 1;
	//outline_color2[6] = 1;
	//outline_color2[7] = 1;
	outline2[4] = (float)draw.x+size.x+softness; //alpha
	outline2[5] = (float)draw.y+size.y;
	//outline_color2[8] = 1;
	//outline_color2[9] = 1;
	//outline_color2[10] = 1;
	//outline_color2[11] = 0;
	outline2[6] = (float)draw.x+size.x+softness; //alpha
	outline2[7] = (float)draw.y;
	//outline_color2[12] = 1;
	//outline_color2[13] = 1;
	//outline_color2[14] = 1;
	//outline_color2[15] = 0;

	// top outline
	outline3[0] = (float)draw.x; //color
	outline3[1] = (float)draw.y;
	//outline_color3[0] = 1;
	//outline_color3[1] = 1;
	//outline_color3[2] = 1;
	//outline_color3[3] = 1;
	outline3[2] = (float)draw.x+size.x; //color
	outline3[3] = (float)draw.y;
	//outline_color3[4] = 1;
	//outline_color3[5] = 1;
	//outline_color3[6] = 1;
	//outline_color3[7] = 1;
	outline3[4] = (float)draw.x;   //alpha
	outline3[5] = (float)draw.y-softness;
	//outline_color3[8] = 1;
	//outline_color3[9] = 1;
	//outline_color3[10] = 1;
	//outline_color3[11] = 0;
	outline3[6] = (float)draw.x+size.x; //alpha
	outline3[7] = (float)draw.y-softness;
	//outline_color3[12] = 1;
	//outline_color3[13] = 1;
	//outline_color3[14] = 1;
	//outline_color3[15] = 0;

	// bottom outline
	outline4[0] = (float)draw.x; //color
	outline4[1] = (float)draw.y+size.y;
	//outline_color4[0] = 1;
	//outline_color4[1] = 1;
	//outline_color4[2] = 1;
	//outline_color4[3] = 1;
	outline4[2] = (float)draw.x+size.x; //color
	outline4[3] = (float)draw.y+size.y;
	//outline_color4[4] = 1;
	//outline_color4[5] = 1;
	//outline_color4[6] = 1;
	//outline_color4[7] = 1;
	outline4[4] = (float)draw.x; //color
	outline4[5] = (float)draw.y+size.y+softness;
	//outline_color4[8] = 1;
	//outline_color4[9] = 1;
	//outline_color4[10] = 1;
	//outline_color4[11] = 0;
	outline4[6] = (float)draw.x+size.x; //color
	outline4[7] = (float)draw.y+size.y+softness;
	//outline_color4[12] = 1;
	//outline_color4[13] = 1;
	//outline_color4[14] = 1;
	//outline_color4[15] = 0;
}

///////////////////////////////////////
void DKSquare::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();
	Recalculate();
}

//////////////////////////////////
void DKSquare::SetSize(DKSize siz)
{
	size = siz;
	Recalculate();
}

/////////////////////////////////////
void DKSquare::SetScale(DKScale scal)
{
	scale = scal;
}

/////////////////////////////////////
void DKSquare::SetColor(DKColor rgba)
{
	color = rgba;

	//FIXME - this does not fix the outlines
	for(int i=0; i<16; i=i+4){
		square_colors[i] = color.r;
		square_colors[i+1] = color.g;
		square_colors[i+2] = color.b;
		square_colors[i+3] = color.a;
	}
}

////////////////////////////////////////////
void DKSquare::SetTopLeftColor(DKColor rgba)
{
	square_colors[4] = rgba.r;
	square_colors[5] = rgba.g;
	square_colors[6] = rgba.b;
	square_colors[7] = rgba.a;

	outline_color[4] = rgba.r;
	outline_color[5] = rgba.g;
	outline_color[6] = rgba.b;
	outline_color[7] = 0.0f;

	outline_color[12] = rgba.r;
	outline_color[13] = rgba.g;
	outline_color[14] = rgba.b;
	outline_color[15] = rgba.a;

	outline_color3[0] = rgba.r;
	outline_color3[1] = rgba.g;
	outline_color3[2] = rgba.b;
	outline_color3[3] = rgba.a;

	outline_color3[8] = rgba.r;
	outline_color3[9] = rgba.g;
	outline_color3[10] = rgba.b;
	outline_color3[11] = 0.0f;
}

/////////////////////////////////////////////
void DKSquare::SetTopRightColor(DKColor rgba)
{
	square_colors[12] = rgba.r;
	square_colors[13] = rgba.g;
	square_colors[14] = rgba.b;
	square_colors[15] = rgba.a;

	outline_color2[4] = rgba.r;
	outline_color2[5] = rgba.g;
	outline_color2[6] = rgba.b;
	outline_color2[7] = rgba.a;

	outline_color2[12] = rgba.r;
	outline_color2[13] = rgba.g;
	outline_color2[14] = rgba.b;
	outline_color2[15] = 0;

	outline_color3[4] = rgba.r;
	outline_color3[5] = rgba.g;
	outline_color3[6] = rgba.b;
	outline_color3[7] = rgba.a;

	outline_color3[12] = rgba.r;
	outline_color3[13] = rgba.g;
	outline_color3[14] = rgba.b;
	outline_color3[15] = 0;
}

///////////////////////////////////////////////
void DKSquare::SetBottomLeftColor(DKColor rgba)
{
	square_colors[0] = rgba.r;
	square_colors[1] = rgba.g;
	square_colors[2] = rgba.b;
	square_colors[3] = rgba.a;

	outline_color[0] = rgba.r;
	outline_color[1] = rgba.g;
	outline_color[2] = rgba.b;
	outline_color[3] = 0;

	outline_color[8] = rgba.r;
	outline_color[9] = rgba.g;
	outline_color[10] = rgba.b;
	outline_color[11] = rgba.a;

	outline_color4[0] = rgba.r;
	outline_color4[1] = rgba.g;
	outline_color4[2] = rgba.b;
	outline_color4[3] = rgba.a;

	outline_color4[8] = rgba.r;
	outline_color4[9] = rgba.g;
	outline_color4[10] = rgba.b;
	outline_color4[11] = 0;
}

////////////////////////////////////////////////
void DKSquare::SetBottomRightColor(DKColor rgba)
{
	square_colors[8] = rgba.r;
	square_colors[9] = rgba.g;
	square_colors[10] = rgba.b;
	square_colors[11] = rgba.a;

	outline_color2[0] = rgba.r;
	outline_color2[1] = rgba.g;
	outline_color2[2] = rgba.b;
	outline_color2[3] = rgba.a;

	outline_color2[8] = rgba.r;
	outline_color2[9] = rgba.g;
	outline_color2[10] = rgba.b;
	outline_color2[11] = 0;

	outline_color4[4] = rgba.r;
	outline_color4[5] = rgba.g;
	outline_color4[6] = rgba.b;
	outline_color4[7] = rgba.a;

	outline_color4[12] = rgba.r;
	outline_color4[13] = rgba.g;
	outline_color4[14] = rgba.b;
	outline_color4[15] = 0;
}

////////////////////////
void DKSquare::Display()
{
	if(NotVisible()){return;}

	if(point.x == DKCENTERX){
		draw.x = par->draw.x + par->size.x/2 - size.x/2;
		Recalculate();
	}
	if(point.y == DKCENTERY){
		draw.y = par->draw.y + par->size.y/2 - size.y/2;
		Recalculate();
	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glVertexPointer(2, GL_FLOAT, 0, square_vectors);
	glColorPointer(4, GL_FLOAT, 0, square_colors);
	
	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, draw.z); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), -draw.z); //from top left
	//////////////////////////////////////////////////////////

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	///anti-aliased outline
	glVertexPointer(2, GL_FLOAT, 0, outline);
	glColorPointer(4, GL_FLOAT, 0, outline_color);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glVertexPointer(2, GL_FLOAT, 0, outline2);
	glColorPointer(4, GL_FLOAT, 0, outline_color2);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glVertexPointer(2, GL_FLOAT, 0, outline3);
	glColorPointer(4, GL_FLOAT, 0, outline_color3);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glVertexPointer(2, GL_FLOAT, 0, outline4);
	glColorPointer(4, GL_FLOAT, 0, outline_color4);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glDisable(GL_BLEND);
	
	glPopMatrix();
}
