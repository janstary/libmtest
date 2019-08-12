#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

struct value {
	float in;
	float out;
} values[] = {

	{ LONG_MIN,      LONG_MIN	},
	{  INT_MIN,       INT_MIN	},
	{ -16777217,	-16777217	},
	{ -16777216,	-16777216	},
	{        -1,           -1	},

/* man fesetround
 *   FE_TONEAREST  Results are rounded to the closest representable value.
 *   If the exact result is exactly half way between two representable values,
 *   the value whose last binary digit is even (zero) is chosen.
 *   This is the default mode.
 * So  0.5 goes down to zero (not to the odd one),
 * but 1.5 goes up   to  two (not to the odd one).
 */
	{         +0.5,	0.0	},
	{         +1.0,	1.0	},
	{         +1.5,	2.0	},
	{         +2.0,	2.0	},
	{         +2.5,	2.0	},
	{         +3.0,	3.0	},
	{         +3.5,	4.0	},

	{ F_BELOW15, 1.0	},
	{ F_BELOW35, 3.0	},
	{ F_BELOW55, 5.0	},

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
			printf("% .8f (%0#6x) % .8f (%0#6x) != % .8f (%0#6x)\n",
				v->in,f2u(v->in), r,f2u(r), v->out,f2u(v->out));
			return 1;
		/*
		} else {
			printf("% .8f (%0#6x): % .8f (%0#6x)\n",
				v->in, f2u(v->in), v->out, f2u(v->out));
		*/
		}
	}

	return 0;
}
