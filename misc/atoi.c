#include <stdio.h>

int main()
{
	char s[] = {"1234567"};
	int num = 0;
	int index = 0;
	while (s[index] != 0) {
		num = num * 10 + (s[index]-'0');
		++index;
	}
	printf("%d", num);

	int j = 0xFF0000AA;
	char *c = (char*)&j;
	if (*c == 0xFF) {
		printf("big endian\n");
	} else {
		printf("small endian\n");
	}
}
