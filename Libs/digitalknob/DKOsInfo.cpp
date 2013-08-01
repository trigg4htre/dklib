#include "DKOSInfo.h"

#if defined (WIN32) || (WIN64)

////////////////////////
DKString GetOSCompany(){
	return "Microsoft";
}

/////////////////////
DKString GetOSName(){
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); 
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi); 

	if(bOsVersionInfoEx == 0){
		return false; // Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	}
	PGNSI pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if(NULL != pGNSI){
		pGNSI(&si);
	}
	else{ 
		GetSystemInfo(&si); // Check for unsupported OS
	}
	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId || osvi.dwMajorVersion <= 4 ){
		return false;
	}
	std::wstringstream os;
	if ( osvi.dwMajorVersion == 6 ){
		if(osvi.dwMinorVersion == 0){
			if(osvi.wProductType == VER_NT_WORKSTATION){
				os << "Windows Vista ";
			}
			else{
				os << "Windows Server 2008 ";
			}
		}  
		if (osvi.dwMinorVersion == 1){
			if(osvi.wProductType == VER_NT_WORKSTATION){
				os << "Windows 7 ";
			}
			else{
				os << "Windows Server 2008 R2 ";
			}
		}  
	}
	if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2){
		if(GetSystemMetrics(SM_SERVERR2)){
			os <<  "Windows Server 2003 R2, ";
		}
		else if (osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER){
			os <<  "Windows Storage Server 2003";
		}
		else if ( osvi.wSuiteMask & VER_SUITE_WH_SERVER ){
			os <<  "Windows Home Server";
		}
		else if( osvi.wProductType == VER_NT_WORKSTATION && si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64){
			os <<  "Windows XP Professional x64 Edition";
		}
		else{
			os << "Windows Server 2003, ";  // Test for the server type.
		}
	} 
	if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1){
		os << "Windows XP ";
	} 
	if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0){
		os << "Windows 2000 ";  
	}

	return toString(os.str());
}

////////////////////////
DKString GetOSVersion(){
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;
	DWORD dwType;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); 
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi); 

	if(bOsVersionInfoEx == 0){
		return false; // Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	}
	PGNSI pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if(NULL != pGNSI){
		pGNSI(&si);
	}
	else{ 
		GetSystemInfo(&si); // Check for unsupported OS
	}
	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId || osvi.dwMajorVersion <= 4 ){
		return false;
	}
	std::wstringstream os;
	if ( osvi.dwMajorVersion == 6 ){
		if(osvi.dwMinorVersion == 0){
			if(osvi.wProductType == VER_NT_WORKSTATION){
				//os << "Windows Vista ";
			}
			else{
				//os << "Windows Server 2008 ";
			}
		}  
		if (osvi.dwMinorVersion == 1){
			if(osvi.wProductType == VER_NT_WORKSTATION){
				//os << "Windows 7 ";
			}
			else{
				//os << "Windows Server 2008 R2 ";
			}
		}  
		PGPI pGPI = (PGPI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetProductInfo");
		pGPI( osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);  
		switch(dwType){
			case PRODUCT_ULTIMATE:
				os << "Ultimate Edition";
				break;
			case PRODUCT_PROFESSIONAL:
				os << "Professional";
				break;
			case PRODUCT_HOME_PREMIUM:
				os << "Home Premium Edition";
				break;
			case PRODUCT_HOME_BASIC:
				os << "Home Basic Edition";
				break;
			case PRODUCT_ENTERPRISE:
				os << "Enterprise Edition";
				break;
			case PRODUCT_BUSINESS:
				os << "Business Edition";
				break;
			case PRODUCT_STARTER:
				os << "Starter Edition";
				break;
			case PRODUCT_CLUSTER_SERVER:
				os << "Cluster Server Edition";
				break;
			case PRODUCT_DATACENTER_SERVER:
				os << "Datacenter Edition";
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				os << "Datacenter Edition (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER:
				os << "Enterprise Edition";
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				os << "Enterprise Edition (core installation)";
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				os << "Enterprise Edition for Itanium-based Systems";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER:
				os << "Small Business Server";
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				os << "Small Business Server Premium Edition";
				break;
			case PRODUCT_STANDARD_SERVER:
				os << "Standard Edition";
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				os << "Standard Edition (core installation)";
				break;
			case PRODUCT_WEB_SERVER:
				os << "Web Server Edition";
				break;
		}
	}
	if (osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2){
		if(GetSystemMetrics(SM_SERVERR2)){
			//os <<  "Windows Server 2003 R2, ";
		}
		else if (osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER){
			//os <<  "Windows Storage Server 2003";
		}
		else if ( osvi.wSuiteMask & VER_SUITE_WH_SERVER ){
			//os <<  "Windows Home Server";
		}
		else if( osvi.wProductType == VER_NT_WORKSTATION && si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64){
			//os <<  "Windows XP Professional x64 Edition";
		}
		else{
			//os << "Windows Server 2003, ";  // Test for the server type.
		}
		if (osvi.wProductType != VER_NT_WORKSTATION){
			if(si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64){
				if(osvi.wSuiteMask & VER_SUITE_DATACENTER){
					os <<  "Datacenter Edition for Itanium-based Systems";
				}
				else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE){
					os <<  "Enterprise Edition for Itanium-based Systems";
				}
			}   
			else if(si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64){
				if(osvi.wSuiteMask & VER_SUITE_DATACENTER){
					os <<  "Datacenter x64 Edition";
				}
				else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE){
					os <<  "Enterprise x64 Edition";
				}
				else{
					os <<  "Standard x64 Edition";
				}
			}
			else{
				if(osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER){
					os <<  "Compute Cluster Edition";
				}
				else if(osvi.wSuiteMask & VER_SUITE_DATACENTER){
					os <<  "Datacenter Edition";
				}
				else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE){
					os <<  "Enterprise Edition";
				}
				else if(osvi.wSuiteMask & VER_SUITE_BLADE){
					os <<  "Web Edition";
				}
				else{
					os <<  "Standard Edition";
				}
			}
		}
	} 
	if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1){
		//os << "Windows XP ";
		if(osvi.wSuiteMask & VER_SUITE_PERSONAL){
			os <<  "Home Edition";
		}
		else{
			os <<  "Professional";
		}
	} 
	if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0){
		//os << "Windows 2000 ";  
		if(osvi.wProductType == VER_NT_WORKSTATION){
			os <<  "Professional";
		}
		else{
			if(osvi.wSuiteMask & VER_SUITE_DATACENTER){
				os <<  "Datacenter Server";
			}
			else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE){
				os <<  "Advanced Server";
			}
			else{
				os <<  "Server";
			}
		}
	} 

	return toString(os.str());
}

