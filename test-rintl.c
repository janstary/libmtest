#include "test-rintl.h"
#include "utils.h"
#include "test.h"

struct io roundn[] = {
	{ -4.0L,	-4.0L },
	{ -3.5L,	-4.0L },
	{ -D_ALMOST35,	-3.0L },
	{ -3.0L,	-3.0L },
	{ -D_FOLLOW25,	-3.0L },
	{ -2.5L,	-2.0L },
	{ -2.0L,	-2.0L },
	{ -1.5L,	-2.0L },
	{ -D_ALMOST15,	-1.0L },
	{ -1.0L,	-1.0L },
	{ -D_FOLLOW05,	-1.0L },
	{ -0.5L,	-0.0L },
	{ +0.5L,	+0.0L },
	{ +D_FOLLOW05,	+1.0L },
	{ +1.0L,	+1.0L },
	{ +D_ALMOST15,	+1.0L },
	{ +1.5L,	+2.0L },
	{ +2.0L,	+2.0L },
	{ +2.5L,	+2.0L },
	{ +D_FOLLOW25,	+3.0L },
	{ +3.0L,	+3.0L },
	{ +D_ALMOST35,	+3.0L },
	{ +3.5L,	+4.0L },
	{ +4.0L,	+4.0L },
	{ +0.0L,        +0.0 }
};

struct io roundd[] = {
	{ -4.0L,	-4.0L },
	{ -D_FOLLOW30,	-4.0L },
	{ -3.0L,	-3.0L },
	{ -D_FOLLOW20,	-3.0L },
	{ -2.0L,	-2.0L },
	{ -D_FOLLOW10,	-2.0L },
	{ -1.0L,	-1.0L },
	{ -D_FOLLOW00,	-1.0L },
	{ +D_ALMOST10,	+0.0L },
	{ +1.0L,	+1.0L },
	{ +D_ALMOST20,	+1.0L },
	{ +2.0L,	+2.0L },
	{ +D_ALMOST30,	+2.0L },
	{ +3.0L,	+3.0L },
	{ +D_ALMOST40,	+3.0L },
	{ +4.0L,	+4.0L },
	{ +0.0,         +0.0L }
};

struct io roundu[] = {
	{ -4.0L,	-4.0L },
	{ -D_ALMOST40,	-3.0L },
	{ -3.0L,	-3.0L },
	{ -D_ALMOST30,	-2.0L },
	{ -2.0L,	-2.0L },
	{ -D_ALMOST20,	-1.0L },
	{ -1.0L,	-1.0L },
	{ -D_ALMOST10,	+0.0L },
	{ +D_FOLLOW00,	+1.0L },
	{ +1.0L,	+1.0L },
	{ +D_FOLLOW10,	+2.0L },
	{ +2.0L,	+2.0L },
	{ +D_FOLLOW20,	+3.0L },
	{ +3.0L,	+3.0L },
	{ +D_FOLLOW30,	+4.0L },
	{ +4.0L,	+4.0L },
	{ +D_FOLLOW40,	+5.0L },
	{ +0.0,         +0.0 }
};

struct io roundz[] = {
	{ -D_FOLLOW40,	-4.0L },
	{ -4.0L,	-4.0L },
	{ -D_ALMOST40,	-3.0L },
	{ -D_FOLLOW30,	-3.0L },
	{ -3.0L,	-3.0L },
	{ -D_ALMOST30,	-2.0L },
	{ -D_FOLLOW20,	-2.0L },
	{ -2.0L,	-2.0L },
	{ -D_ALMOST20,	-1.0L },
	{ -D_FOLLOW10,	-1.0L },
	{ -1.0L,	-1.0L },
	{ -D_ALMOST10,	-0.0L },
	{ -D_FOLLOW00,	-0.0L },
	{ +D_FOLLOW00,	+0.0L },
	{ +D_ALMOST10,	+0.0L },
	{ +1.0L,	+1.0L },
	{ +D_FOLLOW10,	+1.0L },
	{ +D_ALMOST20,	+1.0L },
	{ +2.0L,	+2.0L },
	{ +D_FOLLOW20,	+2.0L },
	{ +D_ALMOST30,	+2.0L },
	{ +3.0L,	+3.0L },
	{ +D_FOLLOW30,	+3.0L },
	{ +D_ALMOST40,	+3.0L },
	{ +4.0L,	+4.0L },
	{ +D_FOLLOW40,	+4.0L },
	{ +0.0L,        +0.0 }
};

struct test tests[] = {
	{ FE_TONEAREST,  "rounding to nearest",   roundn },
	{ FE_DOWNWARD,	 "rounding downward",     roundd },
	{ FE_UPWARD,	 "rounding upward",       roundu },
	{ FE_TOWARDZERO, "rounding towards zero", roundz }
};
