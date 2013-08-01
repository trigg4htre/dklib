#include "DKAnimate.h"

//define our static variables
std::vector<AnimateObject> DKAnimate::animations;

//////////////////////
DKAnimate::DKAnimate()
{

}

///////////////////////
DKAnimate::~DKAnimate()
{
	
}

///////////////////////////
void DKAnimate::DeleteAll()
{
	for(unsigned int i=0; i<animations.size(); ++i){
		animations.clear();
	}
}

//////////////////////////////////////////////////////////////////////////
void DKAnimate::Move(DKObject* object, DKPoint pos, int pixels_per_second)
{
	AnimateObject temp;
	temp.object = object;
	temp.the_command = 1;
	temp.start.x = object->point.x - object->par->point.x;
	temp.start.y = object->point.y - object->par->point.y;
	temp.start.z = object->point.z - object->par->point.z;
	temp.end.x = pos.x;
	temp.end.y = pos.y;
	temp.end.z = pos.z;
	temp.start_time = SDL_GetTicks();
	temp.pixels_per_second = pixels_per_second;

	for(unsigned int i=0; i<animations.size(); ++i){
		if(temp.object == animations[i].object &&
			temp.the_command == animations[i].the_command){
			animations[i] = temp;
			//return; 
		}
	}
	animations.push_back(temp);
}

////////////////////////////////////////////////////////////
void DKAnimate::Size(DKObject* object, DKSize siz, int time)
{
	AnimateObject temp;
	temp.object = object;
	temp.the_command = 2;
	temp.start.x = object->size.x;
	temp.start.y = object->size.y;
	temp.start.z = object->size.z;
	temp.end.x = siz.x;
	temp.end.y = siz.y;
	temp.end.z = siz.z;
	temp.start_time = SDL_GetTicks();
	temp.the_time = time;

	for(unsigned int i=0; i<animations.size(); ++i){
		if(temp.object == animations[i].object &&
			temp.the_command == animations[i].the_command){
			return; 
		}
	}
	animations.push_back(temp);
}

/////////////////////////////////////////////////////////////////////
void DKAnimate::Rotate(DKObject *object, DKRotate rotation, int time)
{
	AnimateObject temp;
	temp.object = object;
	temp.the_command = 3;
	temp.start.x = object->rotation.x;
	temp.start.y = object->rotation.y;
	temp.start.z = object->rotation.z;
	temp.end.x = rotation.x;
	temp.end.y = rotation.y;
	temp.end.z = rotation.z;
	temp.start_time = SDL_GetTicks();
	temp.the_time = time;

	for(unsigned int i=0; i<animations.size(); ++i){
		if(temp.object == animations[i].object &&
			temp.the_command == animations[i].the_command){
			return; 
		}
	}
	animations.push_back(temp);
}

////////////////////////////////////////////////////////////////
void DKAnimate::Scale(DKObject* object, DKScale scale, int time)
{
	AnimateObject temp;
	temp.object = object;
	temp.the_command = 4;
	temp.start.x = object->scale.x;
	temp.start.y = object->scale.y;
	temp.start.z = object->scale.z;
	temp.end.x = scale.x;
	temp.end.y = scale.y;
	temp.end.z = scale.z;
	temp.x_direction = 1;
	temp.y_direction = 1;
	temp.z_direction = 1;
	temp.start_time = SDL_GetTicks();
	temp.the_time = time;

	for(unsigned int i=0; i<animations.size(); ++i){
		if(temp.object == animations[i].object &&
			temp.the_command == animations[i].the_command){
			return; 
		}
	}
	animations.push_back(temp);
}

/////////////////////////
void DKAnimate::Animate()
{
	for(unsigned int i=0; i<animations.size(); ++i){
		if(animations[i].the_command == 1){
			DoMove(&animations[i]);
		}
		else if(animations[i].the_command == 2){
			DoSize(&animations[i]);
		}
		else if(animations[i].the_command == 3){
			DoRotate(&animations[i]);
		}
		else if(animations[i].the_command == 4){
			DoScale(&animations[i]);
		}
	}
}

