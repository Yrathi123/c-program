#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	char c;
	FILE *fp;
	fp = fopen(argv[1],"r");
	while(fp != EOF){
		c = getc(fp);
		printf("%c",c);
	}
	fclose(fp);
}
