#include <iostream>
#include <vector>

int main() {
    alignas(16) std::vector<std::vector<float>> a, b,c,d;
    for (int i=0; i<100; i++) {
        std::vector<float> k;
        for (int f=0; f<100; f++) {
            k.push_back(1);
        }
        a.push_back(k);
        std::vector<float> l;
        for (int f=0; f<100; f++) {
            l.push_back(2);
        }
        b.push_back(l);
        std::vector<float> m;
        for (int f=0; f<100; f++) {
            m.push_back(0);
        }
        c.push_back(m);
    }
    return 0;
}