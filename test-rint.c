#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

double in[] = {
	-1.5000000001,
	-1.5000000000,
	-1.4999999999,
	-1.0000000000,
	-0.5000000001,
	-0.5000000000,
	-0.4999999999,
	+0.4999999999,
	+0.5000000000,
	+0.5000000001,
	+1.0000000000,
	+1.4999999999,
	+1.5000000000,
	+1.5000000001,
	(double) INT_MIN,
	(double) INT_MAX,
	(double) LONG_MIN,
	(double) LONG_MAX,
	0
};

int
main()
{
	double *d;
	for (d = in; *d; d++)
		printf("%+36.10f %+36.10f\n", *d, rint(*d));
	return 0;
}
