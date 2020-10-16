#include <stdio.h>

register int y = 10;

int *x = &y;

int main() {
printf("%d %p \n", *x, x);
}
