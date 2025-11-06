/* The harmonic series 1/1 + 1/2 + 1/3 + 1/4 famously diverges,
 * but if the numbers are IEEE floats, it doesn't - in fact, it never grows
 * over cca 15.404; note that the reason is not that the 1/n eventualy drops
 * below MIN_FLOAT, but rather that the addition of the relatively tiny 1/n
 * to the relatively large sum no longer makes a difference. For 32bit floats,
 * the growth stops when adding 1/2097152 (0x35000000)
 * fails to increase the running sum of 0x4176757c */

/* When printing every step with -v, most time is spent printing. */

#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <err.h>

#define FFMT "%9llu %15.13f %#010x %21.18f %#010x\n"
#define LFMT "%9llu %.16f %#18llx %.9f %#18llx\n"

int fflag = 1;
int dflag = 0;
int lflag = 0;
int vflag = 0;

void
usage(void)
{
	errx(1, "usage: harmonic [-fdlv]");
}

void
fharm(void) {
	uint64_t n = 1;
	float x = 1/n;
	float this = 0;
	float next = x;
	do {
		this = next;
		if (vflag) {
			printf(FFMT,
			n, x, *(uint32_t*)(&x), this, *(uint32_t*)(&this));
		}
		x = (1.0) / ++n;
		next = this + x;
	} while (next > this);
	printf(FFMT, n, x, *(uint32_t*)(&x), this, *(uint32_t*)(&this));
}

void
dharm(void) {
	uint64_t n = 1;
	double x = 1/n;
	double this = 0;
	double next = x;
	do {
		this = next;
		if (vflag) {
			printf(LFMT,
			n, x, *(uint64_t*)(&x), this, *(uint64_t*)(&this));
		}
		x = (1.0) / ++n;
		next = this + x;
	} while (next > this);
	printf(LFMT, n, x, *(uint64_t*)(&x), this, *(uint64_t*)(&this));
}

void
lharm(void) {
}

int
main(int argc, char** argv)
{
	int c;

	while ((c = getopt(argc, argv, "fdlv")) != -1) switch(c) {
		case 'f':
			fflag = 1;
			dflag = 0;
			lflag = 0;
			break;
		case 'd':
			fflag = 0;
			dflag = 1;
			lflag = 0;
			break;
		case 'l':
			dflag = 0;
			fflag = 0;
			lflag = 1;
			break;
		case 'v':
			vflag = 1;
			break;
		default:
			usage();
			break;
	}
	argc -= optind;
	argv += optind;

	if (argc)
		usage();

	if (fflag) {
		fharm();
	} else if (dflag) {
		dharm();
	} else if (lflag) {
		lharm();
	}

	return 0;
}
