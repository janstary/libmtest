#include "test-rint-up.h"
#include "utils.h"
#include "test.h"

int
pre(void)
{
	return (0 == fesetround(FE_UPWARD)) ? 0 : 1;
}

struct io io[] = {
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

struct test test = { "rounding upward", pre, io };
