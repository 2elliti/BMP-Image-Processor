#include "grayscale.h"


void processing_gray(char *file){

    FILE *fp = fopen(file,"rb");


        char *imageheader = malloc(sizeof(char)*54);
        if(fread(imageheader,1,54,fp) != 54){
                fprintf(stderr,"Error: fread()(-c)\n");
                exit(1);
        }

        unsigned int width = *((int *)(imageheader + 18));
        unsigned int height = *((int *)(imageheader + 22));
        unsigned short int bitdepth = *((unsigned short int *)(imageheader + 28));

        char *colortable = malloc(sizeof(char)*1024);

        if(bitdepth<=8){
                if(fread(colortable,1,1024,fp));
        }


        FILE *fo = fopen("sample_gray.bmp","wb");

        if(fwrite(imageheader,1,54,fo) != 54){
                fprintf(stderr,"Error: fwrite()(-c)\n");
                exit(1);
        }
        int imagedatasize = width*height;

	    unsigned char buffer[imagedatasize][3];
        int i;
        for(i=0;i<imagedatasize;i++){
            int y;
            y=0;
            buffer[i][1] = getc(fp);					//green
            buffer[i][2] = getc(fp);					//blue
            buffer[i][0] = getc(fp);					//red
		
            y = (buffer[i][0]*0.3) + (buffer[i][1]*0.59) + (buffer[i][2]*0.11); //conversion formula of rgb to gray

            putc(y,fo);
            putc(y,fo);
            putc(y,fo);
        }

}