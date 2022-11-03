#include <stdio.h>

int
main(void)
{
	printf("int:     %lu\n", sizeof(int));
	printf("long:    %lu\n", sizeof(long));
	printf("llong:   %lu\n", sizeof(long long));
	printf("float:   %lu\n", sizeof(float));
	printf("double:  %lu\n", sizeof(double));
	printf("ldouble: %lu\n", sizeof(long double));
	return 0;
}
