#include "DKCircle.h"

/////////////////////////////////////////////////////////////
DKCircle::DKCircle(DKObject *parent, DKPoint pos, DKSize siz)
{
	Create(parent,pos,siz);
}

////////////////////////////////////////////////////////////////
void DKCircle::Create(DKObject *parent, DKPoint pos, DKSize siz)
{
	name = "DKCircle";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	CalculateDraw();
	
	size = siz;

	segments = 100;
	filled = true;
	
	int count=0;
	for (GLfloat i = 0; i < 360.0f; i+=(360.0f/segments)){
		circle_vectors[count++] = (GLfloat)(cos(DEGREES_TO_RADIANS(i))*(size.x/2));
		circle_vectors[count++] = (GLfloat)(sin(DEGREES_TO_RADIANS(i))*(size.y/2));
	}
	for(int i=0; i<400; ++i){circle_colors[i] = 1.0f;}
	SetVisibility(true);
}

/////////////////////
DKCircle::~DKCircle()
{

}

////////////////////////////////////////////////////////////////////////
DKObject* DKCircle::NewCircle(DKObject *parent, DKPoint pos, DKSize siz)
{
	objects.push_back(new DKCircle(parent, pos, siz));
	return objects[objects.size() - 1];
}

//////////////////////////////////
void DKCircle::SetSize(DKSize siz)
{
	size = siz;
	int count=0;
	for (GLfloat i = 0; i < 360.0f; i+=(360.0f/segments)){
		circle_vectors[count++] = (GLfloat)(cos(DEGREES_TO_RADIANS(i))*(size.x/2));
		circle_vectors[count++] = (GLfloat)(sin(DEGREES_TO_RADIANS(i))*(size.y/2));
	}
}


///////////////////////////////////////////////////////////
void DKCircle::SetColor(DKColor rgba)
{
	color = rgba;

	for(int i=0; i<400; i=i+4){
		circle_colors[i] = color.r;
		circle_colors[i+1] = color.g;
		circle_colors[i+2] = color.b;
		circle_colors[i+3] = color.a;
	}
}

////////////////////////
void DKCircle::Display()
{
	if(NotVisible()){return;}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY); // enables the color-array.

	//glTranslatef(point.x+size.x, y_pos+size.y, 0.0);
	glColorPointer(4, GL_FLOAT, 0, circle_colors); //get the color
	glVertexPointer (2, GL_FLOAT , 0, circle_vectors); 

	//FIXME - causes weird stuff to happen in 3D view when we use z
	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, draw.z); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	//glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), -draw.z); //from top left
	//////////////////////////////////////////////////////////

	glDrawArrays ((filled) ? GL_TRIANGLE_FAN : GL_LINE_LOOP, 0, segments);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}