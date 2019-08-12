#include <unistd.h>
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

	{ +0.5,	0.0 },
	{ +1.0,	1.0 },
	{ +1.5,	2.0 },
	{ +2.0,	2.0 },
	{ +2.5,	2.0 },
	{ +3.0,	3.0 },
	{ +3.5,	4.0 },

	{ F_BELOW15, 1.0 },
	{ F_BELOW35, 3.0 },
	{ F_BELOW55, 5.0 },

	{ +16777216,	+16777216	},
	{ +16777217,	+16777217	},

	{  INT_MAX,       INT_MAX	},
	{ LONG_MAX,      LONG_MAX	},

	{  0, 0 }

};

int
main(int argc, char** argv)
{
	int c;
	float r;
	int vflag = 0;
	struct value *v;

	while ((c = getopt(argc, argv, "v")) != -1) switch (c) {
		case 'v':
			vflag = 1;
			break;
		default:
			break;
	}
	argc -= optind;
	argv -= optind;

	for (v = values; v->in; v++) {
		if ((r = rintf(v->in)) != v->out) {
			printf("% .8f (%0#6x) % .8f (%0#6x) != % .8f (%0#6x)\n",
				v->in,f2u(v->in), r,f2u(r), v->out,f2u(v->out));
			return 1;
		} else if (vflag) {
			printf("% .8f (%0#6x) % .8f (%0#6x)\n",
				v->in, f2u(v->in), v->out, f2u(v->out));
		}
	}

	return 0;
}
