/* Let´s play a bit with durations. Create a duration, d1, with a precision of seconds, initalaized to 42 seconds.
   Create a second duration, d2, initialized with 1.5 minutes. Calculate the sum of d1 and d2. Write out the result
   to the standard output., once expressed in seconds, once expressed in minutes. */

#include <iostream>
#include <format>
using std::cout;
using std::format;
using std::endl;
using std::ratio;
using namespace std::chrono;

int main()
{
	seconds d1{ 42 };
	duration<double, ratio<60>> d2{ 1.5 };
	auto d3{ d1 + d2 };
	cout << format("{} seconds or {} minutes.",
		d3.count(),
		duration<double, ratio<60>>{ d3 }.count()) << endl;
}