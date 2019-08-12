#include <stdint.h>
#include "utils.h"

float
uf(uint32_t u)
{
	union uf uf;
	uf.u = u;
	return uf.f;
}

uint32_t
fu(float f)
{
	union uf uf;
	uf.f = f;
	return uf.u;
}
