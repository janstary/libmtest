#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#include "utils.h"
#include "which.h"
#include "test-func.h"

int vflag = 0;
int nflag = 1;
int dflag = 1;
int uflag = 1;
int zflag = 1;

extern int optind;
extern struct test tests[];

int
testfunc(OTYPE (*FUNC)(ITYPE), struct io *io)
{
	OTYPE o;
	struct io *v;
	for (v = io; v->i; v++) {
		if ((o = FUNC(v->i)) != v->o) {
			printf(REALFMT" "REALFMT" "REALFMT"\n", v->i, v->o, o);
			if (vflag > 1)
				printf(" "HEXAFMT" "HEXAFMT" "HEXAFMT"\n",
					RU(v->i), RU(v->o), RU(o));
			return 1;
		} else if (vflag > 0) {
			printf(REALFMT" "REALFMT, v->i, v->o);
			if (vflag > 1)
				printf(" "HEXAFMT" "HEXAFMT,
					RU(v->i), RU(v->o));
			putchar('\n');
		}
	}
	return 0;
}

int
main(int argc, char** argv)
{
	int c;
	struct test *t;

	while ((c = getopt(argc, argv, "vnduz")) != -1) switch (c) {
		case 'v':
			vflag++;
			break;
		case 'n':
			nflag = 1;
			dflag = 0;
			uflag = 0;
			zflag = 0;
			break;
		case 'd':
			nflag = 0;
			dflag = 1;
			uflag = 0;
			zflag = 0;
			break;
		case 'u':
			nflag = 0;
			dflag = 0;
			uflag = 1;
			zflag = 0;
			break;
		case 'z':
			nflag = 0;
			dflag = 0;
			uflag = 0;
			zflag = 1;
			break;
		default:
			break;
	}
	argc -= optind;
	argv -= optind;

	for (t = tests; t->io; t++) {
		switch (t->round) {
			case FE_TONEAREST:
				if (0 == nflag)
					continue;
				break;
			case FE_DOWNWARD:
				if (0 == dflag)
					continue;
				break;
			case FE_UPWARD:
				if (0 == uflag)
					continue;
				break;
			case FE_TOWARDZERO:
				if (0 == zflag)
					continue;
				break;
		}
		if (0 != fesetround(t->round))
			return 1;
		if (vflag && t->comment)
			printf("%s\n", t->comment);
		if (0 != testfunc(FUNC, t->io))
			return 1;
	}

	return 0;
}
