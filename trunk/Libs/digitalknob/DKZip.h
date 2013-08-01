//// DKZip.h ////

//http://www.codeguru.com/cpp/cpp/algorithms/compression/article.php/c11735/zlib-Add-Industrial-Strength-Compression-to-Your-CC-Apps.htm

#pragma once
#ifndef DKZip_H
#define DKZip_H

#include <stdio.h>
#include "zlib.h"

///////////
class DKZip
{
public:
	DKZip();
	~DKZip(){};
	unsigned long file_size(char *filename);
	int decompress_one_file(char *infilename, char *outfilename);
	int compress_one_file(char *infilename, char *outfilename);
};

#endif //DKZip_H