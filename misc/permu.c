#include <stdio.h>
#include <string.h>
#include <malloc.h>

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permu(char *a, int l, int r)
{
	if (l==r) {
		printf("%s \n", a);
	} else {
		int i;
		for (i = l ; i <r; i++) {
			swap((a+l), (a+i));
			permu(a, l+1, r);
			swap((a+l),(a+i));
		}
	}
}

int main()
{
        char *str = (char *)malloc(5*sizeof(char));
	if (str) {
		sprintf(str,"%s","ABC");
	int n = strlen(str);
	permu(str, 0, n-1);
	}
	return 0;
}



