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

	{ 0x1.7ffffep0, 1.0	}, /* 0x3fbfffff, just below 1.5 = 0x3fc00000 */
	{ 0x3.7ffffbp0, 3.0	}, /* 0x405fffff, just below 3.5 = 0x40600000 */
	{ 0x5.7ffff5p0, 5.0	}, /* 0x40afffff, just below 5.5 = 0x40b00000 */

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
