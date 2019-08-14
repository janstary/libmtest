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

double
ud(uint64_t u)
{
	union ud ud;
	ud.u = u;
	return ud.d;
}

uint64_t
du(double d)
{
	union ud ud;
	ud.d = d;
	return ud.u;
}

long double
uD(unsigned long long u)
{
	union uD uD;
	uD.u = u;
	return uD.D;
}

unsigned long long
Du(long double D)
{
	union uD uD;
	uD.D = D;
	return uD.u;
}
