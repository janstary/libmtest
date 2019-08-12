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

	{ -F_BELOW55,	-5.0 },
	{ -5.0,		-5.0 },
	{ -4.5,		-4.0 },
	{ -4.0,		-4.0 },
	{ -3.5,		-4.0 },
	{ -F_BELOW35,	-3.0 },
	{ -3.0,		-3.0 },
	{ -3.0,		-3.0 },
	{ -2.5,		-2.0 },
	{ -1.5,		-2.0 },
	{ -F_BELOW15,	-1.0 },
	{ -1.0,		-1.0 },
	{ -0.5,		-0.0 },

	{ +0.5,		+0.0 },
	{ +1.0,		+1.0 },
	{ +F_BELOW15,	+1.0 },
	{ +1.5,		+2.0 },
	{ +2.0,		+2.0 },
	{ +2.5,		+2.0 },
	{ +3.0,		+3.0 },
	{ +F_BELOW35,	+3.0 },
	{ +3.5,		+4.0 },
	{ +4.0,		+4.0 },
	{ +4.5,		+4.0 },
	{ +5.0,		+5.0 },
	{ +F_BELOW55,	+5.0 },

	{  INT_MAX,       INT_MAX	},
	{ LONG_MAX,      LONG_MAX	},

	{  0, 0 }

};

int
main(int argc, char** argv)
{
	int c;
	float r;
	struct value *v;

	int vflag = 0;
	int dflag = 1;
	int uflag = 1;
	int zflag = 1;

	while ((c = getopt(argc, argv, "vduz")) != -1) switch (c) {
		case 'v':
			vflag++;
			break;
		case 'd':
			dflag = 1;
			uflag = 0;
			zflag = 0;
			break;
		case 'u':
			dflag = 0;
			uflag = 1;
			zflag = 0;
			break;
		case 'z':
			dflag = 0;
			uflag = 0;
			zflag = 1;
			break;
		default:
			break;
	}
	argc -= optind;
	argv -= optind;

	for (v = values; v->in; v++) {
		if ((r = rintf(v->in)) != v->out) {
			printf("% .8f (%0#10x) % .8f (%0#10x) % .8f (%0#10x)\n",
				v->in, fu(v->in), r, fu(r), v->out, fu(v->out));
			return 1;
		} else if (vflag > 0) {
			printf("% .8f % .8f", v->in, v->out);
			if (vflag > 1)
				printf(" %0#10x %0#10x", fu(v->in), fu(v->out));
			putchar('\n');
		}
	}

	return 0;
}
