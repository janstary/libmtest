#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#include "utils.h"
#include "which.h"
#include "test.h"

int vflag = 0;
extern struct test test;

int
dotest(OTYPE (*func)(ITYPE), struct io *io)
{
	OTYPE o;
	struct io *v;
	for (v = io; v->i; v++) {
		if ((o = func(v->i)) != v->o) {
			printf(INUMFMT" "ONUMFMT" "ONUMFMT"\n", v->i, v->o, o);
			if (vflag > 1)
				printf(" "IHEXFMT" "OHEXFMT" "OHEXFMT"\n",
				INUMHEX(v->i), ONUMHEX(v->o), ONUMHEX(o));
			return 1;
		} else if (vflag > 0) {
			printf(INUMFMT" "ONUMFMT, v->i, v->o);
			if (vflag > 1)
				printf(" "IHEXFMT" "OHEXFMT,
				INUMHEX(v->i), ONUMHEX(v->o));
			putchar('\n');
		}
	}
	return 0;
}

int
main(int argc, char** argv)
{
	int c;
	struct test *t = &test;

	while ((c = getopt(argc, argv, "v")) != -1) switch (c) {
		case 'v':
			vflag++;
			break;
		default:
			break;
	}
	argc -= optind;
	argv -= optind;

	if (t->pre && t->pre())
		return 1;
	if (vflag && t->comment)
		printf("%s\n", t->comment);
	if (0 != dotest(FUNC, t->io))
		return 1;

	return 0;
}
