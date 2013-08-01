/// DKFile.h

#pragma once
#ifndef DKFile_H
#define DKFile_H

#include "DKDebug.h"
#include "SDL.h"
#include <stdio.h>
#include <fstream>

////////////
class DKFile
{
public:
	static void SetDataPath(DKString path);
	static DKString DataPath(DKString file);
	static bool FileExists(DKString filepath);

	static void GetDrives(DKStringArray &strings);
	static void GetDirectories(DKString path, DKStringArray &strings);
	static void GetFiles(DKString path, DKStringArray &strings);

	static DKString data_path;
};

#endif //DKFile_H