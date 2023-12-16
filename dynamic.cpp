#include <iostream>
#include <string>
#include <dlfcn.h>


int main() {
    std::string lib1 = "../build/lib_1.so";
	std::string lib2 = "../build/lib_2.so";
	
	void *curlib = dlopen(lib1.c_str(), RTLD_LAZY);

	float (*Derivative)(float A, float deltaX);
	int (*PrimeCount)(int A, int B);

	Derivative = (float (*)(float, float)) dlsym(curlib, "Derivative");
    PrimeCount = (int (*)(int, int)) dlsym(curlib, "PrimeCount");

    int choose;
	int number_lib = 1;
	std::cout << "Enter 1 or 2 to select a function(1 - Derivate; 2 - PrimeCount) or 0 switch to library  or -1 to exit" << std::endl;

	while(std::cin >> choose) {

		if (choose == 0) {
			dlclose(curlib);
			if (number_lib == 1) {
				std::cout << "You switched to library number 2" << std::endl;
				curlib = dlopen(lib2.c_str(), RTLD_LAZY);
				number_lib = 2;

			} else {
				std::cout << "You switched to library number 1" << std::endl;
				curlib = dlopen(lib1.c_str(), RTLD_LAZY);
				number_lib= 1;
			}
			Derivative = (float (*)(float, float)) dlsym(curlib, "Derivative");
    		PrimeCount = (int (*)(int, int)) dlsym(curlib, "PrimeCount");
		}

		if (choose == 1) {
			float A, deltaX, Ans1;
			std::cout << "Enter A and deltaX" << std::endl;
			std::cin >> A >> deltaX;
			Ans1 = Derivative(A, deltaX);
			std::cout<<"Derivative value: " << Ans1 << std::endl;
		}

		if (choose == 2) {
			int A, B, Ans2;
			std::cout << "Enter A and B" << std::endl;
			std::cin >> A >> B;
			Ans2 = PrimeCount(A, B);
			std::cout << "PrimeCount value: " << Ans2 << std::endl;
		}

		if (choose == -1) {
			std::cout << "Exit" << std::endl;
			return 0;
		}

		std::cout << "Enter 1 or 2 to select a function(1 - Derivate; 2 - PrimeCount) or 0 switch to library  or -1 to exit" << std::endl;
		
	}
	
}
