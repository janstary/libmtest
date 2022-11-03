#include "test-lrint.h"
#include "test-func.h"
#include "utils.h"

struct io roundn[] = {
/* With small values, test the breaking points:
 * just below and just above 0.5 */
	{ 0.5,		0 },
	{ D_FOLLOW05,	1 },
	{ 1.0,		1 },
	{ D_ALMOST15,	1 },
	{ 1.5,		2 },
	{ 2.0,		2 },
	{ 2.5,		2 },
	{ D_FOLLOW25,	3 },
	{ 3.0,		3 },
	{ D_ALMOST35,	3 },
	{ 3.5,		4 },
	{ 4.0,		4 },
/* FIXME: test around 2 << 22, for machines with 32 bit longs */
/* After (2 << 49), ints are only representable as floats
 * with a precision of .25, so that's what we test on. */
	{ 0x2.0p49,		0x0004000000000000	},
	{ 0x2.0p49 + 0.25,	0x0004000000000000	},
	{ 0x2.0p49 + 0.50,	0x0004000000000000	},
	{ 0x2.0p49 + 0.75,	0x0004000000000000 + 1	},
	{ 0x2.0p49 + 1.00,	0x0004000000000000 + 1	},
	{ 0x2.0p49 + 1.25,	0x0004000000000000 + 1	},
	{ 0x2.0p49 + 1.50,	0x0004000000000000 + 2	},
/* After (2 << 50), the precision drops to 0.5;
 * that's the last place where rounding does anything. */
	{ 0x2.0p50,		0x0008000000000000	},
	{ 0x2.0p50 + 0.50,	0x0008000000000000	},
	{ 0x2.0p50 + 1.00,	0x0008000000000000 + 1	},
	{ 0x2.0p50 + 1.50,	0x0008000000000000 + 2	},
/* After (2 << 51), the precision drops to 1.0;
 * so just check that integers get rounded to themselves. */
	{ 0x2.0p51,		0x0010000000000000	},
	{ 0x2.0p52,		0x0020000000000000	},
	{ 0x2.0p53,		0x0040000000000000	},
	{ 0x2.0p54,		0x0080000000000000	},
	{ 0x2.0p55,		0x0100000000000000	},
	{ 0x2.0p56,		0x0200000000000000	},
	{ 0x2.0p57,		0x0400000000000000	},
	{ 0x2.0p58,		0x0800000000000000	},
	{ 0x2.0p59,		0x1000000000000000	},
	{ 0x2.0p60,		0x2000000000000000	},
	{ 0x2.0p61,		0x4000000000000000	},
/*
	{ 0x2.0p62,		0x7fffffffffffffff 	},
	{ LONG_MAX,		LONG_MAX },
		implicit conversion from 'long' to 'double' changes value
		from 9223372036854775807 to 9223372036854775808.
*/
	{ 0.0,		0 }
};

struct io roundd[] = {
	/* FIXME */
	{ 0.0,		0 }
};

struct io roundu[] = {
	/* FIXME */
	{ 0.0,		0 }
};

struct io roundz[] = {
	/* FIXME */
	{ 0.0,		0 }
};

struct test tests[] = {
	{ FE_TONEAREST,  "rounding to nearest",   roundn },
	{ FE_DOWNWARD,	 "rounding downward",     roundd },
	{ FE_UPWARD,	 "rounding upward",       roundu },
	{ FE_TOWARDZERO, "rounding towards zero", roundz }
};
