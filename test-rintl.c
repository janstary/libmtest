#include "test-rintl.h"
#include "test-func.h"
#include "utils.h"

struct io roundn[] = {
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

struct io roundd[] = {
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

struct io roundu[] = {
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

struct io roundz[] = {
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

struct test tests[] = {
	{ FE_TONEAREST,  "rounding to nearest",   roundn },
	{ FE_DOWNWARD,	 "rounding downward",     roundd },
	{ FE_UPWARD,	 "rounding upward",       roundu },
	{ FE_TOWARDZERO, "rounding towards zero", roundz }
};
