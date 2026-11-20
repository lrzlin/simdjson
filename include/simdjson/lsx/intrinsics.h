#ifndef SIMDJSON_LSX_INTRINSICS_H
#define SIMDJSON_LSX_INTRINSICS_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/lsx/base.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <lsxintrin.h>

static_assert(sizeof(__m128i) <= simdjson::SIMDJSON_PADDING, "insufficient padding for LoongArch SX");

simdjson_inline uint64_t lsx_movfr2gr_d(__m128i v) {
  uint64_t r;
  __asm__("movfr2gr.d %0, %1" : "=r"(r) : "f"(((v2f64)v)[0]));
  return r;
}

simdjson_inline int64_t lsx_movfr2gr_s(__m128i v) {
  int64_t r;
  __asm__("movfr2gr.s %0, %1" : "=r"(r) : "f"(((v2f64)v)[0]));
  return r;
}

simdjson_inline int64_t lsx_movfrh2gr_s(__m128i v) {
  int64_t r;
  __asm__("movfrh2gr.s %0, %1" : "=r"(r) : "f"(((v2f64)v)[0]));
  return r;
}

#endif //  SIMDJSON_LSX_INTRINSICS_H
