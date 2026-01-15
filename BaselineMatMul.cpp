#include "BaselineMatMul.h"
//
// Created by kanishka on 12/1/26.
//
Baseline::Baseline(std::vector<std::vector<float>> &a, std::vector<std::vector<float>> &b, std::vector<std::vector<float>> &c) {
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            for (int k=0;k<100;k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}