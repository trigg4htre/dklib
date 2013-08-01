///// DKFont.h /////

#pragma once
#ifndef DKFONT_H
#define DKFONT_H

#include "DKObject.h"
#include "DKFile.h"

#include "arial.h"
#include "SDL.h"

#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
#include <FTGL/ftgl.h>
#endif
#if defined (IOS) || (ANDROID)
#include <FTGL/ftgles.h>
#endif

#include <vector>

//////////////////////////////
class DKFont : public DKObject
{
public:

	DKFont(){};
	DKFont(DKObject* parent);
	DKFont(DKObject* parent, DKString file);
	void Create(DKObject* parent);
	void Create(DKObject* parent, DKString file);
	~DKFont();

	int GetWidth(DKString text); 
	int GetHeight(); 

	DKString filename;
	unsigned char *buffer;
	FTGLTextureFont *texture_font;

	static DKObject* NewFont(DKObject* parent);
};

#endif //DKFONTS_H