#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#include "which.h"

struct test {
	int	round;
	char*	comment;
	struct io {
		ITYPE i;
		ITYPE o;
	}	*io;
};
