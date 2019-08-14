#include <stdint.h>

union uf {
	uint32_t u;
	float    f;
};

union ud {
	uint64_t u;
	double   d;
};

union uD {
	unsigned long long u;
	long double        D;
};

float			uf(uint32_t);
uint32_t		fu(float);

double			ud(uint64_t);
uint64_t		du(double);

long double		uD(unsigned long long);
unsigned long long	Du(long double);

#define F_ALMOST10 0x0.ffffffp0 /* 0x3f7fffff, just below 0x3f800000 = 1.0 */
#define F_ALMOST15 0x1.7ffffep0 /* 0x3fbfffff, just below 0x3fc00000 = 1.5 */
#define F_ALMOST20 0x1.fffffep0 /* 0x3fffffff, just below 0x40000000 = 2.0 */
#define F_ALMOST30 0x2.fffffbp0 /* 0x403fffff, just below 0x40400000 = 3.0 */
#define F_ALMOST35 0x3.7ffffbp0 /* 0x405fffff, just below 0x40600000 = 3.5 */
#define F_ALMOST40 0x3.fffffbp0 /* 0x407fffff, just below 0x40800000 = 4.0 */

#define F_FOLLOW00 0x1.0p-126   /* 0x00800000, smallest normal float       */
#define F_FOLLOW05 0x0.800001p0 /* 0x3f000001, just above 0x3f000000 = 0.5 */
#define F_FOLLOW10 0x1.000002p0 /* 0x38000001, just above 0x3f800000 = 1.0 */
#define F_FOLLOW15 0x1.800001p0 /* 0x3fc00001, just above 0x3fc00000 = 1.5 */
#define F_FOLLOW20 0x2.000003p0 /* 0x40000001, just above 0x40000000 = 2.0 */
#define F_FOLLOW25 0x2.800003p0 /* 0x40200001, just above 0x40200000 = 2.5 */
#define F_FOLLOW30 0x3.000003p0 /* 0x40400001, just above 0x40400000 = 3.0 */
#define F_FOLLOW40 0x4.000005p0 /* 0x40800001, just above 0x40800000 = 4.0 */

#define D_ALMOST10 0x0.fffffffffffffap0	/* 0x3fefffffffffffff */
#define D_ALMOST15 0x1.7ffffffffffff7p0	/* 0x3ff7ffffffffffff */
#define D_ALMOST20 0x1.fffffffffffff7p0	/* 0x3fffffffffffffff */
#define D_ALMOST30 0x2.ffffffffffffefp0	/* 0x4007ffffffffffff */
#define D_ALMOST35 0x3.7fffffffffffefp0	/* 0xc00bffffffffffff */
#define D_ALMOST40 0x3.ffffffffffffefp0	/* 0x400fffffffffffff */

#define D_FOLLOW00 0x1.0p-1022		/* 0x0010000000000000 */
#define D_FOLLOW05 0x0.80000000000005p0	/* 0x3fe0000000000001 */
#define D_FOLLOW10 0x1.00000000000010p0	/* 0x3ff0000000000001 */
#define D_FOLLOW20 0x2.00000000000020p0	/* 0x4000000000000001 */
#define D_FOLLOW25 0x2.80000000000020p0	/* 0x4004000000000001 */
#define D_FOLLOW30 0x3.00000000000020p0	/* 0x4008000000000001 */
#define D_FOLLOW40 0x4.00000000000030p0	/* 0x4010000000000001 */
