#include <iostream>
#include <chrono>
#include <initializer_list>
#include "Array2D.hpp"

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	Array2D<int> a;
	std::initializer_list<int> b;

	for (int i=0; i<100; i++) {
		for (int ii; ii<100; ii++) {
			b[i][ii] = i+ii*100;
		}
	}

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() << "\n";
	return 0;
}
