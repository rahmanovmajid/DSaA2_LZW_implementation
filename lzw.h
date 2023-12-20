#ifndef LZW
#define LZW

#include "dict.h"

void initDict(Dict *dict,char *fileName);
int *encode(Dict *dict,char *fileName,int *length);
char *decode(Dict *dict, int *encodedText, int len);


#endif
