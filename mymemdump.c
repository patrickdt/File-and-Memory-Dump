
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {
   	// Add your code here.
   	// You may see p as an array.
    	// p[0] will return the element 0 
	// p[1] will return the element 1 and so on
    
	//we want to print the new address every 1st, 16th, and 24th.
	//for (int i = 0; i < len; i++){
	//	if(len%16==0){
	//		fprintf(fd, "0x%016lX: ", (unsigned long) p); // Print address of the beginning of p. You need to print it every 16 bytes
	//	}
	//}
	int i=0;
    	for (i=0; i < len/16; i++) {
		fprintf(fd, "0x%016lX: ", (unsigned long)p + i*16);
		for(int j=0; j<16; j++){
			// Get value at [p]. The &0xFF is to make sure you truncate to 8bits or one byte.
        		int c = p[i*16+j]&0xFF;
			// Print first byte as hexadecimal
        		fprintf(fd, "%02X ", c);
		}
		fprintf(fd, " ");
		for (int j=0; j<16; j++){
        		int c = p[i*16+j]&0xFF;
			// Print first byte as character. Only print characters >= 32 that are the printable characters.
        		fprintf(fd, "%c", (c>=32&&c<127)?c:'.');
		}
        	fprintf(fd,"\n");
      }
      if (len%16!=0){
		fprintf(fd, "0x%016lX: ", (unsigned long)p + i*16);
		for(int j=0; j<len%16; j++){
			int c=p[(i)*16+j]&0xFF;
			fprintf(fd, "%02X ", c);
		}
		for(int j=0; j<16-len%16; j++){
			fprintf(fd, "   ");
		}
		fprintf(fd, " ");
		for(int j=0; j<len%16; j++){
			int c=p[(i)*16+j]&0xFF;
			fprintf(fd, "%c", (c>=32&&c<127)?c:'.');
		}
		fprintf(fd, "\n");

      }
    }

