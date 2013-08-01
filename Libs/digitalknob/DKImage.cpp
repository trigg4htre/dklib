#include "DKImage.h"

//////////////////////////////////////////////////////////////
DKImage::DKImage(DKObject *parent, DKPoint pos, DKString file) 
{
	Create(parent,pos,file);
}

///////////////////////////////////////////////////////////////////////
DKImage::DKImage(DKObject *parent, DKPoint pos, const char* const* xpm)
{
	Create(parent,pos,xpm);
}

//////////////////////////////////////////////////////////////////
void DKImage::Create(DKObject *parent, DKPoint pos, DKString file)
{
	if(!DKFile::FileExists(file)){
		DKDebug("Image File Does Not Exist\n");
		return;
	}
	name = "DKImage";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	point = pos;
	CalculateDraw();

	SetColor(DKColor(1,1,1,1));
	Recalculate();

	filename = file;
	glGenTextures(1,&image);
	Reload();
	SetVisibility(true);
}

///////////////////////////////////////////////////////////////////////////
void DKImage::Create(DKObject *parent, DKPoint pos, const char* const* xpm)
{
	name = "DKImage";
	par = parent;
	point = pos;
	frame = par->frame;
	win = par->win;
	point = pos;
	CalculateDraw();

	SetColor(DKColor(1,1,1,1));
	Recalculate();

	filename = "XPM";
	xpm_image = (char**)xpm;
	glGenTextures(1,&image);
	Reload();
	SetVisibility(true);
}

///////////////////
DKImage::~DKImage()
{
	//glDeleteTextures(1, &dkimage);  //Delete our texture
	//SDL_FreeSurface(surface);
}

/////////////////////////////////////////////////////////////////////////
DKObject* DKImage::NewImage(DKObject *parent, DKPoint pos, DKString file)
{
	objects.push_back(new DKImage(parent, pos, file));
	return objects[objects.size() - 1];
}

//////////////////////////////////////////////////////////////////////////////////
DKObject* DKImage::NewImage(DKObject *parent, DKPoint pos, const char* const* xpm)
{
	objects.push_back(new DKImage(parent, pos, xpm));
	return objects[objects.size() - 1];
}

///////////////////////////
void DKImage::Recalculate()
{
	texture[0] = 0.0f;
	texture[1] = 1.0f;    
    texture[2] = 0.0f;
	texture[3] = 0.0f;
    texture[4] = 1.0f;
	texture[5] = 1.0f;
    texture[6] = 1.0f;
	texture[7] = 0.0f;
	square[0] = draw.x;
	square[1] = draw.y+pot_h;
	square[2] = draw.z;
	square[3] = draw.x;
	square[4] = draw.y;
	square[5] = draw.z;
	square[6] = draw.x+pot_w;
	square[7] = draw.y+pot_h;
	square[8] = draw.z;
	square[9] = draw.x+pot_w;
	square[10] = draw.y;
	square[11] = draw.z;
	t_color[0] = color.r;//1.0f;
	t_color[1] = color.g;//1.0f;
	t_color[2] = color.b;//1.0f;
	t_color[3] = color.a;//1.0f;
	t_color[4] = color.r;//1.0f;
	t_color[5] = color.g;//1.0f;
	t_color[6] = color.b;//1.0f;
	t_color[7] = color.a;//1.0f;
	t_color[8] = color.r;//1.0f;
	t_color[9] = color.g;//1.0f;
	t_color[10] = color.b;//1.0f;
	t_color[11] = color.a;//1.0f;
	t_color[12] = color.r;//1.0f;
	t_color[13] = color.g;//1.0f;
	t_color[14] = color.b;//1.0f;
	t_color[15] = color.a;//1.0f;
}

///////////////////////////////////////
void DKImage::SetFile(DKString file)
{
	filename = file;
	glGenTextures(1,&image);
	Reload();
}

//////////////////////////////////////
void DKImage::SetPosition(DKPoint pos)
{
	point = pos;
	CalculateDraw();
	Recalculate();
	Update();
}

/////////////////////////////////
void DKImage::SetSize(DKSize siz)
{
	pot_w += (int)(siz.x - size.x);
	pot_h += (int)(siz.y - size.y);
	size = siz;
	Recalculate();
}

////////////////////////////////////
void DKImage::SetColor(DKColor rgba)
{
	color = rgba;
	Recalculate();
}

///////////////////////
void DKImage::Display()
{
	if(NotVisible()){return;}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, image); // select our current texture
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glColorPointer(4, GL_FLOAT, 0, t_color); //get the color
	glVertexPointer(3, GL_FLOAT, 0, square);
    glTexCoordPointer(2, GL_FLOAT, 0, texture);

	////  Transformations ////////////////////////////////////
	glTranslatef(draw.x+size.x/2, draw.y+size.y/2, 0); //from top left
	glRotatef(rotation.x,1,0,0);
	glRotatef(rotation.y,0,1,0);
	glRotatef(rotation.z,0,0,1);
	glScalef(scale.x,scale.y,scale.z);
	glTranslatef(-(draw.x+size.x/2),-(draw.y+size.y/2), 0); //from top left
	//////////////////////////////////////////////////////////

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY); // enables the color-array.
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

//////////////////////////////////
int DKImage::PowerOfTwo(int input)
{
	int value = 1;
	while ( value < input ){
		value <<= 1;
	}
	return value;
}

//////////////////////
void DKImage::Reload()
{
	//SDL_GL_MakeCurrent(win, frame->context);

	SDL_Surface* surface2;
	SDL_Rect area;

	if(filename.compare("XPM") != 0){
		surface = IMG_Load(filename.c_str());
	}
	else{
		surface = IMG_ReadXPMFromArray(xpm_image);
	}

	if(surface == NULL){
		SetVisibility(false);
		SDL_FreeSurface(surface);
		return;
	}

	size.x = (float)surface->w;
	size.y = (float)surface->h;
	pot_w = PowerOfTwo(surface->w);
	pot_h = PowerOfTwo(surface->h);

	surface2 = SDL_CreateRGBSurface(SDL_SWSURFACE,pot_w,pot_h,32,
#if SDL_BYTEORDER == SDL_LIL_ENDIAN /* OpenGL RGBA masks */
			0x000000FF, 
			0x0000FF00, 
			0x00FF0000, 
			0xFF000000
#else
			0xFF000000,
			0x00FF0000, 
			0x0000FF00, 
			0x000000FF
#endif
	);
	if(surface2 == NULL){return;}

	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_NONE);

	/* Copy the surface into the GL texture image */
	area.x = 0;
	area.y = 0;
	area.w = surface->w;
	area.h = surface->h;
	SDL_BlitSurface(surface, &area, surface2, &area);

	glPixelStorei(GL_UNPACK_ALIGNMENT,4);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	
	if (surface2->format->Amask){ //alpha
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pot_w, pot_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface2->pixels);
	}
	else{ //no alpha
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, pot_w, pot_h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface2->pixels);
	}
	glDisable(GL_TEXTURE_2D);

	Recalculate();
}

//////////////////////////////////////
Uint32 DKImage::GetPixel(int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}