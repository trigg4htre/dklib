#include "DKXyz.h"

//////////////////////////////
DKXyz::DKXyz(DKObject* parent)
{
	Create(parent);
}

////////////////////////////////////
void DKXyz::Create(DKObject* parent)
{
	name = "DKXyz";
	par = parent;
	frame = par->frame;
	win = par->win;

	dimensions = 3;
	lineX[0] = -1000.0f;
	lineX[1] = 0.0f;
	lineX[2] = 0.0f;
	lineX[3] = 1000.0f;
	lineX[4] = 0.0f;
	lineX[5] = 0.0f;

	lineY[0] = 0.0f;
	lineY[1] = -1000.0f;
	lineY[2] = 0.0f;
	lineY[3] = 0.0f;
	lineY[4] = 1000.0f;
	lineY[5] = 0.0f;

	lineZ[0] = 0.0f;
	lineZ[1] = 0.0f;
	lineZ[2] = -1000.0f;
	lineZ[3] = 0.0f;
	lineZ[4] = 0.0f;
	lineZ[5] = 1000.0f;

	colorX[0] = 0.0f; //r
	colorX[1] = 1.0f; //g
	colorX[2] = 0.0f; //b
	colorX[3] = 1.0f; //alpha
	colorX[4] = 0.0f; //r
	colorX[5] = 1.0f; //g
	colorX[6] = 0.0f; //b
	colorX[7] = 1.0f; //alpha

	colorY[0] = 1.0f; //r
	colorY[1] = 0.0f; //g
	colorY[2] = 0.0f; //b
	colorY[3] = 1.0f; //alpha
	colorY[4] = 1.0f; //r
	colorY[5] = 0.0f; //g
	colorY[6] = 0.0f; //b
	colorY[7] = 1.0f; //alpha

	colorZ[0] = 0.0f; //r
	colorZ[1] = 0.0f; //g
	colorZ[2] = 1.0f; //b
	colorZ[3] = 1.0f; //alpha
	colorZ[4] = 0.0f; //r
	colorZ[5] = 0.0f; //g
	colorZ[6] = 1.0f; //b
	colorZ[7] = 1.0f; //alpha

	SetVisibility(true);
}

/////////////////////////
DKXyz::~DKXyz()
{

}

/////////////////////////////////////////
DKObject* DKXyz::NewXyz(DKObject *parent)
{
	objects.push_back(new DKXyz(parent));
	return objects[objects.size() - 1];
}

//////////////////////////
void DKXyz::Display()
{
	if(NotVisible()){return;}

	glLineWidth(1);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_CULL_FACE);

	glVertexPointer(3, GL_FLOAT, 0, lineY);
	glColorPointer(4, GL_FLOAT, 0, colorY);
	glDrawArrays(GL_LINES, 0, 2);

	glVertexPointer(3, GL_FLOAT, 0, lineX);
	glColorPointer(4, GL_FLOAT, 0, colorX);
	glDrawArrays(GL_LINES, 0, 2);

	glVertexPointer(3, GL_FLOAT, 0, lineZ);
	glColorPointer(4, GL_FLOAT, 0, colorZ);
	glDrawArrays(GL_LINES, 0, 2);


	glDisable(GL_CULL_FACE);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); // enables the color-array.
}