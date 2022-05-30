#include<iostream>
#include<iomanip>
using namespace std;

class CClock
{
public:
	explicit CClock(int iHour = 0, int iMinute = 0, int iSecond = 0);
	CClock operator +(int iAddSeconds)const;							//返回若干秒后的时间
	CClock operator - (int iAddSeconds)const;							//返回若干秒前的时间
	int operator - (const CClock& rhs)const;							//相差秒数
	CClock& operator ++();												//时间先++，返回新时间
	CClock operator ++(int);											//时间后++，返回原时间
	bool operator >(const CClock& rhs)const;
	bool operator ==(const CClock& rhs)const;
	bool operator >=(const CClock& rhs)const;
	bool operator <(const CClock& rhs)const;
	bool operator <=(const CClock& rhs)const;
	bool operator !=(const CClock& rhs)const;
	explicit operator int() const;										//类型转换，换算成秒
	friend ostream& operator << (ostream& os, const CClock& rhs);
	friend istream& operator >> (istream& is, CClock& rhs);
private:
	int _iHour, _iMinute, _iSecond;
};

CClock::CClock(int iHour, int iMinute, int iSecond) :_iHour(iHour), _iMinute(iMinute), _iSecond(iSecond)
{

}
CClock CClock::operator+(int iAddSeconds)const
{
	int iSecondTotal = static_cast<int>(*this) + iAddSeconds;
	iSecondTotal = (iSecondTotal % (12 * 60 * 60) + (12 * 60 * 60)) % (12 * 60 * 60);
	int iHour, iMinute, iSecond;
	iHour = iSecondTotal / (60 * 60) % 12;
	iMinute = iSecondTotal % (60 * 60) / 60;
	iSecond = iSecondTotal % 60;
	return CClock(iHour, iMinute, iSecond);
}
//返回若干秒前的时间
CClock CClock::operator - (int iAddSeconds) const
{
	return *this + (-iAddSeconds);
}
//相差秒数
int CClock::operator -(const CClock& rhs)const
{
	return static_cast<int>(*this) - static_cast<int>(rhs);
}
CClock& CClock::operator++()
{
	if (++_iSecond == 60) {
		_iSecond = 0;
		if (++_iMinute == 60) {
			_iMinute = 0;
			if (++_iHour == 12) {
				_iHour = 0;
			}
		}
	}
	return *this;
}
CClock CClock::operator++(int)
{
	CClock tmp(*this);
	++(*this);
	return tmp;
}

bool CClock::operator>(const CClock& rhs)const
{
	return static_cast<int>(*this) > static_cast<int>(rhs);
}
bool CClock::operator==(const CClock& rhs)const
{
	return _iHour == rhs._iHour && _iMinute == rhs._iMinute && _iSecond == rhs._iSecond;
}
bool CClock::operator>=(const CClock& rhs)const
{
	return *this > rhs || *this == rhs;
}
bool CClock::operator<(const CClock& rhs)const
{
	return static_cast<int>(*this) < static_cast<int>(rhs);
}
bool CClock::operator <=(const CClock& rhs)const
{
	return *this < rhs || *this == rhs;
}
bool CClock::operator !=(const CClock& rhs)const
{
	return _iHour != rhs._iHour && _iMinute != rhs._iMinute && _iSecond != rhs._iSecond;
}
CClock::operator int() const
{
	return _iHour * 60 * 60 + _iMinute * 60 + _iSecond;
}
ostream& operator << (ostream& os, const CClock& rhs)
{
	cout.fill('0');
	os << setw(2) << rhs._iHour << ":" << setw(2) << rhs._iMinute << ":" << setw(2) << rhs._iSecond;
	return os;
}
istream& operator >> (istream& is, CClock& rhs)
{
	char ch;
	is >> rhs._iHour >> ch >> rhs._iMinute >> ch >> rhs._iSecond;
	return is;
}

int main()
{
	CClock clock1, clock2, clock3, clock4;
	cin >> clock1 >> clock2;
	cout << clock1 << "" << clock2 << endl;
	++clock1; clock2++;
	cout << clock1 << "" << clock2 << endl;
	clock3 = clock1 + 200;
	clock4 = clock2 - 300;
	cout << clock3 << "" << clock4 << endl;
	cout << clock4 - clock3 << endl;
	cout << (clock4 >= clock3) << endl;
	cout << (clock4 < clock3) << endl;
	cout << (clock4 <= clock3) << endl;
	cout << (clock4 != clock3) << endl;
	return 0;
}















