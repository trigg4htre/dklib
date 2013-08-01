/// DKGloabl.h ///////

// *** NOTE ***
//
// This is a good place to put global functions and variable until we find where they belong.
// It is good practice to move things where they really belong. 

#pragma once
#ifndef DKGLOBAL_H
#define DKGLOBAL_H

#include "DKObject.h"
#include "DKOpengl.h"

void DKClipStart(float x, float y, float w, float h, DKObject *frame);
void DKClipEnd();

#endif //DKGLOBAL_H