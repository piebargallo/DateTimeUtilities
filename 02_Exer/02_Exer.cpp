/* Ask the user to enter a date as yyyy-mm-dd, for example, 2020-06-22. Use a regular expression(see Chapter 21, 
   "String Localization and Regular Expressions") to extract the year, month, and day components, and finally, use
   year_month_day to validate the date. */

#include <iostream>
#include <string>
#include <regex>
#include <chrono>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::smatch;
using std::regex;
using namespace std::chrono;

int main()
{
	regex r{ "(\\d{4})-(\\d{2})-(\\d{2})" };
	while (true) {
		cout << "Enter a date (yyyy-mm-dd) (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q") {
			break;
		}

		if (smatch m; regex_match(str, m, r)) {
			cout << "  Parsed date, now validating..." << endl;
			year_month_day date{ year(stoi(m[1])),
				month(stoi(m[2])),
				day(stoi(m[3])) };
			cout << "    date is " <<
				(date.ok() ? "valid." : "not valid!") << endl;
		}
		else {
			cout << "  Cannot parse date!" << endl;
		}
	}
}
