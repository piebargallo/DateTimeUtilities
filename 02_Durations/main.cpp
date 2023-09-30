#include <iostream>
#include <chrono>
#include <format>

//using namespace std::chrono;

int main()
{
	// Specify a duration where each tick is 60 seconds.
	std::chrono::duration<long, std::ratio<60>> d1{ 001 };
	std::cout << d1.count() << std::endl;

	// Specify a duration represented by a double with each tick
	// equal to 1 second and assign the largest possible duration to it.
	auto d2{ std::chrono::duration<double>::max() };
	std::cout << d2.count() << std::endl;

	// Define 2 durations:
	// For the first duration, each tick is 1 minute.
	// For the second duration, each tick is 1 second.
	std::chrono::duration<long, std::ratio<60>> d3{ 10 };  // = 10 minutes
	std::chrono::duration<long, std::ratio<1>> d4{ 14 };   // = 14 seconds

	// Compare both durations.
	if (d3 > d4) { 
		std::cout << "d3 > d4" << std::endl; 
	} else { 
		std::cout << "d3 <= d4" << std::endl; 
	}

	return 0;
}
