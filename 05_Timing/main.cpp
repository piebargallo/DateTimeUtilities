#include <cmath>
#include <iostream>
#include <chrono>

int main()
{
	// Get the start time.
	auto start{ std::chrono::high_resolution_clock::now() };
	// Execute code that you want to time.
	double d{ 0 };
	for (int i{ 0 }; i < 1'000'000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// Get the end time and calculate the difference.
	auto end{ std::chrono::high_resolution_clock::now() };
	auto diff{ end - start };
	// Convert the difference into milliseconds and output to the console.
	std::cout << std::chrono::duration<double, std::milli>{ diff }.count() << "ms" << std::endl;

	return 0;
}
