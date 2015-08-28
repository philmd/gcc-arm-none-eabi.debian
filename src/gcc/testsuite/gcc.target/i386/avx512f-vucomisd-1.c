/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler "vucomisd\[ \\t\]+\[^\n\]*\{sae\}\[^\n\]*%xmm"  } } */

#include <immintrin.h>

volatile __m128d x;
volatile int res;

void extern
avx512f_test (void)
{
  res = _mm_comi_round_sd (x, x, _CMP_NLE_UQ, _MM_FROUND_NO_EXC);
}
