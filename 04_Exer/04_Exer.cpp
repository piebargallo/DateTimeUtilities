/* Write a program that prints out the day of the week of june 22, 2020. */

#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using namespace std::chrono;

int main()
{
	cout << weekday{ 2020y / June / 22d } << endl;
}