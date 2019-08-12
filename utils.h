#include <stdint.h>

#define FLOAT(_hex)	(*((float*)(&(_hex))))

union uf {
	uint32_t u;
	float    f;
};

float		u2f(uint32_t);
uint32_t	f2u(float);
