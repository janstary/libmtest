#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <math.h>
#include <fenv.h>

#include "utils.h"

int vflag = 0;
int dflag = 1;
int uflag = 1;
int zflag = 1;

struct t {
	int r;
	struct v {
		float i;
		float o;
	}	*v;
};

struct v n[] = {
	{ +0.5,		+0.0 },
	{ -0.5,		-0.0 },
	{ +1.0,		+1.0 },
	{ -1.0,		-1.0 },
	{ +F_BELOW15,	+1.0 },
	{ -F_BELOW15,	-1.0 },
	{ +1.5,		+2.0 },
	{ -1.5,		-2.0 },
	{ +2.0,		+2.0 },
	{ -2.0,		-2.0 },
	{ +2.5,		+2.0 },
	{ -2.5,		-2.0 },
	{ +3.0,		+3.0 },
	{ -3.0,		-3.0 },
	{ +F_BELOW35,	+3.0 },
	{ -F_BELOW35,	-3.0 },
	{ +3.5,		+4.0 },
	{ -3.5,		-4.0 },
	{ +4.0,		+4.0 },
	{ -4.0,		-4.0 },
	{ +4.5,		+4.0 },
	{ -4.5,		-4.0 },
	{ +5.0,		+5.0 },
	{ -5.0,		-5.0 },
	{ +F_BELOW55,	+5.0 },
	{ -F_BELOW55,	-5.0 },
	{  INT_MAX,  INT_MAX },
	{  INT_MIN,  INT_MIN },
	{ LONG_MAX, LONG_MAX },
	{ LONG_MIN, LONG_MIN },
	{  0, 0 }
};

struct t tests[] = {
	{ FE_TONEAREST, n },
	{ FE_DOWNWARD,	NULL },
	{ FE_UPWARD,	NULL },
	{ FE_TOWARDZERO,NULL }
};


int
testround(int rounding, struct v * values)
{
	float f;
	struct v *v;
	for (v = values; v->i; v++) {
		if ((f = rintf(v->i)) != v->o) {
			printf("% .8f (%0#10x) % .8f (%0#10x) % .8f (%0#10x)\n",
				v->i, fu(v->i), f, fu(f), v->o, fu(v->o));
			return 1;
		} else if (vflag > 0) {
			printf("% .8f % .8f", v->i, v->o);
			if (vflag > 1)
				printf(" %0#10x %0#10x", fu(v->i), fu(v->o));
			putchar('\n');
		}
	}
	return 0;
}

int
main(int argc, char** argv)
{
	int c;
	struct t *t;

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

	for (t = tests; t->v; t++)
		if (0 != testround(t->r, t->v))
			return 1;

	return 0;
}