////////////////////////////////////////////////
void DKAnimate::DoMove(AnimateObject *theObject)
{
	int currTime = SDL_GetTicks();
	int elapsed = currTime - theObject->start_time;
	/*
	if(elapsed < theObject->the_time){
		int xDistance = theObject->end.x - theObject->start.x;
		int yDistance = theObject->end.y - theObject->start.y;
		int zDistance = theObject->end.z - theObject->start.z;
		int x = theObject->start.x + (xDistance * elapsed / theObject->the_time);
		int y = theObject->start.y + (yDistance * elapsed / theObject->the_time);
		int z = theObject->start.z + (zDistance * elapsed / theObject->the_time);
		theObject->theObject->SetPosition(x, y, z);
	}
	*/
	if(theObject->object->point.x != theObject->end.x ||
	   theObject->object->point.y != theObject->end.y ||
	   theObject->object->point.z != theObject->end.z){
		if(theObject->end.x < theObject->start.x){theObject->x_direction = -1;}
		if(theObject->end.y < theObject->start.y){theObject->y_direction = -1;}
		if(theObject->end.z < theObject->start.z){theObject->z_direction = -1;}

		int x = (int)(theObject->start.x + (theObject->x_direction * elapsed * .001 * theObject->pixels_per_second));
		int y = (int)(theObject->start.y + (theObject->y_direction * elapsed * .001 * theObject->pixels_per_second));
		int z = (int)(theObject->start.z + (theObject->z_direction * elapsed * .001 * theObject->pixels_per_second));
		theObject->object->SetPosition(DKPoint(x,y));
	}
	else{
		for(unsigned int i=0; i<animations.size(); ++i){
			if(theObject == &animations[i]){
				animations.erase(animations.begin()+i);
			}
		}
	}
}

////////////////////////////////////////////////
void DKAnimate::DoSize(AnimateObject *theObject)
{
	int currTime = SDL_GetTicks();
	int elapsed = currTime - theObject->start_time;
	if(elapsed < theObject->the_time){
		float xDistance = theObject->end.x - theObject->start.x;
		float yDistance = theObject->end.y - theObject->start.y;
		float zDistance = theObject->end.z - theObject->start.z;
		int x = (int)theObject->start.x + (int)(xDistance * elapsed / theObject->the_time);
		int y = (int)theObject->start.y + (int)(yDistance * elapsed / theObject->the_time);
		int z = (int)theObject->start.z + (int)(zDistance * elapsed / theObject->the_time);
		theObject->object->SetSize(DKSize(x,y,z));
	}
	else{
		for(unsigned int i=0; i<animations.size(); ++i){
			if(theObject == &animations[i]){
				animations.erase(animations.begin()+i);
			}
		}
	}
}

//////////////////////////////////////////////////
void DKAnimate::DoRotate(AnimateObject *theObject)
{
	int currTime = SDL_GetTicks();
	int elapsed = currTime - theObject->start_time;
	if(elapsed < theObject->the_time){
		float xDistance = (float)theObject->end.x - (float)theObject->start.x;
		float yDistance = (float)theObject->end.y - (float)theObject->start.y;
		float zDistance = (float)theObject->end.z - (float)theObject->start.z;
		float x = (float)theObject->start.x + ((float)xDistance * (float)elapsed / (float)theObject->the_time);
		float y = (float)theObject->start.y + ((float)yDistance * (float)elapsed / (float)theObject->the_time);
		float z = (float)theObject->start.z + ((float)zDistance * (float)elapsed / (float)theObject->the_time);
		theObject->object->SetRotation(DKRotate(x,y,z));
	}
	else{
		for(unsigned int i=0; i<animations.size(); ++i){
			if(theObject == &animations[i]){
				animations.erase(animations.begin()+i);
			}
		}
	}
}

/////////////////////////////////////////////////
void DKAnimate::DoScale(AnimateObject *theObject)
{
	int currTime = SDL_GetTicks();
	int elapsed = currTime - theObject->start_time;
	if(elapsed < theObject->the_time){
		float xDistance = (float)theObject->end.x - (float)theObject->start.x;
		float yDistance = (float)theObject->end.y - (float)theObject->start.y;
		float zDistance = (float)theObject->end.z - (float)theObject->start.z;
		float x = (float)theObject->start.x + ((float)xDistance * (float)elapsed / (float)theObject->the_time);
		float y = (float)theObject->start.y + ((float)yDistance * (float)elapsed / (float)theObject->the_time);
		float z = (float)theObject->start.z + ((float)zDistance * (float)elapsed / (float)theObject->the_time);
		theObject->object->SetScale(DKScale(x,y,z));
	}
	else{
		for(unsigned int i=0; i<animations.size(); ++i){
			if(theObject == &animations[i]){
				animations.erase(animations.begin()+i);
			}
		}
	}
}