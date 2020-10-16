#include <stdio.h>

void pback(int n)
{
	if (n>=1) printf(" %d ", n);
	if (n==1) return;
	pback(n-1);
	return;
}


int main()
{
   pback(10);
   return 0;
}




