/*
 * based on dbader.org/blog/python-ctypes-tutorial
 */

unsigned long tenmillion_add_function(void) {
	int i, j;
        unsigned long sum;
	for (j=0; i < 100; j++) {
        sum = 0;
	for (i=0; i < 1000000; i++) {
		sum += i;
	}
	}
	return sum;
}
