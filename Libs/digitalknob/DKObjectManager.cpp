#include "DKObjectManager.h"

//////////////////////////////////
DKObjectManager::DKObjectManager()
{

}

///////////////////////////////////
DKObjectManager::~DKObjectManager()
{

}

//////////////////////////////////////////////////////////////
void DKObjectManager::BringForward(unsigned int object_number)
{
	DKObject::BringForward(objects[current_object]);
	if(object_number < objects.size()-1){
		objects.insert(objects.begin()+object_number+2, objects[current_object]);
		objects.erase(objects.begin()+object_number);
		return;
	}
	else{
		BringToFront(current_object);
		return;
	}
}

//////////////////////////////////////////////////////////////
void DKObjectManager::SendBackward(unsigned int object_number)
{
	DKObject::SendBackward(objects[current_object]);
	objects.insert(objects.begin()+current_object-1, objects[current_object]);
	objects.erase(objects.begin()+current_object+1);
}

///////////////////////////////////////////////////////////////
void DKObjectManager::BringToFront(unsigned  int object_number)
{
	DKObject::BringToFront(objects[current_object]);
	objects.push_back(objects[object_number]);
	objects.erase(objects.begin()+object_number);
}

////////////////////////////////////////////////////////////
void DKObjectManager::SendToBack(unsigned int object_number)
{
	//FIXME  - i'm broken
	for(unsigned int i=0; i<objects.size(); i++){
	//	if(objects[i] == this){
			DKObject::MoveToSpot(objects[current_object], i+1);
			objects.insert(objects.begin(), objects[current_object]);
			objects.erase(objects.begin()+object_number+1);
	//	}
	}	
}

/////////////////////////////////////////////
void DKObjectManager::SetColor(DKColor color)
{
	objects[current_object]->SetColor(color);
}

//////////////////////////////////////////////////////////////////
void DKObjectManager::SetColor(float r, float g, float b, float a)
{
	objects[current_object]->SetColor(r,g,b,a);
}

//////////////////////////////////////////////
void DKObjectManager::SetPosition(DKPoint pos)
{
	objects[current_object]->SetPosition(pos);
}

/////////////////////////////////////////
void DKObjectManager::SetSize(DKSize siz)
{
	objects[current_object]->SetSize(siz);
}

//////////////////////////////////////////////////
void DKObjectManager::SetRotation(DKRotate rotate)
{
	objects[current_object]->SetRotation(rotate);
}

////////////////////////////////////////////
void DKObjectManager::SetScale(DKScale scal)
{
	objects[current_object]->SetScale(scal);
}

//////////////////////////////////////////
void DKObjectManager::SetDementions(int d)
{
	objects[current_object]->SetDementions(d);
}

///////////////////////////////////////////////////
void DKObjectManager::SetVisibility(bool truefalse)
{
	objects[current_object]->SetVisibility(truefalse);
}