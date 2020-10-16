#include <stdio.h>

typedef struct at {
	unsigned int x:1;
	unsigned int y:2;
	unsigned int z:3;
} t;

int main()
{
   t a;
   a.x = a.y = a.z = 0;
   a.x = 0x1;
   a.y = 0x3;
   a.z = 0x7;
   printf("%x %x %x \n", a.x, a.y, a.z );
}
