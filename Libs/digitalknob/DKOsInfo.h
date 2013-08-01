//// DKOsInfo.h ////

#pragma once
#ifndef DKOsInfo_H
#define DKOsInfo_H

#include "DKString.h"

#if defined (WIN32) || (WIN64)
#include "windows.h"
#include <sstream>
typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
typedef BOOL (WINAPI *PGPI)(DWORD, DWORD, DWORD, DWORD, PDWORD);
#define PRODUCT_PROFESSIONAL	0x00000030
#define VER_SUITE_WH_SERVER	0x00008000
#endif //WIN32 || WIN64

DKString GetOSCompany();
DKString GetOSName();
DKString GetOSVersion();
DKString GetOSServicePack();
DKString GetOSBuild();
DKString GetOSArchitecture();

#endif //DKOsInfo_H