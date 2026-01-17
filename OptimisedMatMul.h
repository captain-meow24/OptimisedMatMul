//
// Created by kanishka on 12/1/26.
//

#ifndef OPTIMISEDMATMUL_H
#define OPTIMISEDMATMUL_H

#include<iostream>


class Optimised {
public:
    void cache_miss(float (&a)[400][400],float (&b)[400] [400], float (&c)[400][400]);
    void SSE(float (&a)[400][400],float (&b)[400] [400], float (&c)[400][400]);
    void AVX(float (&a)[400][400],float (&b)[400][400], float (&c)[400][400]);

    void transpose(float (&B)[400][400], float (&BT)[400][400], int N);
};


#endif //OPTIMISEDMATMUL_H
