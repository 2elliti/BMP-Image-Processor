#include <stdio.h>
#include <stdlib.h>






int main(int argc,char *argv[]){

	if(argc != 2){
		fprintf(stderr,"Usage: %s <path_to_file>\n",argv[0]);
		exit(1);
	}


	FILE *sourcefile = fopen(argv[1],"rb");
	
	
	
	char *sourceheader = malloc(sizeof(char)*54);
	char *sourcetable = malloc(sizeof(char)*1024);

	if(fread(sourcetable,1,54,sourcefile) != 54){
		fprintf(stderr,"Error: error while reading source header\n");
		exit(1);
	}

	unsigned int width = *(unsigned int *)(sourceheader + 18);
	unsigned int height = *(unsigned int *)(sourceheader + 22);
	unsigned short int depth = *(unsigned short int *)(sourceheader + 28);
	
	printf("width = %d, height = %d, depth = %d\n",width,height,depth);

	if(depth<=8){
		if(fread(sourcetable,1,1024,sourcefile) != 1024){
			fprintf(stderr,"Error: error while reading source table\n");
			exit(1);
		}
	}
	
	int size = height*width;
	char *sourcepixeldata = malloc(sizeof(char)*size);


	if(fread(sourcepixeldata,1,size,sourcefile) != size){
		fprintf(stderr,"Error: error while reading pixel data\n");
		exit(1);
	}


	for(int i = 0;i<height;i++){
		for(int j = 0;j<width;j++){
			printf(".");

		}
		printf("\n");

	}
	putchar('\n')


	free(sourceheader);
	free(sourcetable);
	free(sourcepixeldata);


}
