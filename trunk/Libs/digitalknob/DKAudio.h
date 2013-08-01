//// DKAudio.h ////

#pragma once
#ifndef DKAUDIO_H
#define DKAUDIO_H

#include "DKString.h"
#include "DKFile.h"

#include "SDL_mixer.h"
#include <stdio.h>
#define BUFFER 1024

//////////////
class DKAudio
{
public:
	DKAudio(DKString file);
	~DKAudio();
	void Play();

	Mix_Chunk *sound;
};

#endif //DKAUDIO_H
