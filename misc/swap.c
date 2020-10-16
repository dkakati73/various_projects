#include <stdio.h>
#include <malloc.h>
#include <string.h>

void worker(char *s1, char *s2)
{
	char *s3;
	int max;
	if (strlen(s1) > strlen(s2))
		max = strlen(s1);
	else 
		max = strlen(s2);
	s3 = (char *)malloc(sizeof(char)*max+1);
	strcpy(s3, s1);
	strcpy(s1, s2);
	strcpy(s2, s3);
}

void worker1(char **s1, char **s2)
{
	char *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int main()
{
	char s1[10] = "abc";
	char s2[10] = "123";
	char *s3 = "111";
	char *s4 = "222";

	worker(s1, s2);
	worker1(&s3, &s4);
	printf("%s %s \n", s1, s2);
	printf("%s %s \n", s3, s4);
}

