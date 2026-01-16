#include <iostream>
#include <vector>

int main() {
    alignas(16) float a[100][100];
    alignas(16) float b[100][100];
    alignas(16) float c[100][100];
    alignas(16) float d[100][100];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = 1.0f;
            b[i][j] = 2.0f;
            c[i][j] = 0.0f;
            d[i][j] = 0.0f;
        }
    }

    return 0;
}