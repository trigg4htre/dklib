#include "SourceCode.h"

DKString SourceCode::project_path;

////////////////////////
void SourceCode::Write()
{
	project_path = "Projects/TestApp/";
	WriteAppSource();
	WriteMainWindowHeader();
	WriteMainWindowSource();
}

/////////////////////////////////
void SourceCode::WriteAppSource()
{
	DKString file_path = project_path + "app.cpp";
	DKString text = "";

	text += "/// app.cpp /////\n";
	text += "\n";
	text += "#ifdef WIN32\n";
    text += "	#define INIT_LEAK_FINDER\n";
    text += "	#include \"LeakFinder.h\"\n";
    text += "#endif //WIN32\n";
	text += "\n";
	text += "#include \"DK.h\"\n";
	text += "#include \"DKDebug.h\"\n";
	text += "#include \"MainWindow.h\"\n";
	text += "MainWindow *mainwindow\n";
	text += "\n";
	text += "////////////////////////////////\n";
	text += "int main(int argc, char *argv[])\n";
	text += "{\n";
	text += "	DKDebug(\"App Started\");\n";
	text += "	mainwindow = new MainWindow(\"TestAppp\",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,\n";
	text += "		SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);\n";
	text += "\n";
	text += "	mainwindow->Init();\n";
	text += "	mainwindow->Loop(); //Create Main Loop\n";
	text += "	delete mainwindow; //cleanup\n";
	text += "\n";
	text += "	exit(0); //FIXME - we need to return a value according to a possible error.\n";
	text += "}";

	SDL_RWops *rw = SDL_RWFromFile(file_path.c_str(),"w+");
	SDL_RWwrite(rw,text.c_str(),1,text.size());
	SDL_RWclose(rw);
}

////////////////////////////////////////
void SourceCode::WriteMainWindowHeader()
{
	DKString file_path = project_path + "MainWindow.h";
	DKString text = "";

	text += "///// MainWindow.h /////\n";
	text += "\n";
	text += "#ifndef MainWindow_H\n";
	text += "#define MainWindow_H\n";
	text += "\n";
	text += "#include \"SDL.h\"\n";
	text += "#include \"DKFrame.h\"\n";
	text += "\n";
	text += "/////////////////////////////////\n";
	text += "class MainWindow : public DKFrame\n";
	text += "{\n";
	text += "public:\n";
	text += "	MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags);\n";
	text += "	~MainWindow();\n";
	text += "	void Init();\n";
	text += "\n";
	text += "};";
	text += "\n";
	text += "#endif //MainWindow_H";

	SDL_RWops *rw = SDL_RWFromFile(file_path.c_str(),"w+");
	SDL_RWwrite(rw,text.c_str(),1,text.size());
	SDL_RWclose(rw);
}

////////////////////////////////////////
void SourceCode::WriteMainWindowSource()
{
	DKString file_path = project_path += "MainWindow.cpp";
	DKString text = "";

	text += "#include \"MainWindow.h\"\n";
	text += "\n";
	text += "//////////////////////////////////////////////////////////////////////////////////\n";
	text += "MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)\n";
	text += "	: DKFrame(caption, x, y, w, h, flags)\n";
	text += "{\n";
	text += "\n";
	text += "}\n";
	text += "\n";
	text += "///////////////////////\n";
	text += "void MainWindow::Init()\n";
	text += "{\n";
	text += "	SetColor(.1,.2,.3,1);\n";
	text += "}\n";
	text += "\n";
	text += "/////////////////////////\n";
	text += "MainWindow::~MainWindow()\n";
	text += "{\n";
	text += "	SDL_Quit();\n";
	text += "}\n";

	SDL_RWops *rw = SDL_RWFromFile(file_path.c_str(),"w+");
	SDL_RWwrite(rw,text.c_str(),1,text.size());
	SDL_RWclose(rw);
}