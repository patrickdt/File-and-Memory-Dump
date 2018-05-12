
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
	double max = *array;
	double *p = array;
	double *pend = p+n;	
	while (p<pend){
		if (*p > max){
			max = *p;
		}
		p++;
	}
  	return max;
}

// Return minimum element of array
double minArray(int n, double * array) {
	double min = * array;
	double *p = array;
	double *pend = p+n;
	while (p<pend){
		if(*p < min){
			min = *p;
		}
		p++;
	}
	return min;
}

// Find the position int the array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
  	//min = * array;
	//max = * array;
	double *p = array;
	double *pend = p+n;
	
	int ans=0;
        while (p<pend){
		//if ((val<pend)&&((*(val-1)==min)&&(*(val + 1)==max))){
		//	return val;
		//
		if (*p < max && *p > min){	
			return ans;
		}
		p++;
		ans++;
	}
	return -1;
}
// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {	
	int i, j, k;
	double temp;
	double * p = array;
	//double * q = array;
	//double * pend = p + n;
	for (int i = 0; i<n; i++){
		for(int j =0; j<n; j++){
			if(*(p+i)<*(p+j)){
				temp = *(p+i);
				*(p+i)= *(p+j);
				*(p+j)= temp;
			}
		}
	}
}
// Print array
void printArray(int n, double * array) {
	double * p = array;
	double * pend = p + n;
	int i = 0;
	
	while (p<pend){
		printf("%d:%lf\n",i,*p);
		p++; i++;
	}
}

