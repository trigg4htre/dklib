#include "DKTriangle.h"

/////////////////////////////////////////////////////////////////////////////////////
DKTriangle::DKTriangle(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3)
{
	Create(parent,pos,x2,y2,x3,y3);
}

///////////////////////////////////////////////////////////////////////////////////////
void DKTriangle::Create(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3)
{
	name = "DKTriangle";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	/*
	point.x = par->draw.x + point.x;
	y_pos = par->draw.y + point.y;
	z_pos = par->draw.z + point.z;
	x_pos2 = par->draw.x+x2;
	y_pos2 = par->draw.y+y2;
	z_pos2 = 0;
	x_pos3 = par->draw.x+x3;
	y_pos3 = par->draw.y+y3;
	z_pos3 = 0;
	*/
	size.x = x2-point.x;
	size.y = y3-point.y;
	size.z = 0;
	Update();

	SetVisibility(true);
}

/////////////////////////
DKTriangle::~DKTriangle()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////
DKObject* DKTriangle::NewTriangle(DKObject *parent, DKPoint pos, int x2, int y2, int x3, int y3)
{
	objects.push_back(new DKTriangle(parent, pos, x2,y2,x3,y3));
	return objects[objects.size() - 1];
}

/////////////////////////
void DKTriangle::Update()
{
	tri_vectors[0] = point.x;
	tri_vectors[1] = point.y;
	tri_vectors[2] = point.z;
	tri_vectors[3] = x_pos2;
	tri_vectors[4] = y_pos2;
	tri_vectors[5] = 0.0f;
	tri_vectors[6] = x_pos3;
	tri_vectors[7] = y_pos3;
	tri_vectors[8] = 0.0f;
}

/////////////////////////////////////////
void DKTriangle::SetPosition(DKPoint pos)
{
	/*
	x_pos2 = x_pos2 + (par->draw.x + pos.x - point.x);
	y_pos2 = y_pos2 + (par->draw.y + pos.y - point.y);
	z_pos2 = z_pos2 + (par->draw.z + pos.z - point.z);
	x_pos3 = x_pos3 + (par->draw.x + pos.x - point.x);
	y_pos3 = y_pos3 + (par->draw.y + pos.y - point.y);
	z_pos3 = z_pos3 + (par->draw.z + pos.z - point.z);
	x_pos = par->draw.x+x;
	y_pos = par->draw.y+y;
	z_pos = par->draw.x+z;
	*/
	Update();
}

////////////////////////////////////
void DKTriangle::SetSize(DKSize siz)
{
	size = siz;
	x_pos2 = point.x + size.x;
	//y_pos2 = ?
	//z_pos2 = ?
	//x_pos3 = ?
	//y_pos3 = ?
	//z_pos3 = ?
	Update();
}

///////////////////////////////////////
void DKTriangle::SetColor(DKColor rgba)
{
	color = rgba;

	tri_colors[0] = color.r;
	tri_colors[1] = color.g;
	tri_colors[2] = color.b;
	tri_colors[3] = color.a;

	tri_colors[4] = color.r;
	tri_colors[5] = color.g;
	tri_colors[6] = color.b;
	tri_colors[7] = color.a;

	tri_colors[8] = color.r;
	tri_colors[9] = color.g;
	tri_colors[10] = color.b;
	tri_colors[11] = color.a;
}

/////////////////////////////////////////////
void DKTriangle::SetPoint1Color(DKColor rgba)
{
	tri_colors[0] = rgba.r;
	tri_colors[1] = rgba.g;
	tri_colors[2] = rgba.b;
	tri_colors[3] = rgba.a;
}

/////////////////////////////////////////////
void DKTriangle::SetPoint2Color(DKColor rgba)
{
	tri_colors[4] = rgba.r;
	tri_colors[5] = rgba.g;
	tri_colors[6] = rgba.b;
	tri_colors[7] = rgba.a;
}

/////////////////////////////////////////////
void DKTriangle::SetPoint3Color(DKColor rgba)
{
	tri_colors[8] = rgba.r;
	tri_colors[9] = rgba.g;
	tri_colors[10] = rgba.b;
	tri_colors[11] = rgba.a;
}

//////////////////////////
void DKTriangle::Display()
{
	if(NotVisible()){return;}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColorPointer(4, GL_FLOAT, 0, tri_colors); //get the color
	glEnableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glVertexPointer(3, GL_FLOAT, 0,tri_vectors); //get the triangle
	glEnableClientState(GL_VERTEX_ARRAY);
	
	//FIXME - causes weird stuff to happen in 3D view when we use z
	////  Transformations ////////////////////////////////////
	glTranslatef(point.x+size.x/2, point.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(point.x+size.x/2),-(point.y+size.y/2),0); //from top left
	//////////////////////////////////////////////////////////

	glDrawArrays(GL_TRIANGLES, 0, 3); //draw it
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); // enables the color-array.

	glPopMatrix();
}