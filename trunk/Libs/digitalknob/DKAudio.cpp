#include "DKAudio.h"

///////////////////////////////
DKAudio::DKAudio(DKString file)
{
	if(!DKFile::FileExists(file)){
		DKDebug("Audio File Does Not Exist\n");
		return;
	}
	Mix_Init(0);
	Mix_Quit(); //???
	int error = 0;
	error = Mix_OpenAudio(8000,MIX_DEFAULT_FORMAT,2,BUFFER);
	if(error){
		DKDebug("Audio Error");
	}

	Mix_AllocateChannels(10);

	sound = Mix_LoadWAV(file.c_str());
	if(!sound){
		//DKDebug(Mix_GetError());
	}
	Mix_VolumeMusic(64);
}

///////////////////
DKAudio::~DKAudio()
{
	Mix_FreeChunk(sound);
	Mix_CloseAudio();
}

void DKAudio::Play()
{
	Mix_PlayChannel(-1, sound, 0);
}