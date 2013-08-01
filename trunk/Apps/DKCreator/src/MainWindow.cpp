#include "MainWindow.h"


//////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h), flags)
{

}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");
	SetColor(DKColor(0.1f,0.2f,0.3f,1));

	font.Create(this);
	viewport.Create(this,20,100,640,480);

	dko.NewButton(this,0,23,DKFile::DataPath("windows.png"));
	//dko.dk_objects[dko.current_object]->LinkButtonEvent(ButtonEvent,this,1);
	
	//windows.Create(this,DKPoint(0,23),DKFile::DataPath("windows.png"));
	//windows.LinkButtonEvent(ButtonEvent,this,1);
	mac.Create(this,DKPoint(40,23),DKFile::DataPath("mac.png"));
	mac.LinkButtonEvent(ButtonEvent,this,2);
	linux.Create(this,DKPoint(80,23),DKFile::DataPath("linux.png"));
	linux.LinkButtonEvent(ButtonEvent,this,3);
	android.Create(this,DKPoint(120,23),DKFile::DataPath("android.png"));
	android.LinkButtonEvent(ButtonEvent,this,4);
	iphone.Create(this,DKPoint(160,23),DKFile::DataPath("iphone.png"));
	iphone.LinkButtonEvent(ButtonEvent,this,5);

	menu.Create(this,DKFont::fonts[0]);
	menu.LinkMenuBarEvent(MenuBarEvent, this,1);
	menu.AddItem("File");
	menu.AddItem("Edit");
	menu.AddItem("View");
	menu.AddSelection("File","New Project",1);
	menu.AddSelection("File","Export Source Code",2);
	menu.AddSelection("File","Exit",3);
	
	//Maximize(); //can't do this until windows is created
	//SourceCode::Write();  //creates app.cpp, MainWindow.h and MainWindow.cpp

	fs.Create(this,DKPoint(200,20),&font, "Fullscreen");
	fs.LinkTextButtonEvent(TextButtonEvent, this, 1);
}

/////////////////////////
MainWindow::~MainWindow()
{
	DKDebug("App Exited\n");
	SDL_Quit();
}

//////////////////////////////////////////
void MainWindow::OnMenuBar(DKEvent* event)
{
	if(event->id2==1){
		DKDebug("New Project cliecked\n");
		new_project = new NewProject(this, size.x/2-200, size.y/2-100, 400,200);
	}
	if(event->id2==2){
		DKDebug("Export Source Code clicked\n");
		//TODO
	}
	if(event->id2==3){
		DKDebug("Exit clicked\n");
		Exit();
	}
}

/////////////////////////////////////
void MainWindow::OnTextButton(DKEvent* event)
{
	if(event->id==1){
		Fullscreen(DKSize(800,600));
	}
}

/////////////////////////////////
void MainWindow::OnButton(DKEvent* event)
{
	if(event->id == 1){
		DKDebug("Windows clicked\n");
		viewport.SetSize(DKSize(640,480));
		Update();
	}
	if(event->id == 2){
		DKDebug("Mac clicked\n");
		viewport.SetSize(DKSize(640,480));
		Update();
	}
	if(event->id == 3){
		DKDebug("Linux clicked\n");
		viewport.SetSize(DKSize(640,480));
		Update();
	}
	if(event->id == 4){
		DKDebug("Android clicked\n");
		viewport.SetSize(DKSize(320,480));
		Update();
	}
	if(event->id == 5){
		DKDebug("iPhone clicked\n");
		viewport.SetSize(DKSize(320,480));
		Update();
	}
}



