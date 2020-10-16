#include <stdio.h>
#include <string.h>

int A[10];

void nbitsprint(int n)
{
	int i;
	if (n<1) {
		for (i=0; i<4;i++)
			printf("%d",A[i]);
		printf("\n");
		return;
	} else {
		for (i=0; i <=1; i++) {
		    A[n-1] = i;
	     	    nbitsprint(n-1);
		}
	}
}


int main() {
    nbitsprint(4);
    bzero(A,10*sizeof(int));
}
