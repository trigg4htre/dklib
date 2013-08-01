#include "MainWindow.h"

///////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(DKString caption, int x, int y, int w, int h, Uint32 flags)
	: DKFrame(caption, DKPoint(x,y), DKSize(w,h),  flags)
{
}

///////////////////////
void MainWindow::Init()
{
	DKDebug("MainWindow Init\n");
	SetColor(DKColor(.5,.5,.5,1));

	font.Create(this);
	title.Create(this,DKPoint(5,5),&font,"SYSTEM INFORMATION");

	os_company.Create(this,DKPoint(5,45),&font,"OS Company:  "+GetOSCompany());
	os_name.Create(this,DKPoint(5,65),&font,"OS Name:  "+GetOSName());
	os_version.Create(this,DKPoint(5,85),&font,"OS Version:  "+GetOSVersion());
	os_servicepack.Create(this,DKPoint(5,105),&font,"OS Service Pack:  "+GetOSServicePack());
	os_build.Create(this,DKPoint(5,125),&font,"OS Build:  "+GetOSBuild());
	os_architecture.Create(this,DKPoint(5,145),&font,"OS Arch:  "+GetOSArchitecture());

	//FIXME - need error protection on glGetString
	gl_vendor.Create(this,DKPoint(5,175),&font,("OpenGL Vendor:  "+toString((unsigned char*)glGetString(GL_VENDOR))));
	gl_renderer.Create(this,DKPoint(5,195),&font,("OpenGL Renderer:  "+toString((unsigned char*)glGetString(GL_RENDERER))));
	gl_version.Create(this,DKPoint(5,215),&font,("OpenGL Version:  "+toString((unsigned char*)glGetString(GL_VERSION))));
}

/////////////////////////
MainWindow::~MainWindow()
{
	DKDebug("App Exited\n");
	SDL_Quit();
}