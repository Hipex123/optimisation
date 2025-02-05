#include <iostream>
#include <chrono>
#include <utility>
#include "Array2D.hpp"

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	Array2D<int> a(100, 100);

	for (int i=0; i<100; i++) {
		for (int ii=0; ii<100; ii++) {
			a[i][ii] = ii;
		}
	}
	Array2D<int> b(std::move(a));
	std::cout<<a[1][3]<<"\n";
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() <<"\n";
	return 0;
}
