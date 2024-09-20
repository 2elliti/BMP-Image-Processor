#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	
	if(argc != 2){
		fprintf(stderr,"Usage: %s < file_path >\n",argv[0]);
		exit(1);
	}


	FILE *sourcefile = fopen(argv[1],"rb");

	char *sourceheader = malloc(sizeof(char)*54);
	char *sourcecolortable = malloc(sizeof(char)*1024);
	
	if(fread(sourceheader,1,54,sourcefile) != 54){
		fprintf(stderr,"Error: error while reading source header\n");
		exit(1);
	}
	if(fread(sourcecolortable,1,1024,sourcefile) != 1024){
		fprintf(stderr,"Error: error while reading source color table\n");
		exit(1);
	}

	unsigned int width = *(unsigned int *)(sourceheader + 18);
	unsigned int height = *(unsigned int *)(sourceheader + 22);
	unsigned short int depth = *(unsigned short int *)(sourceheader + 28);

	printf("%d\n",depth);

	unsigned char buffer[width*height][3];

	for(int i=0;i<width*height;i++)


}
