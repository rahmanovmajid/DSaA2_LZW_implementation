#ifndef LIST
#define LIST


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct List{
	char *key;
    char *value;
    struct List *pNext;
}List;



List *L_new(char* key,char *value);
char *L_append(List **ppHead, char* key,char *value);
char *L_search(List *pHead, char *key);
void L_print(List *pHead);


#endif