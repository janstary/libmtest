#include <stdint.h>

union uf {
	uint32_t u;
	float    f;
};

float		uf(uint32_t);
uint32_t	fu(float);

#define F_ALMOST10 (0x0.ffffffp0) /* 0x3f7fffff, just below 0x3f800000 = 1.0 */
#define F_ALMOST15 (0x1.7ffffep0) /* 0x3fbfffff, just below 0x3fc00000 = 1.5 */
#define F_ALMOST20 (0x1.fffffep0) /* 0x3fffffff, just below 0x40000000 = 2.0 */
#define F_ALMOST30 (0x2.fffffbp0) /* 0x403fffff, just below 0x40400000 = 3.0 */
#define F_ALMOST35 (0x3.7ffffbp0) /* 0x405fffff, just below 0x40600000 = 3.5 */
#define F_ALMOST40 (0x3.fffffbp0) /* 0x407fffff, just below 0x40800000 = 4.0 */
#define F_ALMOST55 (0x5.7ffff5p0) /* 0x40afffff, just below 0x40b00000 = 5.5 */
