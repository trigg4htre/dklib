///// SourceCode.h /////

#ifndef SourceCode_H
#define SourceCode_H

#include "DK.h"

////////////////
class SourceCode
{
public:
	SourceCode(){};
	~SourceCode(){};

	static void Write();
	static void WriteAppSource(); //app.cpp
	static void WriteMainWindowHeader(); //MainWindow.h
	static void WriteMainWindowSource(); //MainWindow.cpp

	static DKString project_path;
};

#endif //SourceCode_H