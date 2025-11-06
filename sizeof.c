#include <stdio.h>

int
main(void)
{
	printf("int:         %2lu\n", sizeof(int));
	printf("long:        %2lu\n", sizeof(long));
	printf("long long:   %2lu\n", sizeof(long long));
	printf("float:       %2lu\n", sizeof(float));
	printf("double:      %2lu\n", sizeof(double));
	printf("long double: %2lu\n", sizeof(long double));
	return 0;
}
