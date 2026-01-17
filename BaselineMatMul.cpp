#include "BaselineMatMul.h"
//
// Created by kanishka on 12/1/26.
//
Baseline::Baseline(float (&a)[400][400],float (&b)[400] [400], float (&c)[400][400]) {
    for (int i=0; i<400; i++) {
        for (int j=0; j<400; j++) {
            for (int k=0;k<400;k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}