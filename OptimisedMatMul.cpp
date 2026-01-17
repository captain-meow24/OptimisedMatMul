//
// Created by kanishka on 12/1/26.
//
#include "OptimisedMatMul.h"
#include <xmmintrin.h>
#include <immintrin.h>

void Optimised::cache_miss(float (&a)[100][100],float (&b)[100] [100], float (&c)[100][100]) {
    for (int i=0; i<100; i++) {
        for (int k=0; k<100; k++) {
            for (int j=0;j<100;j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Optimised::transpose(float (&B)[100][100], float (&BT)[100][100], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            BT[j][i] = B[i][j];
        }
    }
}


void Optimised::SSE(float (&a)[100][100],float (&b)[100] [100], float (&c)[100][100]) {
    alignas(16) float bt[100][100]{};
    alignas(16) float temp[4];
    transpose(b, bt, 100);
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            __m128 sum = _mm_setzero_ps();
            for (int k=0; k<100; k+=4) {
                __m128 va = _mm_load_ps(&a[i][k]);
                __m128 vb= _mm_load_ps(&bt[j][k]);
                sum = _mm_add_ps(sum, _mm_mul_ps(va, vb));
            }
            _mm_store_ps(temp, sum);
            c[i][j] = temp[0] + temp[1] + temp[2] + temp[3];

        }
    }
}
