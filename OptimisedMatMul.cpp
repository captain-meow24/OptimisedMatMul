//
// Created by kanishka on 12/1/26.
//
#include "OptimisedMatMul.h"
#include <xmmintrin.h>
#include <immintrin.h>

void Optimised::cache_miss(std::vector<std::vector<float>> &a, std::vector<std::vector<float>> &b, std::vector<std::vector<float>> &c) {
    for (int i=0; i<100; i++) {
        for (int k=0; k<100; k++) {
            for (int j=0;j<100;j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Optimised::transpose(float* B, float* BT, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            BT[j*N + i] = B[i*N + j];
        }
    }
}


void Optimised::SSE(std::vector<std::vector<float>> &a, std::vector<std::vector<float>> &b, std::vector<std::vector<float>> &c) {
    float* a1 = &a[0][0];
    std::vector<std::vector<float>> bt;
    bt.reserve(100*100);
    transpose(&b, &bt, 100);
    float* b1 = &bt[0][0];
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            for (int k=0; k<25; k++) {
                __m128 va, vb, vc;
                va= _mm_load_ps(a1);
                va= _mm_load_ps(a1);
                vc = _mm_mul_ps(va, vb);
            }
        }
    }
}
