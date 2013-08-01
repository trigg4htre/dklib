#include "MainWindow.h"


//////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h), flags)
{
	
}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");
	SetColor(DKColor(0.1f,0.2f,0.3f,1));

	xyz.Create(this);
	font.Create(this);
	fps.Create(this, DKPoint(0,frame->size.y-25), &font);
	text.Create(this,DKPoint(0,0), &font, "DKTestApp");
	text.SetColor(DKColor(1,0,0,1));
	image.Create(this,DKPoint(0,30),DKFile::DataPath("newpanel.png"));
	button1.Create(this,DKPoint(5,170),&font,"Spin XYZ");
	button1.LinkTextButtonEvent(TextButtonEvent,this,1);

	//DKFileDialog *file_dialog = new DKFileDialog(this);
	//file_dialog->LinkFileDialogEvent(FileDialogEvent, this, 1);

	/*
	DKStringArray drives;
	DKFile::GetDrives(drives);
	for(int i=0; i<drives.size(); ++i){
		DKDebug(drives[i]);
		DKDebug("\n");
	}

	DKStringArray directories;
	DKFile::GetDirectories("C:\\Windows\\", directories);
	for(int i=0; i<directories.size(); ++i){
		DKDebug(directories[i]);
		DKDebug("\n");
	}
	
	DKStringArray files;
	DKFile::GetFiles("C:\\Windows\\", files);
	for(int i=0; i<files.size(); ++i){
		DKDebug(files[i]);
		DKDebug("\n");
	}
	*/
}

/////////////////////////
MainWindow::~MainWindow()
{
	DKDebug("App Exited\n");
	SDL_Quit();
}

/////////////////////////////////////////////
void MainWindow::OnTextButton(DKEvent* event)
{
	if(event->id == 1){
		DKCamera::Rotate(this,1,10000);
	}
}

/*
/////////////////////////////////////////////
void MainWindow::OnFileDialog(DKEvent* event)
{
	DKDebug( ((DKFileDialog*)event)->full_path );
}
*/