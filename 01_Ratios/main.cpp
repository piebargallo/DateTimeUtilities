#include <iostream>
#include <ratio>
#include <format>

int main()
{
	// Define a compile-time rational number.
	using r1 = std::ratio<1, 60>;
	using r2 = std::ratio<1, 30>;
	
	// Compare two rational numbers.
	using res = std::ratio_less<r2, r1>;
	std::cout << std::format("4) r2 < r1: {}", res::value) << std::endl;

	return 0;
}
