#include <iostream>
#include <chrono>

using namespace std::chrono;

int main()
{
	{
		time_point<steady_clock, seconds> tpSeconds{ 42s };
		// Convert seconds to milliseconds implicitly.
		time_point<steady_clock, milliseconds> tpMilliseconds{ tpSeconds };

		std::cout << tpMilliseconds.time_since_epoch().count() << "ms" << std::endl;
	}

	{
		time_point<steady_clock, milliseconds> tpMilliseconds{ 42'424ms };
		// Convert milliseconds to seconds explicitly.
		time_point<steady_clock, seconds> tpSeconds{
			time_point_cast<seconds>(tpMilliseconds) };
		// Or:
		//auto tpSeconds{ time_point_cast<seconds>(tpMilliseconds) };

		// Convert seconds back to milliseconds and output the result.
		milliseconds ms{ tpSeconds.time_since_epoch() };
		std::cout << ms.count() << "ms" << std::endl;
	}

	return 0;
}
