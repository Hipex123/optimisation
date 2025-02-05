#include <iostream>
#include <chrono>
#include <array>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	std::array<std::array<int, 100>, 100> a;

	for (int i=0; i<100; i++) {
		for (int ii; ii<100; ii++) {
			a[i][ii] = i+ii*100;
		}
	}

	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start).count() << "\n";
	return 0;
}
