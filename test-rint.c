#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

struct value {
	double in;
	double out;
} values[] = {

{ -1.5000000001, -2.0000000000 },
{ -1.5000000000, -2.0000000000 },
{ -1.4999999999, -1.0000000000 },
{ -1.0000000000, -1.0000000000 },
{ -0.5000000001, -1.0000000000 },
{ -0.5000000000, -0.0000000000 },
{ -0.4999999999, -0.0000000000 },
{ +0.4999999999, +0.0000000000 },
{ +0.5000000000, +0.0000000000 },
{ +0.5000000001, +1.0000000000 },
{ +1.0000000000, +1.0000000000 },
{ +1.4999999999, +1.0000000000 },
{ +1.5000000000, +2.0000000000 },
{ +1.5000000001, +2.0000000000 },
{ (double) INT_MIN,    INT_MIN },
{ (double) INT_MAX,    INT_MAX },
{ (double) LONG_MIN,  LONG_MIN },
{ (double) LONG_MAX,  LONG_MAX },
{ 0, 0 }
};

int
main()
{
	double r;
	struct value *v;
	for (v = values; v->in; v++) {
		if ((r = rint(v->in)) != v->out) {
			printf("rint(%f) = %f != %f\n", v->in, r, v->out);
			return 1;
		}
	}
	return 0;
}
