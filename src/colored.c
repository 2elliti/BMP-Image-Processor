#include "colored.h"



void colored_processing(char *file,char *third_flag){

//	FILE *fp = fopen("file","rb");


//	char *imageheader = malloc(sizeof(char)*54);
//	if(fread(imageheader,1,54,fp) != 54){
//		fprintf(stderr,"Error: fread()(-c)\n");
//		exit(1);
//	}

//	unsigned int width = *((int *)(imageheader + 18));
//	unsigned int height = *((int *)(imageheader + 22));
//	unsigned short int bitdepth = *((unsigned short int *)(imageheader + 28));

//	char *colortable = malloc(sizeof(char)*1024);

//	if(bitdepth<=8){
//		if(fread(colortable,1,1024,fp));
//	}

//	
//	FILE *fo = fopen("sample.bmp","wb");

//	if(fwrite(imageheader,1,54,fo) != 54){
//		fprintf(stderr,"Error: fwrite()(-c)\n");
//		exit(1);
//	}
//	int imagedatasize = width*height;
	

//	;*************************************************************
//	;		       Your Code Starts here
//	;*************************************************************



	if(strcmp(third_flag,"-s") == 0){
		processing_sepia(file);
	}
	else if(strcmp(third_flag,"-g") == 0){
		processing_gray(file);
	}
	else if(strcmp(third_flag,"-as") == 0){
		//
	}
	else{
		printf("Iam at colored last\n");
	}







}

