/*
/*
 ============================================================================
 Roll no.    		: 23141
 Class          	: SE - 9
 Batch              : G - 9
 Name         	    : Sahil Naphade
 Assignment no.     : Assignment 5 - A
 Problem Statement  :


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp1,*fp2;
	char /*source[20],destination[20],*/data[50];
	int i,choice,ch_case;
	char c;
	if(argc<3) printf("Insufficient arguments provided\nProcess Terminated\n");
	else if (argc>3) printf("Excess arguments provided\nProcess Terminated\n");
	else {
		char c;
		FILE *fp1,*fp2;
		fp1 = fopen(argv[1],"rb");
		fp2 = fopen(argv[2],"wb");

		while(!feof(fp1)){
			c = getc(fp1);
			putc(c,fp2);
		}
		printf("File copy successful\n");
	}	
return EXIT_SUCCESS;
} //END OF MAIN FUNCTION
