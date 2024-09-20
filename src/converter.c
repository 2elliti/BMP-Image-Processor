#include "converter.h"




void print_usage(char *file_path){
	fprintf(stderr,"Usage: %s <file_path> <f1> <f2> <f3>. For more help use -help.\n",file_path);
	exit(1);
}




int main(int argc,char **argv){

	if(argc<=2 && argv[1]== NULL){
		print_usage(argv[0]);
	}

	if(argc<=2 && strcmp(argv[1],"-help")!=0){
		print_usage(argv[0]);
	}
	
	if(strcmp(argv[1],"-help") == 0){
		printf(";*************************************************;\n");
		printf(";                 Helping guide                   ;\n");
		printf(";*************************************************;\n");
		printf("-> If you have colored picture then use -c flag, if grayscale then use -nc\n");
		printf("-> If you want to convert colored to sepia use -s flag, grayscale -g flag, ascii -as flag\n");
		printf("-> If you want to convert non colored(Grayscale) to black and white use -bw flag, bright -br flag, Blur -br, ascii -as  \n");
	}
	else{
	
		if(strcmp(argv[2],"-c") == 0){
			if(argv[3] == NULL){
				fprintf(stderr,"You dont have enough flags. Type -help to know more.\n");
				exit(1);
			}
			else{
				/* Function for processing Colored*/
				colored_processing(argv[1],argv[3]);
			}
		}
		else if(strcmp(argv[2],"-nc") == 0){
			if(argv[3]==NULL){
				fprintf(stderr,"You don't have enough flags. Type -help to know more.\n");
				exit(1);
			}
			else{
				/* Function for processing Non - Colored flag */
			}
		}
		else{
			fprintf(stderr,"Error: Pls type -help to see Help section.\n");
		}
	}


}
