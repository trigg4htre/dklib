#include "DKString.h"

//////////////////////////
DKString toString(int num)
{
	DKString s;
	std::stringstream out;
	out << num;
	s = out.str();
	return s;
}

///////////////////////////////////
DKString toString(unsigned int num)
{
	DKString s;
	std::stringstream out;
	out << num;
	s = out.str();
	return s;
}

////////////////////////////
DKString toString(float num)
{
	DKString s;
	std::stringstream out;
	out << num;
	s = out.str();
	return s;
}

/////////////////////////////
DKString toString(double num)
{
	DKString s;
	std::stringstream out;
	out << num;
	s = out.str();
	return s;
}

/////////////////////////////////////
DKString toString(unsigned char* str) 
{
	return reinterpret_cast<char const*>(str);
}

#if defined (WIN32) || (WIN64)
//////////////////////////////////
DKString toString(std::wstring ws)
{
	int len;
    int slength = (int)ws.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, ws.c_str(), slength, 0, 0, 0, 0); 
    std::string s(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, ws.c_str(), slength, &s[0], len, 0, 0); 
    return s;
}

#endif // WIN32 || WIN64
