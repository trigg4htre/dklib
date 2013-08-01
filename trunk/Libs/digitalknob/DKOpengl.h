/// DKOpengl.h /////

#pragma once
#ifndef DKOpengl_h
#define DKOpengl_h

//OPENGL
#if defined (WIN32) || (WIN64) || (MAC) || (LINUX)
        #include "SDL_opengl.h"
#endif

//OPENGL ES
#if defined (ANDROID) || (IOS)
        #include "SDL_opengles.h"
#endif

#endif 