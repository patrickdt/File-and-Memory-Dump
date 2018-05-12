
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void filedump(char * p , int len) {

	int i=0;
	for(i=0; i<len/16; i++){
		printf("0x%016lX: ", (unsigned long)i*16);
		for(int j=0; j<16; j++) {
			int c = p[i*16+j]&0xFF;
			printf("%02X ", c);
		}
		printf(" ");
		for(int j=0; j<16; j++){
			int c = p[i*16+j]&0xFF;
			printf("%c", (c>=32&&c<127)?c:'.');
		}
		printf("\n");
	}
	if (len%16 !=0){
		printf("0x%016lX: ", (unsigned long) i*16);
		for(int j=0; j<len%16; j++){
			int c=p[i*16+j]&0xFF;
			printf("%02X ", c);
		}	
		for(int j=0; j<16-len%16; j++){
			printf("   ");
		}
		printf(" ");
		for(int j=0; j<len%16; j++){
			int c=p[i*16+j]&0xFF;
			printf("%c", (c>=32&&c<127)?c:'.');
		}
		printf("\n");
	}
}
void main(int argc, char **argv){
	int i;
	char *c;
	long size;
	FILE * fp;
	if(argc<2){
		exit(1);
	}
	fp=fopen(argv[1], "r");
	if(fp==NULL){
		printf("Error opening file \"invalidfile\"\n");
		exit(1);
	}
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	c=malloc(size);
	fread(c, 1, size, fp);
	if(argc>2 && atoi(argv[2])<size){
		size = atoi(argv[2]);	
	}
	filedump(c, size);
	
	
}
