//
// Created by kanishka on 12/1/26.
//

#ifndef OPTIMISEDMATMUL_H
#define OPTIMISEDMATMUL_H

#include<iostream>


class Optimised {
    void cache_miss(float (&a)[100][100],float (&b)[100] [100], float (&c)[100][100]);
    void SSE(float (&a)[100][100],float (&b)[100] [100], float (&c)[100][100]);
    void AVX(float (&a)[100][100],float (&b)[100] [100], float (&c)[100][100]);

    void transpose(float (&B)[100][100], float (&BT)[100][100], int N);
};


#endif //OPTIMISEDMATMUL_H
