#include "DKCube.h"


/////////////////////////////////////////////////////////
DKCube::DKCube(DKObject *parent, DKPoint pos, DKSize siz)
{
	Create(parent,pos,siz);
}

//////////////////////////////////////////////////////////////
void DKCube::Create(DKObject *parent, DKPoint pos, DKSize siz)
{
	name = "DKXyz";
	par = parent;
	point = pos;
	size = siz;
	frame = par->frame;
	win = par->win;

	/*
	front.Create(point.x,y_pos,z_pos,size.x,size.y,0,0,0);
	front.SetColor(0,0,1,1);
	back.Create(point.x,y_pos,z_pos+depth,size.x,size.y,0,0,0);
	back.SetColor(0,0,1,1);
	right.Create(point.x,y_pos,z_pos,size.x,size.y,0,-90,0);
	right.SetColor(1,0,0,1);
	left.Create(point.x+size.x,y_pos,z_pos,size.x,size.y,0,-90,0);
	left.SetColor(1,0,0,1);
	top.Create(point.x,y_pos,z_pos,size.x,size.y,90,0,0);
	top.SetColor(0,1,0,1);
	bottom.Create(x_pos,y_pos+size.y,z_pos,size.x,size.y,90,0,0);
	bottom.SetColor(0,1,0,1);
	*/
	
	SetVisibility(true);
}

/////////////////////
DKCube::~DKCube()
{

}

/////////////////////////////////////////
DKObject* DKCube::NewCube(DKObject *parent, DKPoint pos, DKSize siz)
{
	objects.push_back(new DKCube(parent, pos, siz));
	return objects[objects.size() - 1];
}

/////////////////////////////////////
void DKCube::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();

	front.SetPosition(point);
	back.SetPosition(DKPoint(point.x,point.y,point.z+size.z));
	right.SetPosition(point);
	left.SetPosition(DKPoint(point.x+size.x,point.y,point.z));
	top.SetPosition(point);
	bottom.SetPosition(DKPoint(point.x,point.y+size.y,point.z));
}

////////////////////////////////
void DKCube::SetSize(DKSize siz)
{
	size = siz;

	//front.SetPosition(x,y,z);
	back.SetPosition(DKPoint(point.x,point.y,point.z+size.z));
	//right.SetPosition(x,y,z);
	left.SetPosition(DKPoint(point.x+size.x,point.y,point.z));
	//top.SetPosition(x,y,z);
	bottom.SetPosition(DKPoint(point.x,point.y+size.y,point.z));

	front.SetSize(DKSize(size.x,size.y,0));
	back.SetSize(DKSize(size.x,size.y,0));
	right.SetSize(DKSize(size.x,size.y,0));
	left.SetSize(DKSize(size.x,size.y,0));
	top.SetSize(DKSize(size.x,size.y,0));
	bottom.SetSize(DKSize(size.x,size.y,0));
};


//////////////////////
void DKCube::Display()
{
	if(NotVisible()){return;}
	Display3DObjects(this);
}
