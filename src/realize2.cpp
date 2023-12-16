#include "../include/realize.hpp"

float Derivative(float A, float deltaX) {
    return (cosf(A + deltaX) - cosf(A - deltaX) / (2 * deltaX));
}

int PrimeCount(int A, int B) {
    std::vector<int> n(B);
    int res = 0;
    for(int i = 0; i < B; i++) {
        n[i] = i;
    }
    for(int i = 2; i < B; i++) {
        if(n[i] != 0) {
            if(i >= A) res += 1;
            for(int j = i * i; j < B; j += i) {
                n[j] = 0;
            }
        }
    }
    return res;
}
