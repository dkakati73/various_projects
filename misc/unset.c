#include <stdio.h>

int main(void)
{
	int x;
	x = 0x00101;
	printf("%x \n", x);
	printf("%x %x \n", (x&~0x1), x & x-1); 
}
