#include "list.h"


List *L_new(char* key,char *value){
    List *newNode = (List*)malloc(sizeof(List));
    newNode->key=key;
    newNode->value = value;
    newNode->pNext = NULL;
    return newNode;
}

char *L_append(List **ppHead, char *key,char *value){
	List *newNode = L_new(key,value);
    List *tempNode = (*ppHead);
    if (tempNode == NULL){
    	*ppHead = newNode;
        return 0;
    }

    if ( strcmp(tempNode->key, key) == 0){
        return tempNode->value;
    }
    while ( tempNode->pNext != NULL){
        if (strcmp(tempNode->pNext->key, key) == 0){
            
            return tempNode->pNext->value;
        }
        tempNode = tempNode->pNext;
    }
    tempNode->pNext = newNode;
    return 0;
}






char *L_search(List *pHead, char *key){

    List *tempNode = pHead;
    while (tempNode != NULL){
        if (strcmp(tempNode->key, key) == 0){
            
            return tempNode->value;
        }
        tempNode = tempNode->pNext;
    }
    return 0;
}

void L_print(List *pHead){
    if (pHead == NULL)
    {
        puts("");
        return;
    }

    while (pHead != NULL){
        printf("[%s,%s] => ",pHead->key,pHead->value);
        pHead = pHead->pNext;
    }
    puts("");
}

