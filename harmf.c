/* The harmonic series 1/1 + 1/2 + 1/3 + 1/4 famously diverges,
 * but if the numbers are IEEE floats, it doesn't - in fact, it never grows
 * over cca 15.404; note that the reason is not that the 1/n eventualy drops
 * below MIN_FLOAT, but rather that the addition of the relatively tiny 1/n
 * to the relatively large sum no longer makes a difference. For 32bit floats,
 * adding 1/2097152 (0x35000000) no longer increases 0x4176757c */

/* With -v, print every step;
 * most of the time is spent in the printing. */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <err.h>

#define FMT "%7u  %15.13f %#010x  %21.18f %#010x\n"

int vflag = 0;

void
usage(void)
{
	errx(1, "usage: harm [-v]");
}

int
main(int argc, char** argv)
{
	int c;
	uint32_t n = 1;
	float x = 1/n;
	float this = 0;
	float next = x;

	while ((c = getopt(argc, argv, "v")) != -1) switch(c) {
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

	do {
		this = next;
		if (vflag) {
			printf(FMT,
			n, x, *(uint32_t*)(&x), this, *(uint32_t*)(&this));
		}
		x = (1.0) / ++n;
		next = this + x;
	} while (next > this);

	printf(FMT, n, x, *(uint32_t*)(&x), this, *(uint32_t*)(&this));
	return 0;
}
