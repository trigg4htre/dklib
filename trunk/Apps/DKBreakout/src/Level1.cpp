#include "Level1.h"

////////////////////////////////////////////////////////////
Level1::Level1(DKObject *parent, int x, int y, int w, int h)
	: DKPanel(parent, DKPoint(x,y), DKSize(w,h))
{
	SetColor(DKColor(0.1f,0.1f,0.1f,1));

	fps.Create(this,DKPoint(0,size.y-20),DKFont::fonts[0]);

	paddle.Create(this, DKPoint(size.x/2-50,size.y-30),DKSize(100,20));
	paddle.SetColor(DKColor(.5,0,0,1));

	ball.Create(this, DKPoint(size.x/2-5,size.y-39),DKSize(10,10));
	ball.SetColor(DKColor(1,1,1,1));

	for(int i=0; i<20; i++){  //create blocks
		blocks[i].Create(this, DKPoint(70+(i*32),100), DKSize(30,15));
		blocks[i].SetColor(DKColor(0,0,1,1));
	}

	angle = 0;
	xDirection = 0;
	yDirection = 0; //up
	
	inMotion = false;

	DKAnimate::Move(ball.object, DKPoint(size.x/2-50,0), 50);
}

////////////////////////////////////////////
void Level1::OnWindowClose(SDL_Event* event)
{
	DKAnimate::DeleteAll();
	if(event->window.windowID == 1){
		delete this;
		return;
	}
}

////////////////////////////////////////////////
void Level1::OnMouseButtonDown(SDL_Event* event)
{
	inMotion = true;
	SkipEvents();
}

////////////////////////////////////////////
void Level1::OnMouseMotion(SDL_Event* event)
{
	if(!inMotion){return;}
	paddle.SetPosition(DKPoint(event->button.x-50,size.y-30,0));
	SkipEvents();
	Update();
}

//////////////////////
void Level1::Process()
{
	//return;
	if(!inMotion){return;}
	if(DKObject::TestCollision(ball.object, paddle.object)){
		DKAnimate::Move(ball.object, DKPoint(ball.point.x+xDirection,0), 20);
	}
	for(int i=0; i<20; i++){
		if(DKObject::TestCollision(ball.object, blocks[i].object) && blocks[i].NotVisible() == false){
			if(blocks[i].color.r != 1){
				blocks[i].SetColor(DKColor(1,0,0,1));
			}
			else{
				blocks[i].SetVisibility(false);
			}
			DKAnimate::Move(ball.object, DKPoint(ball.point.x+xDirection,yDirection), 20);
			if(yDirection == 0){yDirection = (int)size.y;}
			else{yDirection = 0;}
		}
	}
	if(ball.point.y <= 0){
		DKAnimate::Move(ball.object, DKPoint(ball.point.x+xDirection,size.y), 20);
		if(yDirection == 0){yDirection = (int)size.y;}
		else{yDirection = 0;}
	}
	if(ball.point.x <= 0){
		if(xDirection == angle){xDirection = -angle;}
		else{xDirection = angle;}
		DKAnimate::Move(ball.object, DKPoint(ball.point.x+xDirection,yDirection), 20);
		
	}
	if(ball.point.x >= size.x-10){
		if(xDirection == angle){xDirection = -angle;}
		else{xDirection = angle;}
		DKAnimate::Move(ball.object, DKPoint(ball.point.x+xDirection,yDirection),20);
	}	
}

//////////////////////
//void Level1::Display()
//{
//	Display2DObjects(this);
//}