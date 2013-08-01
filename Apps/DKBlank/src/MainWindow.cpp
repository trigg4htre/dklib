#include "MainWindow.h"

//////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h),  flags)
{
}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");
	SetColor(DKColor(.1,.1,.2,1));

	DKXyz::NewXyz(this);
	DKFont* font = (DKFont*)DKFont::NewFont(this);
	DKMenuBar* menu = (DKMenuBar*)DKMenuBar::NewMenuBar(this, font, 1);
	menu->AddItem("File");
	menu->AddSelection("File", "Item 1",1);
	menu->AddSelection("File", "Item 2",2);
	DKText::NewText(this, DKPoint(10,30), font, "DigitalKnob Rocks!!!");
	DKSquare::NewSquare(this, DKPoint(10,50), DKSize(30, 30));
	DKCircle::NewCircle(this, DKPoint(50,50), DKSize(30, 30));
	DKButton::NewButton(this, DKPoint(10,100), DKFile::DataPath("imgbutton.png"), 13);
	DKTextButton::NewTextButton(this, DKPoint(10,150), font, "Text Button", 14);
	DKToggle::NewToggle(this, DKPoint(200,10), DKFile::DataPath("unchecked.png"), DKFile::DataPath("checked.png"), 8);
	DKTextBox::NewTextBox(this, DKPoint(200,40), DKSize(100,30), font, 1);
	DKSlider::NewSlider(this, DKPoint(260,80), DKFile::DataPath("back.png"), DKFile::DataPath("knob.png"), 1);
	/*
	DKDropDown* drop = (DKDropDown*)DKDropDown::NewDropDown(this, DKPoint(200,200), font, 1);
	drop->AddSelection("Item 1", 1);
	drop->AddSelection("Item 2", 2);
	drop->AddSelection("Item 3", 3);
	drop->AddSelection("Item 4", 4);
	drop->Show();
	*/

	DKObject* window2 = DKWindow::NewWindow(this, "Window 2", DKPoint(30,50), DKSize(150,200), SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	DKXyz::NewXyz(window2);
	DKFont* font2 = (DKFont*)DKFont::NewFont(this);
	window2->SetColor(DKColor(.1,.2,.1,1));
	DKText::NewText(window2, DKPoint(10,30), font2, "This is window 2");
	DKSquare::NewSquare(window2, DKPoint(10,50), DKSize(30, 30));
	DKCircle::NewCircle(window2, DKPoint(50,50), DKSize(30, 30));
	DKButton::NewButton(window2, DKPoint(10,100), DKFile::DataPath("imgbutton.png"), 13);
	DKTextButton::NewTextButton(window2, DKPoint(10,150), font2, "Text Button", 14);
	
	DKObject* window3 = DKWindow::NewWindow(this, "Window 3", DKPoint(30,300), DKSize(150,200), SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	DKXyz::NewXyz(window3);
	DKFont* font3 = (DKFont*)DKFont::NewFont(this);
	window3->SetColor(DKColor(.2,.1,.1,1));
	DKText::NewText(window3, DKPoint(10,30), font3, "This is window 3");
	DKSquare::NewSquare(window3, DKPoint(10,50), DKSize(30, 30));
	DKCircle::NewCircle(window3, DKPoint(50,50), DKSize(30, 30));
	DKButton::NewButton(window3, DKPoint(10,100), DKFile::DataPath("imgbutton.png"), 13);
	DKTextButton::NewTextButton(window3, DKPoint(10,150), font3, "Text Button", 14);

	DKObject* window4 = DKWindow::NewWindow(window3, "Window 4", DKPoint(30,550), DKSize(150,200), SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	DKXyz::NewXyz(window4);
	DKFont* font4 = (DKFont*)DKFont::NewFont(this);
	DKText::NewText(window4, DKPoint(10,30), font4, "This is window 4");
	DKSquare::NewSquare(window4, DKPoint(10,50), DKSize(30, 30));
	DKCircle::NewCircle(window4, DKPoint(50,50), DKSize(30, 30));
	DKButton::NewButton(window4, DKPoint(10,100), DKFile::DataPath("imgbutton.png"), 13);
	DKTextButton::NewTextButton(window4, DKPoint(10,150), font4, "Text Button", 14);

	//DKColorPicker::NewColorPicker(this, 15);

	//DKFileDialog::NewFileDialog(this, 15);

	DKObject *panel = DKPanel::NewPanel(this, DKPoint(300,10), DKSize(100,100));
	panel->SetColor(DKColor(1,1,1,1));

	DKCamera::Rotate(this,1,99999);
	//DKCamera::Rotate(window2,1,10000);
	//DKCamera::Rotate(window3,1,10000);
	//DKCamera::Rotate(window4,1,10000);

	
	//DK::NewLine(this, 0,0, 300,300); //FIXME Not working
	//DK::SetColor(DKColor(1,1,1,1));
	//DK::NewSquare(this, 10, 50, 20, 20);
	//DK::SetColor(DKColor(.1,.5,.3,1));
	//dko.NewTriangle(this, ????);
	//dko.SetColor(DKColor(.1,.1,.3,1));
	//DK::NewCircle(this, 40, 50, 20, 20);
	//dko.SetColor(DKColor(.5,.1,.3,1));

	/*
	textbutton1 = dko.NewTextButton(this, 10, 80, &font, "BUTTON");
	textbutton2 = dko.NewTextButton(this, 100, 80, &font, "BUTTON2");
	toggle1 = dko.NewToggle(this, 200, 80, DKFile::DataPath("unchecked.png"), DKFile::DataPath("checked.png"));
	dko.SetColor(DKColor(.6,.6,.8,1));
	dko.NewImage(this, 10, 110, DKFile::DataPath("logo.png"));
	button1 = dko.NewButton(this, 10, 270, DKFile::DataPath("imgbutton.png"));
	slider1 = dko.NewSlider(this, 250, 100, DKFile::DataPath("back.png"), DKFile::DataPath("knob.png"));
	dko.NewXyz(this);
	dko.NewCube(this, 0,0); //FIXME Not working
	dko.NewDropDown(this, 10, 320, &font);
	((DKDropDown*)dko.dk_objects[dko.current_object])->AddSelection("DropDown", 1);
	((DKDropDown*)dko.dk_objects[dko.current_object])->AddSelection("Item 2", 2);
	((DKDropDown*)dko.dk_objects[dko.current_object])->AddSelection("Item 3", 3);
	((DKDropDown*)dko.dk_objects[dko.current_object])->AddSelection("Item 4", 4);
	((DKDropDown*)dko.dk_objects[dko.current_object])->Show();

	int panel = dko.NewPanel(this, 160, 320, 100, 100);
	dko.SetColor(DKColor(.1,.6,.1,1));

	dko.NewText(dko.dk_objects[panel],10,10,&font,"Panel");
	dko.NewTextButton(dko.dk_objects[panel],5,30,&font,"Button");

	dko.NewTextBox(this,100,50,100,20,&font);

	scrollpanel1 = dko.NewScrollPanel(this, 10,400,80,80);

	dko.NewImage(dko.dk_objects[scrollpanel1], 0, 0, DKFile::DataPath("checkers.png"));


	dko.NewMenuBar(this, &font);
	((DKMenuBar*)dko.dk_objects[dko.current_object])->AddItem("MenuBar");
	((DKMenuBar*)dko.dk_objects[dko.current_object])->AddSelection("MenuBar", "Item 1", 1);
	((DKMenuBar*)dko.dk_objects[dko.current_object])->AddSelection("MenuBar", "Item 2", 2);

	//dko.NewWindow(this, 100,100,100,100, "New Window");
	//dko.NewColorPicker(this);

	dko.NewText(this, 300,300,&font,"text");
	*/
}

/////////////////////////
MainWindow::~MainWindow()
{
	
}

/////////////////////////////////////////
void MainWindow::OnButton(DKEvent* event)
{
	if(event->id == 13){
		DKDebug("Image Button 1 clicked!!! ;)\n");
	}
}

/////////////////////////////////////////////
void MainWindow::OnTextButton(DKEvent* event)
{
	if(event->id==14){
		DKDebug("Text Button 1 clicked!!! ;)\n");
	}
}

//////////////////////////////////
void MainWindow::OnColorPicker(DKEvent* event)
{
	DKDebug("Color Picker 1 clicked!!! ;)\n");
}

/////////////////////////////////////////
void MainWindow::OnToggle(DKEvent* event)
{
	DKDebug("Toggle 1 Clicked\n");

}

/////////////////////////////////////////
void MainWindow::OnSlider(DKEvent* event)
{
	if(event->id == 1){
		DKDebug("Slider 1 Moved!!! ;)\n");
	}
}

//////////////////////////////////////////
void MainWindow::OnMenuBar(DKEvent* event)
{
	if(event->id2 == 1){
		DKDebug("Menubar - Item 1 Clicked\n");
	}
	if(event->id2 == 2){
		DKDebug("Menubar - Item 2 Clicked\n");
	}
}

///////////////////////////////////////////
void MainWindow::OnDropDown(DKEvent* event)
{
	if(event->id2 == 1){
		DKDebug("Dropdown - Item 1 Clicked\n");
	}
	if(event->id2 == 2){
		DKDebug("Dropdown  - Item 2 Clicked\n");
	}
	if(event->id2 == 3){
		DKDebug("Dropdown  - Item 3 Clicked\n");
	}
	if(event->id2 == 4){
		DKDebug("Dropdown  - Item 4 Clicked\n");
	}
}