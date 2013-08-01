#include "DKFont.h"

////////////////////////////////
DKFont::DKFont(DKObject* parent)
{
	Create(parent);
}

//////////////////////////////////////////////
DKFont::DKFont(DKObject* parent, DKString file)
{
	Create(parent, file);
}

/////////////////////////////////////
void DKFont::Create(DKObject* parent)
{
	name = "DKButton";
	par = parent;
	frame = par->frame;
	win = par->win;

	//SDL_GL_MakeCurrent(win, frame->context);
	texture_font = new FTGLTextureFont(arial_ttf, arial_ttf_size);
	//texture_font->UseDisplayList(false);
	texture_font->FaceSize(18);
}

///////////////////////////////////////////////////
void DKFont::Create(DKObject* parent, DKString file)
{
	if(!DKFile::FileExists(file)){
		texture_font = NULL;
		DKDebug("Font File Not Found\n");
		return;
	}
	DKObject::Create(parent, "DKFont");
	filename = file;
	SDL_RWops *filepath = SDL_RWFromFile(filename.c_str(), "rb");

	unsigned long fileLen;
	SDL_RWseek(filepath,0,SEEK_END);
	fileLen=(unsigned long)SDL_RWtell(filepath);
	SDL_RWseek(filepath,0,SEEK_SET);

	//Allocate memory
	buffer=(unsigned char *)malloc(fileLen+1);
	if (!buffer){
		DKDebug("Memory error!\n");
        SDL_RWclose(filepath);
		return;
	}

	//Read file contents into buffer
	SDL_RWread(filepath, buffer, fileLen, 1);
	SDL_RWclose(filepath);

	//SDL_GL_MakeCurrent(win, frame->context);
	texture_font = new FTGLTextureFont(buffer, fileLen);
	//texture_font->UseDisplayList(false);
	texture_font->FaceSize(18);
}

/////////////////
DKFont::~DKFont()
{
	if(texture_font != NULL){
		//free(buffer);
		delete texture_font;
	}
}

///////////////////////////////////////////
DKObject* DKFont::NewFont(DKObject* parent)
{
	objects.push_back(new DKFont(parent));
    return objects[objects.size() - 1];
}

///////////////////////////////////
int DKFont::GetWidth(DKString text)
{
	if(texture_font != NULL){
		return (int)texture_font->Advance(text.c_str(),-1,FTPoint());
	}
	return 0;
}

///////////////////////
int DKFont::GetHeight()
{
	if(texture_font != NULL){
		return (int)texture_font->Ascender()+(int)texture_font->Descender();
	}
	return 0;
}