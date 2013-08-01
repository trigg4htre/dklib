#include "DKFile.h"

DKString DKFile::data_path = "../src/Data/"; //default for Visual Studio

///////////////////////////////////////
void DKFile::SetDataPath(DKString path)
{
	data_path = path;
}

////////////////////////////////////////
DKString DKFile::DataPath(DKString file)
{
	DKString fullpath;
	fullpath.append(data_path);
	fullpath.append(file);

	if(!DKFile::FileExists(fullpath)){ //windows visual c++ working directory to src directory check
		if(fullpath.size() > 6){
			fullpath.erase(0, 6); //remove the first ../../
		}
	}
	if(!DKFile::FileExists(fullpath)){
		fullpath.clear();
		fullpath.append("Data/");
		fullpath.append(file);   //check for it in Data/ folder
	}
	if(!DKFile::FileExists(fullpath)){
		fullpath.clear();
		fullpath.append(file); //check in root
	}
	if(!DKFile::FileExists(fullpath)){
		fullpath.clear();
		DKDebug("Cannot find file\n");
	}

	return fullpath;
}

//////////////////////////////////////////
bool DKFile::FileExists(DKString filepath)
{
	SDL_RWops *file = SDL_RWFromFile(filepath.c_str(), "r");
	if(file){
		SDL_RWclose(file);
		return true;
	}
	return false;
}

//////////////////////////////////////////////
void DKFile::GetDrives(DKStringArray &strings)
{
#if defined (WIN32) || (WIN64)
	TCHAR szDrive[] = " A:";
	DWORD drives = GetLogicalDrives();
	if(drives == 0){
		DKDebug("GetLogicalDrives() failed");
		return;
	}

	for (int i=0; i<26; i++){
		if((drives & (1 << i ))){
			TCHAR driveName[] = { TEXT('A') + i, TEXT(':'), TEXT('\0') }; 
			//DKDebug(driveName);
			//DKDebug("\n");
			strings.push_back(driveName);
		}
	}
#endif //(WIN32) || (WIN64)
}

//////////////////////////////////////////////////////////////////
void DKFile::GetDirectories(DKString path, DKStringArray &strings)
{
#if defined (WIN32) || (WIN64)
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	path = path + "\\*";
	hFind = FindFirstFile(path.c_str(), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE){
		DKDebug("DKFileDialog Error");
		return;
	} 
	else{
        DKDebug(FindFileData.cFileName);
		DKDebug("\n");
		while(FindNextFile(hFind, &FindFileData) != 0){
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
				//DKDebug(FindFileData.cFileName);
				//DKDebug("\n");
				//DKString temp = FindFileData.cFileName;
				//if(temp.compare(".") != 0 && temp.compare("..") != 0 ){
					strings.push_back(FindFileData.cFileName);
				//}
			}
		}
		FindClose(hFind);
	}
#endif //(WIN32) || (WIN64)
}

////////////////////////////////////////////////////////////
void DKFile::GetFiles(DKString path, DKStringArray &strings)
{
#if defined (WIN32) || (WIN64)
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	path = path + "\\*";
	hFind = FindFirstFile(path.c_str(), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE){
		DKDebug("DKFileDialog Error");
		return;
	} 
	else{
        DKDebug(FindFileData.cFileName);
		DKDebug("\n");
		while(FindNextFile(hFind, &FindFileData) != 0){
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE){
				//DKDebug(FindFileData.cFileName);
				//DKDebug("\n");
				//DKString temp = FindFileData.cFileName;
				//if(temp.compare(".") != 0 && temp.compare("..") != 0 ){
					strings.push_back(FindFileData.cFileName);
				//}
			}
		}
		FindClose(hFind);
	}
#endif //(WIN32) || (WIN64)
}