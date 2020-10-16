#include <stdio.h>

void hanoi(int n, char *p1, char *p2, char *p3) //start, end, aux
{
	if (n==1) {
		printf("move disk 1 from %s to %s\n",p1,p2);
		return;
	}
	hanoi(n-1, p1, p3, p2);
	printf("move disk %d from %s to %s \n", n, p1, p2);
	hanoi(n-1, p3, p2, p1);
}


int main()
{
	hanoi(3, "p1", "p2", "p3");
}
