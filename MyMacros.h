#pragma once
#include <stdio.h>
#include<stdlib.h>
#define CHECK_RETURN_0 (void* ptr) (ptr == NULL) ? 0 : 1
#define CHECK_RETURN_NULL (void* ptr) (CHECK_RETURN_0(ptr)) == 0 ? NULL : ptr

#define CHECK_NULL__MSG_COLSE_FILE (FILE* fp){\
	if(!fp)\
	{\
		printf("\nError in file\n");\
		fclose(fp);\
		0;\
	}\
 }\
