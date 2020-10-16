
#include <stdio.h>
#include <strings.h>
#include <string.h>

void go(char s[])
{
	s[0] = '9';
}


int main()
{
	//char *s = "abc123";//cannot be changed
	int i=0;
	char s[10];
	bzero(s, 10*sizeof(char));
	strcpy(s,"abc123");
	s[1] = 'X';
	while (s[i] != '\0') {
		printf("%c", s[i]);
		++i;
	}
	go(s);
	i = 0;
	while (s[i] != '\0') {
		printf("%c", s[i]);
		++i;
	}
}
