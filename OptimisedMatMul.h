//
// Created by kanishka on 12/1/26.
//

#ifndef OPTIMISEDMATMUL_H
#define OPTIMISEDMATMUL_H

#include<iostream>
#include<vector>

class Optimised {
    void cache_miss(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &c);
    void SSE(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &c);
    void AVX(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &c);
};


#endif //OPTIMISEDMATMUL_H
