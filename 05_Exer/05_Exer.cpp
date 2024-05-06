/* Construct a UTC time. Convert this time to the local time in Tokyo, Japan. Further convert the resulting time
   to New York time. And finally convert the resulting time for GMT. Verify that the original UTC time and the final
   GMT time are equal. Tip: the time zone identifier for Tokyo is Asia/Tokyo, for New York is it America/New_York,
   and for GMT is it GMT. */

#include <chrono>
#include <iostream>
using std::cout;
using std::endl;
using namespace std::chrono;

int main()
{
	auto utcTime{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s };

	zoned_time<seconds> tokyoTime{ "Asia/Tokyo", utcTime };
	zoned_time<seconds> newYorkTime{ "America/New_York", tokyoTime };
	zoned_time<seconds> gmtTime{ "GMT", newYorkTime };

	cout << utcTime << endl;
	cout << gmtTime << endl;
}
