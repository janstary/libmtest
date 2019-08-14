#include "test-lrintf.h"
#include "test-func.h"
#include "utils.h"

struct io roundn[] = {
	{ INT8_MAX,	INT8_MAX	},
	{ INT16_MAX,	INT16_MAX	},
	/*
	INT32_MAX is 2147483647, but (float) INT_MAX = 2147483648.00000000,
	as the INT32_MAX int is already too big to be exactly represented
	as a float. So we get lrintf((float)INT_MAX) = 2147483648.00000000,
        which is not the starting 2147483647. But that's not a lrintf()
	problem, integers this big get already rounded as floats.
	*/

	{ (2 << 23)-1,	(2 << 23)-1	},
	{ (2 << 23),	(2 << 23)	},
	{ (2 << 23)+1,	(2 << 23)+0	},
	{ (2 << 23)+2,	(2 << 23)+2	},

	{ (2 << 24)-2,	(2 << 24)-2	},
	{ (2 << 24)-1,	(2 << 24)-0	},
	{ (2 << 24),	(2 << 24)	},
	{ (2 << 24)+1,	(2 << 24)+0	},
	{ (2 << 24)+2,	(2 << 24)+0	},
	{ (2 << 24)+3,	(2 << 24)+4	},
	{ (2 << 24)+4,	(2 << 24)+4	},

	{ (2 << 25)-4,	(2 << 25)-4	},
	{ (2 << 25)-3,	(2 << 25)-4	},
	{ (2 << 25)-2,	(2 << 25)-0	},
	{ (2 << 25)-1,	(2 << 25)-0	},
	{ (2 << 25),	(2 << 25)	},
	{ (2 << 25)+1,	(2 << 25)+0	},
	{ (2 << 25)+2,	(2 << 25)+0	},
	{ (2 << 25)+3,	(2 << 25)+0	},
	{ (2 << 25)+4,	(2 << 25)+0	},
	{ (2 << 25)+5,	(2 << 25)+8	},
	{ (2 << 25)+6,	(2 << 25)+8	},
	{ (2 << 25)+7,	(2 << 25)+8	},
	{ (2 << 25)+8,	(2 << 25)+8	},
	/* ... */
	{ 0.0,		0 }
};

struct io roundd[] = {
	{ 0.0,		0 }
};

struct io roundu[] = {
	{ 0.0,		0 }
};

struct io roundz[] = {
	{ 0.0,		0 }
};

struct test tests[] = {
	{ FE_TONEAREST,  "rounding to nearest",   roundn },
	{ FE_DOWNWARD,	 "rounding downward",     roundd },
	{ FE_UPWARD,	 "rounding upward",       roundu },
	{ FE_TOWARDZERO, "rounding towards zero", roundz }
};
