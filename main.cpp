#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> a, b,c,d;
    for (int i=0; i<100; i++) {
        std::vector<int> k;
        for (int f=0; f<100; f++) {
            k.push_back(1);
        }
        a.push_back(k);
        std::vector<int> l;
        for (int f=0; f<100; f++) {
            l.push_back(2);
        }
        b.push_back(l);
    }
    return 0;
}