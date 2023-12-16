#include "../include/realize.hpp"

float Derivative(float A, float deltaX) {
    return (cosf(A + deltaX) - cosf(A) / deltaX);
}

int PrimeCount(int A, int B) {
    int res = 0;
    for(int i = A; i <= B; i++) {
        res += 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                res -= 1;
                break;
            }
        }
    }
    return res;
}
