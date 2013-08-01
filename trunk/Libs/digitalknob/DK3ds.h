//// DK3ds.h ////
//

#pragma once
#ifndef DK3DS_H
#define DK3DS_H

#pragma warning(disable: 4996) //Deprecation

#include "DKObject.h"
#include "DKOpenGl.h"

#include "SDL_image.h"
#include "lib3ds.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

typedef struct {
    GLuint tex_id; //OpenGL texture ID
    GLint w;
    GLint h;
    unsigned char *pixels;
} PlayerTexture;

//////////////////////////////
class DK3ds : public DKObject
{
public:
	DK3ds(){};
	DK3ds(DKObject *parent, DKString file, DKPoint pos);
	void Create(DKObject *parent, DKString file, DKPoint pos);
	~DK3ds();

	void Display();
	void render_node(Lib3dsNode *node);

	Lib3dsFile *model;
	float bmin[3], bmax[3];
	float sx, sy, sz, size; /* bounding box dimensions */
	float cx, cy, cz;  /* bounding box center */
	DKString camera;
	char datapath[256];
};

#endif //DK3DS_H
