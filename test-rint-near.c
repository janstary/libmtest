#include "test-rint-near.h"
#include "utils.h"
#include "test.h"

int
pre(void)
{
	return (0 == fesetround(FE_TONEAREST)) ? 0 : 1;
}

struct io io[] = {
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

struct test test = { pre, io };
