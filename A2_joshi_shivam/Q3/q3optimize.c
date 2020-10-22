//shivam joshi
#include <stdio.h>

int fibonacci(int n);

int a[42];
int main (int argc, char **argv)
{
   int fib;
   int n;
	for(int i=0;i<=42;i++)
	{
		a[i]=-1;
	}
   for (n = 0; n <= 42; n++) {
      fib = fibonacci(n);
      printf("fibonnaci(%d) = %d\n", n, fib);
   }

   return 0;
}

int fibonacci(int n)
{
   
   if (n <= 0) {
	a[n]=n;
return a[n];
   }
   else if (n == 1) {
a[n]=n;
return a[n];
   }
if(a[n]!=-1)
{
return a[n];
}
      a[n] = fibonacci(n -1) + fibonacci(n - 2); // no of call will reduce from 2^n to 2n-1 T.C is O(n)
return a[n];
   

   
}

