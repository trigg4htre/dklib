//// DKImage.h ////

#pragma once
#ifndef DKIMAGE_H
#define DKIMAGE_H

#include "DKObject.h"
#include "DKFile.h"

#include "SDL_image.h"
#include <stdio.h>

class DKObject;

///////////////////////////////
class DKImage : public DKObject
{
public:
	DKImage(){};
	DKImage(DKObject *parent, DKPoint pos, DKString file);
	DKImage(DKObject *parent, DKPoint pos, const char* const* xpm);
	void Create(DKObject *parent, DKPoint pos, DKString file);
	void Create(DKObject *parent, DKPoint pos, const char* const* xpm);
	~DKImage();
	
	void SetFile(DKString file);
	void SetPosition(DKPoint pos);
	void SetSize(DKSize siz);
	void SetColor(DKColor rgba);
	int PowerOfTwo(int input);
	void Recalculate();
	void Reload();
	void Display();
	Uint32 GetPixel(int x, int y);

	GLuint image;
	DKString filename;
	char** xpm_image;
	GLfloat texture[8];
	GLfloat square[12];
	GLfloat t_color[16];
	SDL_Surface* surface;

	int pot_w; //used to rotate from original center of image
	int pot_h;

	static DKObject* NewImage(DKObject *parent, DKPoint pos, DKString file);
	static DKObject* NewImage(DKObject *parent, DKPoint pos, const char* const* xpm);
};

#endif //DKIMAGE_H