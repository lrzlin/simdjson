#ifndef SIMDJSON_LSX_INTRINSICS_H
#define SIMDJSON_LSX_INTRINSICS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/lsx/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <lsxintrin.h>

static_assert(sizeof(__m128i) <= simdjson::SIMDJSON_PADDING, "insufficient padding for LoongArch SX");

simdjson_inline uint64_t lsx_movfr2gr_d(__m128i v) {
#if defined(__clang__) && (__clang_major__ < 24)
  return __lsx_vpickve2gr_du(v, 0);
#else
  uint64_t r;
  __asm__("movfr2gr.d %0, %1" : "=r"(r) : "f"(((v2f64)v)[0]));
  return r;
#endif
}

simdjson_inline int64_t lsx_movfr2gr_s(__m128i v) {
#if defined(__clang__) && (__clang_major__ < 24)
  return __lsx_vpickve2gr_w(v, 0);
#else
  int64_t r;
  __asm__("movfr2gr.s %0, %1" : "=r"(r) : "f"(((v2f64)v)[0]));
  return r;
#endif
}

#endif //  SIMDJSON_LSX_INTRINSICS_H
