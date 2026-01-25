#include <iostream>
#include <chrono>
#include "BaselineMatMul.h"
#include "OptimisedMatMul.h"

int main() {
    alignas(16) float a[400][400];
    alignas(16) float b[400][400];
    alignas(16) float c[400][400];
    alignas(16) float d[400][400];

    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 400; j++) {
            a[i][j] = 1.0f;
            b[i][j] = 2.0f;
            c[i][j] = 0.0f;
            d[i][j] = 0.0f;
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    Baseline(a,b,c);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken for normal matrix multiplication - " << duration.count() << std::endl;

    Optimised* o= new Optimised();
    auto start1 = std::chrono::high_resolution_clock::now();
    o->cache_miss(a,b,c);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "Time taken when minimizing cache misses - " << duration1.count()<< std::endl;


    auto start2 = std::chrono::high_resolution_clock::now();
    o->SSE(a,b,c);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
    std::cout << "Time taken by using SSE registers - " << duration2.count() << std::endl;

    auto start3 = std::chrono::high_resolution_clock::now();
    o->AVX(a,b,c);
    auto end3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3);
    std::cout << "Time taken by using AVX registers -  " << duration3.count() << std::endl;


    return 0;
}
