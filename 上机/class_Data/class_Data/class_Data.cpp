#include<iostream>
using namespace std;
class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int year,int month,int day);
	void PrintDate();
};
Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
void Date::PrintDate()
{
	cout << this->year << "-" << this->month << "-" << this->day << endl;
}
int main()
{
	while (true) {
		int year, month, day;
		cin >> year >> month >> day;
		Date* d = new Date(year, month, day);
		d->PrintDate();
	}
}