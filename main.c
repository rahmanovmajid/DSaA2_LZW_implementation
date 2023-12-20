#include "lzw.h"

 
int main(int argc, char * argv[])
{
	Dict *dict = D_new(10);

	char *fileName = "test.txt";

	printf("Given text file: \n");
	puts("");
	initDict(dict,fileName);
	puts("");
	puts("");
	Dict *initDict = D_duplicate(dict);


	printf("Printing the initial dictionary: \n");
  	D_print(dict);
 	
 	int length;
   	int *encodeArr = encode(dict,fileName,&length);
	printf("Printing the whole (FULL) Dictionary : \n");
 	D_print(dict);



	printf("Now the encoded text is coming(or code?)...\n");
   	for (int i = 0; i < length; ++i){
   		printf("%d ",encodeArr[i] );
   	}

	printf("\n\n");
	printf("Now decoded text is coming...\n");
   	decode(initDict,encodeArr, length);
   

	return 0;
}







