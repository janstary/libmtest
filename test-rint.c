#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <err.h>

#include "utils.h"

extern int optind;

int vflag = 0;
int dflag = 1;
int uflag = 1;
int zflag = 1;

struct t {
	int r;
	char* say;
	struct v {
		double i;
		double o;
	}	*v;
};

struct v rn[] = {
	{ -4.0,		-4.0 },
	{ -3.5,		-4.0 },
	{ -D_ALMOST35,	-3.0 },
	{ -3.0,		-3.0 },
	{ -D_FOLLOW25,	-3.0 },
	{ -2.5,		-2.0 },
	{ -2.0,		-2.0 },
	{ -1.5,		-2.0 },
	{ -D_ALMOST15,	-1.0 },
	{ -1.0,		-1.0 },
	{ -D_FOLLOW05,	-1.0 },
	{ -0.5,		-0.0 },
	{ +0.5,		+0.0 },
	{ +D_FOLLOW05,	+1.0 },
	{ +1.0,		+1.0 },
	{ +D_ALMOST15,	+1.0 },
	{ +1.5,		+2.0 },
	{ +2.0,		+2.0 },
	{ +2.5,		+2.0 },
	{ +D_FOLLOW25,	+3.0 },
	{ +3.0,		+3.0 },
	{ +D_ALMOST35,	+3.0 },
	{ +3.5,		+4.0 },
	{ +4.0,		+4.0 },
	{ +0.0,         +0.0 }
};

struct v rd[] = {
	{ -4.0,		-4.0 },
	{ -D_FOLLOW30,	-4.0 },
	{ -3.0,		-3.0 },
	{ -D_FOLLOW20,	-3.0 },
	{ -2.0,		-2.0 },
	{ -D_FOLLOW10,	-2.0 },
	{ -1.0,		-1.0 },
	{ -D_FOLLOW00,	-1.0 },
	{ +D_ALMOST10,	+0.0 },
	{ +1.0,		+1.0 },
	{ +D_ALMOST20,	+1.0 },
	{ +2.0,		+2.0 },
	{ +D_ALMOST30,	+2.0 },
	{ +3.0,		+3.0 },
	{ +D_ALMOST40,	+3.0 },
	{ +4.0,		+4.0 },
	{ +0.0,         +0.0 }
};

struct v ru[] = {
	{ -4.0,		-4.0 },
	{ -D_ALMOST40,	-3.0 },
	{ -3.0,		-3.0 },
	{ -D_ALMOST30,	-2.0 },
	{ -2.0,		-2.0 },
	{ -D_ALMOST20,	-1.0 },
	{ -1.0,		-1.0 },
	{ -D_ALMOST10,	+0.0 },
	{ +D_FOLLOW00,	+1.0 },
	{ +1.0,		+1.0 },
	{ +D_FOLLOW10,	+2.0 },
	{ +2.0,		+2.0 },
	{ +D_FOLLOW20,	+3.0 },
	{ +3.0,		+3.0 },
	{ +D_FOLLOW30,	+4.0 },
	{ +4.0,		+4.0 },
	{ +D_FOLLOW40,	+5.0 },
	{ +0.0,         +0.0 }
};

struct v rz[] = {
	{ -D_FOLLOW40,	-4.0 },
	{ -4.0,		-4.0 },
	{ -D_ALMOST40,	-3.0 },
	{ -D_FOLLOW30,	-3.0 },
	{ -3.0,		-3.0 },
	{ -D_ALMOST30,	-2.0 },
	{ -D_FOLLOW20,	-2.0 },
	{ -2.0,		-2.0 },
	{ -D_ALMOST20,	-1.0 },
	{ -D_FOLLOW10,	-1.0 },
	{ -1.0,		-1.0 },
	{ -D_ALMOST10,	-0.0 },
	{ -D_FOLLOW00,	-0.0 },
	{ +D_FOLLOW00,	+0.0 },
	{ +D_ALMOST10,	+0.0 },
	{ +1.0,		+1.0 },
	{ +D_FOLLOW10,	+1.0 },
	{ +D_ALMOST20,	+1.0 },
	{ +2.0,		+2.0 },
	{ +D_FOLLOW20,	+2.0 },
	{ +D_ALMOST30,	+2.0 },
	{ +3.0,		+3.0 },
	{ +D_FOLLOW30,	+3.0 },
	{ +D_ALMOST40,	+3.0 },
	{ +4.0,		+4.0 },
	{ +D_FOLLOW40,	+4.0 },
	{ +0.0,         +0.0 }
};

struct t tests[] = {
	{ FE_TONEAREST,  "to nearest",   rn },
	{ FE_DOWNWARD,	 "downward",     rd },
	{ FE_UPWARD,	 "upward",       ru },
	{ FE_TOWARDZERO, "towards zero", rz }
};


int
testround(struct t *t)
{
	double d;
	struct v *v;
	if (NULL == t)
		return 1;
	if (0 != fesetround(t->r))
		return 1;
	if (vflag && t->say)
		printf("rounding %s\n", t->say);
	for (v = t->v; v->i; v++) {
		if ((d = rint(v->i)) != v->o) {
			printf("% .17f % .17f % .17f\n", v->i, v->o, d);
			if (vflag > 1)
				printf(" %0#18llx  %0#18llx  %0#18llx\n",
				du(v->i), du(v->o), du(d));
			return 1;
		} else if (vflag > 0) {
			printf("% .17f % .17f", v->i, v->o);
			if (vflag > 1)
				printf("  %0#18llx %0#18llx", du(v->i), du(v->o));
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
