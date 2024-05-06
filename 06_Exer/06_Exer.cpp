/* Write a getDurationsinceMidnight() function that returns the duration between midnught and the current time.
   Tip: The function mktime(), defined in <ctime> could be useful in your implementation. It accepts a tm* as
   argument and returns a time_t. It´s basically the opposite of what localtime() does. Use your function to print
   out the number of seconds since midnight to yhe standard output console. Finally, use the hh_mm_ss class to 
   convert the duration returned by your function to hours, minutes and seconds, and print the result on standard 
   output. */

#include <ctime>
#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using namespace std::chrono;

system_clock::duration getDurationSinceMidnight()
{
	// Get current time.
	auto now{ system_clock::now() };

	// From the current time, construct a time representing
	// midnight of the current day.
	time_t nowTimeT{ system_clock::to_time_t(now) };
	tm midnightTm{ 0 };
	localtime_s(&midnightTm, &nowTimeT);
	midnightTm.tm_hour = 0;
	midnightTm.tm_min = 0;
	midnightTm.tm_sec = 0;
	// Construct a time_point for midnight.
	auto midnight{ system_clock::from_time_t(mktime(&midnightTm)) };

	return now - midnight;
}

int main()
{
	auto durationSinceMidnight{ getDurationSinceMidnight() };
	auto numberOfSecondsSinceMidnight{ duration_cast<seconds>(durationSinceMidnight).count() };
	cout << numberOfSecondsSinceMidnight << endl;

	hh_mm_ss hms{ durationSinceMidnight };
	cout << hms.hours().count() << ":" << hms.minutes().count() << ":" << hms.seconds().count() << endl;
}