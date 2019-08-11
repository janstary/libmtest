#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

struct value {
	float in;
	float out;
} values[] = {

	{ LONG_MIN,      LONG_MIN	},
	{  INT_MIN,       INT_MIN	},
	{ -16777217,	-16777217	},
	{ -16777216,	-16777216	},
	{        -1,           -1	},

	/*
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
	*/

/* man fesetround FE_TONEAREST
 * Results are rounded to the closest representable value.
 * If the exact result is exactly half way between two representable values,
 * the value whose last binary digit is even (zero) is chosen.
 * This is the default mode.
 *
 * So 0.5 goes to zero (not one),
 * but 1.5 goes to two (not one).
 */
	{        +0.5,	       +0.0	},
	{        +1.0,	       +1.0	},
	{        +1.5,	       +2.0	},
	{        +2.0,	       +2.0	},
	{        +2.5,	       +2.0	},
	{        +3.0,	       +3.0	},
	{        +3.5,	       +4.0	},

/* TODO: test the nearest float below 0.5, 1.5, 2.5, ... */

	{ +16777216,	+16777216	},
	{ +16777217,	+16777217	},

	{  INT_MAX,       INT_MAX	},
	{ LONG_MAX,      LONG_MAX	},

	{  0, 0 }

};

int
main()
{
	float r;
	struct value *v;
	for (v = values; v->in; v++) {
		if ((r = rintf(v->in)) != v->out) {
			printf("rintf(%f) = %f != %f\n", v->in, r, v->out);
			return 1;
		}
	}
	return 0;
}
