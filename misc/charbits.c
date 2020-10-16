#include <stdio.h>
#include <string.h>

char A[10];

void nbitsprint(int n)
{
	char i;
	if (n<1) {
		for (i='a'; i<'e';i++)
			printf("%c",A[i-'a']);
		printf("\n");
		return;
	} else {
		for (i='a'; i< 'e'; i++) {
		    A[n-1] = i;
		    nbitsprint(n-1);
		}
	}
}


int main() {
    nbitsprint(4);
    bzero(A,10*sizeof(char));
}
