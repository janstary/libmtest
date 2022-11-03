#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#include "which.h"

struct io {
	ITYPE i;
	OTYPE o;
};

struct test {
	int (*pre)(void);
	struct io *io;
};
