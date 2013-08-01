#include "DKCamera.h"

//define our static variables
std::vector<CameraObject> DKCamera::cameras;

////////////////////
DKCamera::DKCamera()
{

}

DKCamera::~DKCamera()
{

}

/////////////////////////////////////////////////////////////
void DKCamera::Rotate(DKFrameBase *frame, int axis, int time)
{
	CameraObject temp;
	temp.the_frame = frame;
	temp.the_command = 2;
	temp.axis = axis;
	temp.start_time = SDL_GetTicks();
	temp.time = time;

	for(unsigned int i=0; i<cameras.size(); ++i){
		if(temp.the_frame == cameras[i].the_frame &&
			temp.the_command == cameras[i].the_command){
			return; 
		}
	}
	cameras.push_back(temp);
	DKObject::Update();
};

////////////////////////
void DKCamera::Animate()
{
	for(unsigned int i=0; i<cameras.size(); ++i){
		if(cameras[i].the_command == 1){
		//	DoMove(&cameras[i]);
		}
		else if(cameras[i].the_command == 2){
			DoRotate(&cameras[i]);
			DKObject::Update();
		}
	}
}

////////////////////////////////////////////////
void DKCamera::DoRotate(CameraObject *theCamera)
{
	int currTime = SDL_GetTicks();
	int elapsed = currTime - theCamera->start_time;
	if(elapsed < theCamera->time){
		theCamera->angle -= 360.00f/(theCamera->time);
		theCamera->the_frame->eye_x=0.5f*cos(theCamera->angle);
		theCamera->the_frame->eye_z=0.5f*sin(theCamera->angle);
	}
	else{
		for(unsigned int i=0; i<cameras.size(); ++i){
			if(theCamera == &cameras[i]){
				cameras.erase(cameras.begin()+i);
			}
		}
	}
}

