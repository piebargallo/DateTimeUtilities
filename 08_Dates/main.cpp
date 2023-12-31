#include <chrono>
#include <iostream>

using namespace std::chrono;

int main()
{
	year y1{ 2020 };
	auto y2{ 2020y };

	month m1{ 6 };
	auto m2{ June };

	day d1{ 22 };
	auto d2{ 22d };

	// Create a date for 2020-06-22.
	year_month_day fulldate1{ 2020y, June, 22d };
	auto fulldate2{ 2020y / June / 22d };
	auto fulldate3{ 22d / June / 2020y };

	// Create a date for the 3rd Monday of June 2020.
	year_month_day fulldate4{ Monday[3] / June / 2020 };

	// Create a month_day for June 22 of an unspecified year.
	auto june22{ June / 22d };
	// Create a year_month_day for June 22, 2020.
	auto june22_2020{ 2020y / june22 };

	// Create a month_day_last for the last day of a June of an unspecified year.
	auto lastDayOfAJune{ June / last };
	// Create a year_month_day_last for the last day of June for the year 2020.
	auto lastDayOfJune2020{ 2020y / lastDayOfAJune };

	// Create a year_month_weekday_last for the last Monday of June 2020.
	auto lastMondayOfJune2020{ 2020y / June / Monday[last] };

	// Get today as sys_days.
	auto today{ floor<days>(system_clock::now()) };

	// Convert date to time_point.
	system_clock::time_point t1{ sys_days{2020y / June / 22d } };

	// Convert time_point to date.
	year_month_day yearmonthday{ floor<days>(t1) };
	year_month_day today2{ floor<days>(system_clock::now()) };


	// Full date with time: 2020-06-22 09:35:10 UTC.
	auto t2{ sys_days{ 2020y / June / 22d } + 9h + 35min + 10s };

	// Output to stream is supported.
	std::cout << yearmonthday << std::endl;

	return 0;
}