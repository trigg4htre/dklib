#include "DKLine.h"

////////////////////////////////////////////////////////////////////////////
DKLine::DKLine(DKObject *parent, DKPoint pos, int x2, int y2, int linewidth)
{
	Create(parent,pos,x2,y2,linewidth);
}

/////////////////////////////////////////////////////////////////////////////////
void DKLine::Create(DKObject *parent, DKPoint pos, int x2, int y2, int linewidth)
{
	DKObject::Create(parent, "DKLine");
	point = pos;
	/*
	point.x = par->draw.x + point.x;
	y_pos = par->draw.y + point.y;
	z_pos = par->draw.z + point.z;
	x_pos2 = par->draw.x+x2;
	y_pos2 = par->draw.y+y2;
	z_pos2 = 0;
	*/
	size.x = x2-point.x;
	size.y = y2-point.y;
	size.z = 0;

	line_width = linewidth+1;
	filter_width = 2;

	Update();
	SetVisibility(true);
}

/////////////////////////
DKLine::~DKLine()
{

}

/////////////////////
void DKLine::Update()
{
	line_vectors[0] = point.x;
	line_vectors[1] = point.y;
	line_vectors[2] = point.z;

	line_vectors[3] = x_pos2;//100;
	line_vectors[4] = y_pos2;//30;
	line_vectors[5] = z_pos2;//0;

	line_vectors[6] = point.x + filter_width;//52;
	line_vectors[7] = point.y;//270;
	line_vectors[8] = point.z;//+filter_width;;//0;

	line_vectors[9] = x_pos2+filter_width;//102;
	line_vectors[10] = y_pos2;//30;
	line_vectors[11] = z_pos2;//+filter_width;;//0;

	line_vectors[12] = point.x+line_width-filter_width;//60;
	line_vectors[13] = point.y;//270;
	line_vectors[14] = point.z;//+lineWidth-filter_width;;//0;

	line_vectors[15] = x_pos2+line_width-filter_width;//110;
	line_vectors[16] = y_pos2;//30;
	line_vectors[17] = z_pos2;//+lineWidth-filter_width;;//0;

	line_vectors[18] = point.x+line_width;//62;
	line_vectors[19] = point.y;//270
	line_vectors[20] = point.z;//+lineWidth;;//0;

	line_vectors[21] = x_pos2+line_width;//112;
	line_vectors[22] = y_pos2;//30;
	line_vectors[23] = z_pos2;//+lineWidth;;//0;
}

/////////////////////////////////////
void DKLine::SetPosition(DKPoint pos)
{
	/*
	x_pos2 = x_pos2 + (par->draw.x+x - point.x);
	y_pos2 = y_pos2 + (par->draw.y+y - y_pos);
	z_pos2 = z_pos2 + (par->draw.z+z - z_pos);
	point.x = par->draw.x+x;
	y_pos = par->draw.y+y;
	z_pos = par->draw.z+z;
	*/
	Update();
}

////////////////////////////////
void DKLine::SetSize(DKSize siz)
{
	size = siz;
	x_pos2 = point.x + size.x;
	y_pos2 = point.y + size.y;
	z_pos2 = point.z + size.z;
	Update();
}

/////////////////////////////////////////////////////////
void DKLine::SetColor(DKColor rgba)
{
	color = rgba;

	line_colors[0] = color.r;
	line_colors[1] = color.g;
	line_colors[2] = color.b;
	line_colors[3] = 0; //alpha
	line_colors[8] = color.r;
	line_colors[9] = color.g;
	line_colors[10] = color.b;
	line_colors[11] = color.a; //alpha
	line_colors[16] = color.r;
	line_colors[17] = color.g;
	line_colors[18] = color.b;
	line_colors[19] = color.a; //alpha
	line_colors[24] = color.r;
	line_colors[25] = color.g;
	line_colors[26] = color.b;
	line_colors[27] = 0; //alpha

	line_colors[4] = color.r;
	line_colors[5] = color.g;
	line_colors[6] = color.b;
	line_colors[7] = 0; //alpha
	line_colors[12] = color.r;
	line_colors[13] = color.g;
	line_colors[14] = color.b;
	line_colors[15] = color.a; //alpha
	line_colors[20] = color.r;
	line_colors[21] = color.g;
	line_colors[22] = color.b;
	line_colors[23] = color.a; //alpha
	line_colors[28] = color.r;
	line_colors[29] = color.g;
	line_colors[30] = color.b;
	line_colors[31] = 0; //alpha
}

/////////////////////////////////////////
void DKLine::SetPoint1Color(DKColor rgba)
{
	line_colors[0] = rgba.r;
	line_colors[1] = rgba.g;
	line_colors[2] = rgba.b;
	line_colors[3] = 0; //alpha
	line_colors[8] = rgba.r;
	line_colors[9] = rgba.g;
	line_colors[10] = rgba.b;
	line_colors[11] = rgba.a; //alpha
	line_colors[16] = rgba.r;
	line_colors[17] = rgba.g;
	line_colors[18] = rgba.b;
	line_colors[19] = rgba.a; //alpha
	line_colors[24] = rgba.r;
	line_colors[25] = rgba.g;
	line_colors[26] = rgba.b;
	line_colors[27] = 0; //alpha
}

/////////////////////////////////////////
void DKLine::SetPoint2Color(DKColor rgba)
{
	line_colors[4] = rgba.r;
	line_colors[5] = rgba.g;
	line_colors[6] = rgba.b;
	line_colors[7] = 0; //alpha
	line_colors[12] = rgba.r;
	line_colors[13] = rgba.g;
	line_colors[14] = rgba.b;
	line_colors[15] = rgba.a; //alpha
	line_colors[20] = rgba.r;
	line_colors[21] = rgba.g;
	line_colors[22] = rgba.b;
	line_colors[23] = rgba.a; //alpha
	line_colors[28] = rgba.r;
	line_colors[29] = rgba.g;
	line_colors[30] = rgba.b;
	line_colors[31] = 0; //alpha
}

//////////////////////
void DKLine::Display()
{
	if(NotVisible()){return;}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);    
	glVertexPointer(3, GL_FLOAT, 0, line_vectors);
	glColorPointer(4, GL_FLOAT, 0, line_colors);

	//FIXME - causes weird stuff to happen in 3D view when we use z
	////  Transformations ////////////////////////////////////
	glTranslatef(point.x+size.x/2, point.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(point.x+size.x/2),-(point.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisable(GL_BLEND);

	glPopMatrix();
}