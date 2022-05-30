#include<iostream>
#include<iomanip>
using namespace std;

class CDate {
public:
	CDate();
	CDate(int year, int month, int day);
	CDate& operator++();//时间先++
	CDate operator++(int);
	CDate operator+ (long days);
	CDate operator-(long days);
	long operator-(const CDate& rhs)const;
	int WeekDay()const;
	bool IsValid();
	int GetMonthDay(int year, int month);// 获取某年某月的天数
	static int IsLeapYear(int year);
	friend ostream& operator<<(ostream& os, const CDate&);
private:
	int m_year, m_month, m_day;
};
CDate::CDate()
{

}
CDate::CDate(int year, int month, int day) :m_year(year), m_month(month), m_day(day)
{

}
bool CDate::IsValid()
{
	return (m_year > 0
		&& m_month > 0 && m_month <= 12
		&& m_day > 0 && m_day <= GetMonthDay(m_year, m_month));
}
int CDate::IsLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0)
		|| year % 400 == 0);
}
// 获取某年某月的天数
int CDate::GetMonthDay(int year, int month)
{
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && IsLeapYear(year))
	{
		++arr[2];
	}
	return arr[month];
}
int CDate::WeekDay()const {
	return (m_day + 2 * m_month + 3 * (m_month + 1) / 5 + m_year + m_year / 4 - m_year / 100 + m_year / 400 + 1 ) % 7;
}
ostream& operator<<(ostream& os, const CDate&rhs) {
	cout.fill('0');
	os << setw(4) << rhs.m_year << "年" << setw(2) << rhs.m_month << "月" << setw(2) << rhs.m_day << "日";
	return os;


}
CDate& CDate:: operator ++() {
	if (++m_year)
	{
		if (++m_month == 12)
		{
			m_month = 0;
			if (++m_day)
			{
				m_day = 0;
			}
		}
	}
	return *this;
}
CDate CDate::operator++(int)
{
	CDate tmp(*this);
	++(*this);
	return tmp;
}
CDate CDate::operator+ (long days){
	if (days < 0) {
		return(*this) - (-days);
	}
	CDate d(*this);
	d.m_day += days;
	while (d.IsValid() == false) {
		int month_day = GetMonthDay(d.m_year, d.m_month);
		d.m_day -= month_day;
		++d.m_month;
		if (d.m_month > 12)
		{
			d.m_month = 1;
			++d.m_year;
		}
	}
	return d;
}
CDate CDate::operator - (long days) {
	if (days < 0)
	{
		return (*this) + (-days);
	}
	CDate d(*this);
	d.m_day -= days;
	while (d.IsValid() == false)
	{
		--d.m_month;
		if (d.m_month == 0)
		{
			--d.m_year;
			d.m_month = 12;
		}
		int pre_month_day = GetMonthDay(d.m_year, d.m_month);
		d.m_day += pre_month_day;
	}
	return d;
}

long CDate::operator-(const CDate& rhs)const//日期-日期 返回天数
{
	int flag = 1;
	CDate max = (*this);
	CDate min = rhs;
	if ((m_year < rhs.m_year) ||
		(m_year == rhs.m_year && m_month < rhs.m_month) ||
		(m_year == rhs.m_year && m_month == rhs.m_month && m_day < rhs.m_day))
	{
		max = rhs;
		min = (*this);
		flag = -1;
	}
	int count = 0;
	while (!(m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day))
	{
		++min;
		++count;
	}
	return flag * count;
}
int main()
{
	CDate c1(2002, 8, 27);
	cout << c1.WeekDay() << endl;
	c1 = c1 + 20;
	cout << c1;
}