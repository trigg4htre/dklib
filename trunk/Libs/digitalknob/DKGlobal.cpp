#include "DKGlobal.h"

// *** NOTE ***
//
// This is a good place to put global functions and variable until we find where they belong.
// It is good practice to move things where they really belong. 


void DKClipStart(float x, float y, float w, float h, DKObject *frame)
{
	glEnable(GL_SCISSOR_TEST);
	glScissor((int)x,(int)frame->size.y-(int)y-(int)h,(int)w,(int)h);
}

void DKClipEnd()
{
	glDisable(GL_SCISSOR_TEST);
}


