#include "sepia.h"



void processing_sepia(char *file){
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


        FILE *fo = fopen("sample_sepia.bmp","wb");

        if(fwrite(imageheader,1,54,fo) != 54){
                fprintf(stderr,"Error: fwrite()(-c)\n");
                exit(1);
        }
        int imagedatasize = width*height;

	unsigned char buffer[imagedatasize][3];
	int i;

	for(i = 0;i<imagedatasize;i++){
		unsigned char r,b,g;
		r = b = g = 0;
		buffer[i][2] = getc(fp);	// blue
		buffer[i][1] = getc(fp);	// green
		buffer[i][0] = getc(fp);	// red
		r = (buffer[i][0]*0.393) + (buffer[i][1]*0.769) + (buffer[i][2]*0.189);
		g = (buffer[i][0]*0.349) + (buffer[i][1]*0.686) + (buffer[i][2]*0.168);
		b = (buffer[i][0]*0.272) + (buffer[i][1]*0.534) + (buffer[i][2]*0.131);
	
		if(r > MAX_VALUE){				
			r = MAX_VALUE;
		}
		if(g > MAX_VALUE){
			g = MAX_VALUE;
		}
		if(b > MAX_VALUE){
			b = MAX_VALUE;
		}
		putc(b,fo);
		putc(g,fo);
		putc(r,fo);
	}


}

