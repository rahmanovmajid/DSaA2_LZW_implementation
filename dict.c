
#include "dict.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Dict *D_new(int size){
    Dict *dict =(Dict *)malloc(sizeof(Dict));
    dict->size = size;
    dict->lastIndex = 0;
    dict->table = (List **)malloc(size * sizeof(List *));
    int i;
    for (i = 0; i < size; i++){
        dict->table[i] = NULL;
    }
    return dict;
}


int D_hash(Dict *dict,char *key){
    if (dict == NULL || dict->size <= 0)
        return -1;
    int index;

    for (index = 0; *key != 0; key++){
        index = (index * 256 + (int)(*key)) % dict->size;
    }
    return index;
}

char* D_put(Dict *dict,char* key, char *value){
    if (dict == NULL || dict->size <= 0)    return 0;
    int index = D_hash(dict, key);
    char * result = L_append(&(dict->table[index]), key,value);
    if (result == 0) {
    	(dict->lastIndex)++;
    	return 0;
    }
    return result;
}

char* D_search(Dict *dict,char* key){
	if (dict == NULL || dict->size <= 0)    return 0;
    int index = D_hash(dict, key);
    char * result = L_search(dict->table[index], key);
    return result;
}

void D_print(Dict *dict){
    int i;
    for (i = 0; i < dict->size; i++){
        printf("%d:", i); 
        L_print(dict->table[i]);
    }
}

Dict* D_duplicate(Dict *dict){
	Dict *newDict = D_new(dict->size); 
    int i;
    for (i = 0; i < dict->size; i++){
    	List *node = dict->table[i];
    	while(node != NULL){
    		D_put(newDict,node->value,node->key);
    		node = node->pNext;
    	}
    }
    return newDict;
}











