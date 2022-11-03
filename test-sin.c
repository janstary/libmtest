#include "test-sin.h"
#include "utils.h"
#include "test.h"

struct io io[] = {
	{ -3*M_PI_2,	+1.0 },
	{ -M_PI_2,	-1.0 },
	{ M_PI_2,	+1.0 },
	/* { M_PI,	+0.0 }, */
	{ 3*M_PI_2,	-1.0 },
	/* { 2*M_PI,	+0.0 }, */
	{ +0.0,		+0.0 },
};

struct test test = { NULL, io };
