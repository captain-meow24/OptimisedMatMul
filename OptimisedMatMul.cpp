//
// Created by kanishka on 12/1/26.
//
#include "OptimisedMatMul.h"
#include <xmmintrin.h>
#include <immintrin.h>

void Optimised::cache_miss(float (&a)[400][400],float (&b)[400] [400], float (&c)[400][400]) {
    for (int i=0; i<400; i++) {
        for (int k=0; k<400; k++) {
            for (int j=0;j<400;j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Optimised::transpose(float (&B)[400][400], float (&BT)[400][400], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            BT[j][i] = B[i][j];
        }
    }
}


void Optimised::SSE(float (&a)[400][400],float (&b)[400] [400], float (&c)[400][400]) {
    alignas(16) float bt[400][400]{};
    alignas(16) float temp[4];
    transpose(b, bt, 400);
    for (int i=0; i<400; i++) {
        for (int j=0; j<400; j++) {
            __m128 sum = _mm_setzero_ps();
            for (int k=0; k<400; k+=4) {
                __m128 va = _mm_load_ps(&a[i][k]);
                __m128 vb= _mm_load_ps(&bt[j][k]);
                sum = _mm_add_ps(sum, _mm_mul_ps(va, vb));
            }
            _mm_store_ps(temp, sum);
            c[i][j] = temp[0] + temp[1] + temp[2] + temp[3];

        }
    }
}

void Optimised::AVX(float (&a)[400][400], float (&b)[400][400], float (&c)[400][400]) {
    alignas(32) float bt[400][400];
    alignas(32) float temp[8];
    transpose(b, bt, 400);
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 400; j++) {
            __m256 sum = _mm256_setzero_ps();
            for (int k = 0; k + 7 < 400; k += 8) {
                __m256 va = _mm256_loadu_ps(&a[i][k]);
                __m256 vb = _mm256_loadu_ps(&bt[j][k]);
                sum = _mm256_add_ps(sum, _mm256_mul_ps(va, vb));
            }
            _mm256_store_ps(temp, sum);
            c[i][j] = temp[0] + temp[1] + temp[2] + temp[3] + temp[4] + temp[5] + temp[6] + temp[7];
        }
    }
}

