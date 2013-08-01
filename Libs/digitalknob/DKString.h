//// DKString.h ////

#pragma once
#ifndef DKString_H
#define DKString_H

#if defined (WIN32) || (WIN64)
#include "windows.h"
#endif //WIN32 || WIN64

#include <vector>
#include <string>
#include <sstream>
#include "DKOpengl.h"
using namespace std;

typedef std::string DKString;
typedef std::vector<DKString> DKStringArray;

DKString toString(int num);
DKString toString(unsigned int num);
DKString toString(float num);
DKString toString(double num);
DKString toString(unsigned char* str);

#if defined (WIN32) || (WIN64)
DKString toString(std::wstring ws);
#endif //WiN32 || WIN64

#endif //DKString_H