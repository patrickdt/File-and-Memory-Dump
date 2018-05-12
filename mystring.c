
#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
//
	if (s != NULL){
        	int i = 0;
		while (*s){
			i++;s++;
		}
		return i;
	}
	return NULL;
}

char * mystrcpy(char * dest, char * src) {
	char *p = dest;
	
	while(*src){
		*dest = *src;
		dest++; src++;
	}
	*dest = '\0';
	return p;
}

char * mystrcat(char * dest, char * src) {
	char *p, *q;
	p = dest;
	while (*p) {
		p++;	
	}
	q = src;
	while (*q){
		*p++ = *q++;
	}
	*p='\0';
	return dest;
}

int mystrcmp(char * s1, char * s2) {
	int i = 0;
	while (*s1){
		i++; s1++;
	}
	int j = 0;
	while (*s2){
		j++; s2++;
	}
	if (i > j) {
		return 1;
	}
	else if (j > i){
		return -1;
	}
	else{
		return 0;
	}
}

char * mystrstr(char * hay, char * needle) {
	//char * h = hay;
	//char * n = needle;
	//char * p;
	while (*hay){
		char *m = hay;
		char *n = needle;
		char * h=hay;
		while((*n) && *n== *h ){
			//hay++; needle++;
			n++;
			//needle++;
			h++;
		}
		if(!*n){
			return m;
		}
		hay++;	
	}
	return NULL;
}

char * mystrdup(char * s) {
	//int i = 0;
	char *str = (char *) malloc(sizeof(char)+1);
	mystrcpy(str, s);
	return str;
}

char * mymemcpy(char * dest, char * src, int n)
{
	while(n){
		*dest=*src;
		dest++; src++;
 		n--;
	}
	return dest;
}
