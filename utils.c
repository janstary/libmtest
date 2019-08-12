#include <stdint.h>
#include "utils.h"

float
u2f(uint32_t u)
{
	union uf uf;
	uf.u = u;
	return uf.f;
}

uint32_t
f2u(float f)
{
	union uf uf;
	uf.f = f;
	return uf.u;
}
