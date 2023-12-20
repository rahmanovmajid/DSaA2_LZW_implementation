#include<stdlib.h>
#include <stdio.h>
#include "lzw.h"


void initDict(Dict *dict,char *fileName){

	FILE *file=fopen(fileName,"r");
	int c;
	while ((c = fgetc(file)) != EOF)
    {
    	//convert char to char
			char *key=(char*)malloc(2*sizeof(char));
			key[0]=(char)c;
			key[1]=0;

			//Converting int to char*

    		char *value=(char*)malloc(10*sizeof(char));
  			sprintf(value, "%d", dict->lastIndex);


			D_put(dict,key, value);

			printf("%s",key );
    }
    
    

    fclose(file);

}


int * encode(Dict *dict,char *fileName,int *length){

	int *encodeArr=(int *)malloc(100*sizeof(int));
	*length=0;
	char* encodeValue;

	FILE *file=fopen(fileName,"r");
	int c=fgetc(file);
	//Loop through file until end of th file
	while (c != EOF)
    {
    		char *key=(char*)malloc(10*sizeof(char));
    		int index=0;
    		//Loop through while finding new value which is not in dictionary
    		while(c!=EOF){
				key[index++]=(char)c; 
				key[index]=0;//sa0

				//Converting int to char*
			    char* value=(char*)malloc(10*sizeof(char));
			  	sprintf(value, "%d", dict->lastIndex);

				char* result=D_put(dict,key,value);
				if (result==0) break; //new value is founded && added to Dictionary
				else {
				//there is the same value in the dictionary
				c=fgetc(file);
				encodeValue=result;
				}
				
			}
			encodeArr[(*length)++]=atoi(encodeValue);


    }
    fclose(file);
    return encodeArr;
}



char *decode(Dict *dict, int *encodedText, int len){
	char *previousValue=NULL;
	for (int i = 0; i < len; ++i)
	{
		int key=encodedText[i];

		//Converting int to char*
		char* keyStr=(char*)malloc(10*sizeof(char));
		sprintf(keyStr, "%d", key);
		char *value=D_search(dict,keyStr);
		if (previousValue!=NULL)
		{
			char *newValue=(char*)malloc(100*sizeof(char));
			snprintf(newValue,100, "%s%c", previousValue, value[0]);

			char* newKey=(char*)malloc(10*sizeof(char));
			sprintf(newKey, "%d", dict->lastIndex);

			D_put(dict,newKey, newValue);
			
		}
		printf("%s",value);
		previousValue=value;
	}
	puts("");
}

