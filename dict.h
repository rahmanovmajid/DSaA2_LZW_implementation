
#ifndef DICT
#define DICT


#include "list.h"


typedef struct Dict{
    List **table;
    int size;
    int lastIndex;
}Dict;


Dict *D_new(int size);
int D_hash(Dict *dict,char *key);
char* D_search(Dict *dict,char* key);
char* D_put(Dict *dict,char* key, char *value);
void D_print(Dict *dict);
Dict* D_duplicate(Dict *dict);




#endif
