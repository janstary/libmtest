#include <stdint.h>

union uf {
	uint32_t u;
	float    f;
};

float		uf(uint32_t);
uint32_t	fu(float);

#define F_BELOW15 (0x1.7ffffep0) /* 0x3fbfffff, just below 0x3fc00000 = 1.5 */
#define F_BELOW35 (0x3.7ffffbp0) /* 0x405fffff, just below 0x40600000 = 3.5 */
#define F_BELOW55 (0x5.7ffff5p0) /* 0x40afffff, just below 0x40b00000 = 5.5 */
