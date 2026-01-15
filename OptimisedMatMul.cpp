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


void Optimised::SSE(std::vector<std::vector<float>> &a, std::vector<std::vector<float>> &b, std::vector<std::vector<float>> &c) {
    for (int i=0; i<25;i++) {
        
    }
}
