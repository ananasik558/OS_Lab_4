#include <iostream>
#include "include/realize.hpp"

int main() {
    int choose;

    std::cout << "Enter 1 or 2 to select a function(1 - Derivate; 2 - PrimeCount) or -1 to exit" << std::endl;

    while (std::cin >> choose) {

        if (choose == 1) {
            float A, deltaX;
            std::cout << "Enter A and deltaX" << std::endl;
            std::cin >> A >> deltaX;
            std::cout << "Derivative value: " << Derivative(A, deltaX) << std::endl;
        }

        if (choose == 2) {
            int A, B;
            std::cout << "Enter A and B" << std::endl;
            std::cin >> A >> B;
            std::cout << "PrimeCount value: " << PrimeCount(A, B) << std::endl;
        }

        if (choose == -1) {
            std::cout << "Exit" << std::endl;
            return 0;
        }
        std::cout << "Enter 1 or 2 to select a function(1 - Derivate; 2 - PrimeCount) or -1 to exit" << std::endl;
    }
}
