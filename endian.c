#include <stdio.h>

int
isLittleEndian(){
	int a = 0x05;
	char * p = (char *) &a;
	if (*p==0x05) {
		return 1;
	}
}

main (){
	if (isLittleEndian()){
		printf("Machine is Little Endian\n");
	}
	else{
		printf("Machine is Big Endian\n");
	}
}
