#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <err.h>

#include "utils.h"

int vflag = 0;
int dflag = 1;
int uflag = 1;
int zflag = 1;

struct t {
	int r;
	char* say;
	struct v {
		float i;
		float o;
	}	*v;
};

struct v rn[] = {
	{ -4.0,		-4.0 },
	{ -3.5,		-4.0 },
	{ -F_ALMOST35,	-3.0 },
	{ -3.0,		-3.0 },
	{ -2.5,		-2.0 },
	{ -2.0,		-2.0 },
	{ -1.5,		-2.0 },
	{ -F_ALMOST15,	-1.0 },
	{ -1.0,		-1.0 },
	{ -0.5,		-0.0 },
	{ +0.5,		+0.0 },
	{ +1.0,		+1.0 },
	{ +F_ALMOST15,	+1.0 },
	{ +1.5,		+2.0 },
	{ +2.0,		+2.0 },
	{ +2.5,		+2.0 },
	{ +3.0,		+3.0 },
	{ +F_ALMOST35,	+3.0 },
	{ +3.5,		+4.0 },
	{ +4.0,		+4.0 },
	{ +0.0,         +0.0 }
};

struct v rd[] = {
	{ -4.0,		-4.0 },
	{ -F_FOLLOW30,	-4.0 },
	{ -3.0,		-3.0 },
	{ -F_FOLLOW20,	-3.0 },
	{ -2.0,		-2.0 },
	{ -F_FOLLOW10,	-2.0 },
	{ -1.0,		-1.0 },
	{ -F_FOLLOW00,	-1.0 },
	{ +F_ALMOST10,	+0.0 },
	{ +1.0,		+1.0 },
	{ +F_ALMOST20,	+1.0 },
	{ +2.0,		+2.0 },
	{ +F_ALMOST30,	+2.0 },
	{ +3.0,		+3.0 },
	{ +F_ALMOST40,	+3.0 },
	{ +4.0,		+4.0 },
	{ +0.0,         +0.0 }
};

struct v ru[] = {
	{ -4.0,		-4.0 },
	{ -F_ALMOST40,	-3.0 },
	{ -3.0,		-3.0 },
	{ -F_ALMOST30,	-2.0 },
	{ -2.0,		-2.0 },
	{ -F_ALMOST20,	-1.0 },
	{ -1.0,		-1.0 },
	{ -F_ALMOST10,	+0.0 },
	{ +F_FOLLOW00,	+1.0 },
	{ +1.0,		+1.0 },
	{ +F_FOLLOW10,	+2.0 },
	{ +2.0,		+2.0 },
	{ +F_FOLLOW20,	+3.0 },
	{ +3.0,		+3.0 },
	{ +F_FOLLOW30,	+4.0 },
	{ +4.0,		+4.0 },
	{ +0.0,         +0.0 }
};

struct v rz[] = {
	{ +0.0,         +0.0 }
};

struct t tests[] = {
	{ FE_TONEAREST,  "to nearest", rn },
	{ FE_DOWNWARD,	 "downward",   rd },
	{ FE_UPWARD,	 "upward",     ru },
	{ FE_TOWARDZERO, "to zero",    rz }
};


int
testround(struct t *t)
{
	float f;
	struct v *v;
	if (NULL == t)
		return 1;
	if (0 != fesetround(t->r))
		return 1;
	if (vflag && t->say)
		printf("rounding %s\n", t->say);
	for (v = t->v; v->i; v++) {
		if ((f = rintf(v->i)) != v->o) {
			printf("% .8f % .8f % .8f\n", v->i, v->o, f);
			if (vflag > 1)
				printf(" %0#10x  %0#10x  %0#10x\n",
				fu(v->i), fu(v->o), fu(f));
			return 1;
		} else if (vflag > 0) {
			printf("% .8f % .8f", v->i, v->o);
			if (vflag > 1)
				printf("  %0#10x %0#10x", fu(v->i), fu(v->o));
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
		if (0 != testround(t))
			return 1;

	return 0;
}
