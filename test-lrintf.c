#include "test-lrintf.h"
#include "utils.h"
#include "test.h"

struct io roundn[] = {
/* With small values, test the breaking points:
 * just below and just above 0.5 */
	{ +0.5,		+0 },
	{ +F_FOLLOW05,	+1 },
	{ +1.0,		+1 },
	{ +F_ALMOST15,	+1 },
	{ +1.5,		+2 },
	{ +2.0,		+2 },
	{ +2.5,		+2 },
	{ +F_FOLLOW25,	+3 },
	{ +3.0,		+3 },
	{ +F_ALMOST35,	+3 },
	{ +3.5,		+4 },
	{ +4.0,		+4 },
/* After (2 << 20), ints are only representable as floats
 * with a precision of .25, so that's what we test on. */
	{ (2 << 20),		(2 << 20)	},
	{ (2 << 20) + 0.25,	(2 << 20)	},
	{ (2 << 20) + 0.50,	(2 << 20)	},
	{ (2 << 20) + 0.75,	(2 << 20) + 1	},
	{ (2 << 20) + 1.00,	(2 << 20) + 1	},
	{ (2 << 20) + 1.25,	(2 << 20) + 1	},
	{ (2 << 20) + 1.50,	(2 << 20) + 2	},
/* After (2 << 21), the precision drops to 0.5;
 * that's the last place where rounding does anything. */
	{ (2 << 21),		(2 << 21)	},
	{ (2 << 21) + 0.50,	(2 << 21)	},
	{ (2 << 21) + 1.00,	(2 << 21) + 1	},
	{ (2 << 21) + 1.50,	(2 << 21) + 2	},
/* After (2 << 22), the precision drops to 1.0;
 * so just check that integers get rounded to themselves. */
	{ 0x2.0p22,	0x0000000000800000L	},
	{ 0x2.0p23,	0x0000000001000000L	},
	{ 0x2.0p24,	0x0000000002000000L	},
	{ 0x2.0p25,	0x0000000004000000L	},
	{ 0x2.0p26,	0x0000000008000000L	},
	{ 0x2.0p27,	0x0000000010000000L	},
	{ 0x2.0p28,	0x0000000020000000L	},
	{ 0x2.0p29,	0x0000000040000000L	},
	{ 0x2.0p30,	0x0000000080000000L	},
/* On a machine with 32-bit longs, this cannot be represented,
 * and the return value of lrintf() is undefined. Nevermind,
 * as there is nothing going on with respect to rounding.
	{ 0x2.0p31,	0x0000000100000000L	},
	{ 0x2.0p32,	0x0000000200000000L	},
	{ 0x2.0p33,	0x0000000400000000L	},
	{ 0x2.0p34,	0x0000000800000000L	},
	{ 0x2.0p35,	0x0000001000000000L	},
	{ 0x2.0p36,	0x0000002000000000L	},
	{ 0x2.0p37,	0x0000004000000000L	},
	{ 0x2.0p38,	0x0000008000000000L	},
	{ 0x2.0p39,	0x0000010000000000L	},
	{ 0x2.0p40,	0x0000020000000000L	},
	{ 0x2.0p41,	0x0000040000000000L	},
	{ 0x2.0p42,	0x0000080000000000L	},
	{ 0x2.0p43,	0x0000100000000000L	},
	{ 0x2.0p44,	0x0000200000000000L	},
	{ 0x2.0p45,	0x0000400000000000L	},
	{ 0x2.0p46,	0x0000800000000000L	},
	{ 0x2.0p47,	0x0001000000000000L	},
	{ 0x2.0p48,	0x0002000000000000L	},
	{ 0x2.0p49,	0x0004000000000000L	},
	{ 0x2.0p50,	0x0008000000000000L	},
	{ 0x2.0p51,	0x0010000000000000L	},
	{ 0x2.0p52,	0x0020000000000000L	},
	{ 0x2.0p53,	0x0040000000000000L	},
	{ 0x2.0p54,	0x0080000000000000L	},
	{ 0x2.0p55,	0x0100000000000000L	},
	{ 0x2.0p56,	0x0200000000000000L	},
	{ 0x2.0p57,	0x0400000000000000L	},
	{ 0x2.0p58,	0x0800000000000000L	},
	{ 0x2.0p59,	0x1000000000000000L	},
	{ 0x2.0p60,	0x2000000000000000L	},
	{ 0x2.0p61,	0x4000000000000000L	},
	{ 0x2.0p62,	0x7fffffffffffffffL 	},
*/
/*
	{ 0x2.0p62,	0x8000000000000000 },
	{ INT_MAX,	INT_MAX		},
	{ LONG_MAX,	LONG_MAX	},
*/
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
