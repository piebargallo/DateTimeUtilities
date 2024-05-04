/* Write a getNumberOf DaysBetweenDates() function that calculates the number of days between two given dates. Test
   your implementation in your main() function. */

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int getNumberOfDaysBetweenDates(const sys_days& date1, const sys_days& date2)
{
	return (date2 - date1).count();
}

int main()
{
	cout << getNumberOfDaysBetweenDates(2019y / June / 22d, 2020y / June / 22d) << endl;
}
