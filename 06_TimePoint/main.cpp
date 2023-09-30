#include <iostream>
#include <chrono>

int main()
{
	// Create a time_point representing the epoch of the associated steady clock.
	std::chrono::time_point<std::chrono::steady_clock> tp1;
	// or
	// steady_clock::time_point tp1;

	// Add 10 minutes to the time_point.
	tp1 += std::chrono::minutes{ 10 };

	// Store the duration between epoch and time_point.
	auto d1{ tp1.time_since_epoch() };

	// Convert the duration to seconds and output to the console.
	std::chrono::duration<double> d2{ d1 };
	std::cout << d2.count() << " seconds" << std::endl;

	return 0;
}