///////////////////////////
DKString GetOSServicePack()
{
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); 
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi); 

	if(bOsVersionInfoEx == 0){
		return false; // Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	}
	PGNSI pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if(NULL != pGNSI){
		pGNSI(&si);
	}
	else{ 
		GetSystemInfo(&si); // Check for unsupported OS
	}
	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId || osvi.dwMajorVersion <= 4 ){
		return false;
	}
	std::wstringstream os;
	
	// Include service pack (if any). 
	if(wcslen((const wchar_t*)osvi.szCSDVersion) > 0){
		os << osvi.szCSDVersion;
	}
	else{
		os << L"Service Pack: none";
	}

	return toString(os.str());
}

/////////////////////
DKString GetOSBuild()
{
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); 
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi); 

	if(bOsVersionInfoEx == 0){
		return false; // Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	}
	PGNSI pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if(NULL != pGNSI){
		pGNSI(&si);
	}
	else{ 
		GetSystemInfo(&si); // Check for unsupported OS
	}
	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId || osvi.dwMajorVersion <= 4 ){
		return false;
	}
	std::wstringstream os;
	
	os << L"build " << osvi.dwBuildNumber; //Get Build

	return toString(os.str());
}

////////////////////////////
DKString GetOSArchitecture()
{
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX)); 
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi); 

	if(bOsVersionInfoEx == 0){
		return false; // Call GetNativeSystemInfo if supported or GetSystemInfo otherwise.
	}
	PGNSI pGNSI = (PGNSI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetNativeSystemInfo");
	if(NULL != pGNSI){
		pGNSI(&si);
	}
	else{ 
		GetSystemInfo(&si); // Check for unsupported OS
	}
	if(VER_PLATFORM_WIN32_NT != osvi.dwPlatformId || osvi.dwMajorVersion <= 4 ){
		return false;
	}
	std::wstringstream os;
	
	if(osvi.dwMajorVersion >= 6){
		if(si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64){
			os <<  "64-bit";
		}
		else if (si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_INTEL){
			os << "32-bit";
		}
	}
	else{
		os << "32-bit";
	}

	return toString(os.str());
}
#endif //WIN32 || WIN64

#if defined (MAC)
DKString GetOSCompany()
{
	return "Apple";
}
DKString GetOSName()
{
	return "MAC os_name";
}
DKString GetOSVersion()
{
	return "MAC os_version";
}
DKString GetOSServicePack()
{
	return "MAC os_servicepack";
}
DKString GetOSBuild()
{
	return "MAC os_build";
}
DKString GetOSArchitecture()
{
	return "MAC os_architecture";
}
#endif //MAC

#if defined (LINUX)
DKString GetOSCompany()
{
	return "Linux";
}
DKString GetOSName()
{
	return "LINUX os_name";
}
DKString GetOSVersion()
{
	return "LINUX os_version";
}
DKString GetOSServicePack()
{
	return "LINUX os_servicepack";
}
DKString GetOSBuild()
{
	return "LINUX os_build";
}
DKString GetOSArchitecture()
{
	return "LINUX os_architecture";
}
#endif //LINUX

#if defined (IOS)
DKString GetOSCompany()
{
	return "Apple";
}
DKString GetOSName()
{
	return "IOS os_name";
}
DKString GetOSVersion()
{
	return "IOS os_version";
}
DKString GetOSServicePack()
{
	return "IOS os_servicepack";
}
DKString GetOSBuild()
{
	return "IOS os_build";
}
DKString GetOSArchitecture()
{
	return "IOS os_architecture";
}
#endif //IOS

#if defined (ANDROID)
DKString GetOSCompany()
{
	return "Android";
}
DKString GetOSName()
{
	return "ANDROID os_name";
}
DKString GetOSVersion()
{
	return "ANDROID os_version";
}
DKString GetOSServicePack()
{
	return "ANDROID os_servicepack";
}
DKString GetOSBuild()
{
	return "ANDROID os_build";
}
DKString GetOSArchitecture()
{
	return "ANDROID os_architecture";
}
#endif //ANDROID

