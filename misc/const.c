#include <stdio.h>

int f()
{
	printf("a\n");
	return 1;
}

int main()
{
	int a = 10;
	int b = 20;
	int * const x = &a;
	int const * y = &b;

	*x = 11;
	//x = &b;
	y = &a;
	//*y = 11;
	
	int arr[] = {0,1,2,3,4,5,6};
	char * m = (char*)(arr+6) ;
	char * n = (char*)arr;
	printf("%d", *m-*n);

	int (*fptr)();
	fptr = &f;
	(*fptr)();

	int xyz[] = {1,2,3,4,5};
	int *mx;
	mx = &xyz[0];
	printf("%lu %d", sizeof(*mx), *(mx+1)-*mx);

}
