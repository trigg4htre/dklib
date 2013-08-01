///// DKDebug.h ////

#pragma once
#ifndef DKDebug_H
#define DKDebug_H

#ifdef WIN32
	#include <windows.h>
#endif

#if defined (MAC) || (IOS)
	#import <Foundation/Foundation.h>
#endif

#ifdef ANDROID
	#include <android/log.h>
#endif

#include "DKString.h"

void DKDebug(DKString text);
void DKDebug(int text);
void DKDebug(float text);

#endif //DKDebug_H