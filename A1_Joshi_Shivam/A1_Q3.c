#include <stdio.h>
#include "string.h"
int main(int argc, char* argv[]) {
int i, j, k;
i=5; 
int *p = &i;  // earlier point p was not not pointing to any of the address so gdb shows error
int arr[500]; // As a part of debugging pointer p is assigned a valid address to solve segmentation fault
char *str;
for(j = 1; j < 500; ++j){ // Array index was out of bound here earlier it was 5000 now changed to 500
arr[j] = j;
//printf("%d",*p);
}
str="System";
modifyString(str);
printf("Enter integer in 0..4999: ");
scanf("%d", &k);// earlier scanning without & leads to segmentation fault
if(k<5000)foo(arr, k);// value > 4999 cause segmentation fault
else printf("enter value less than 5000");
}
int foo(int* c, int k) {
printf("x[%d] = %d\n", k, c[k]);
}
void modifyString(char *s){
//*(s+3) = 'k';	// Trying to modify String constant is illegal
}
