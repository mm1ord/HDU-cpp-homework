#include<iostream>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int n) {
	if (n == 1 || n == -1 || n == 0)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}


int main() {
	list<int> l;
	int num1=0; int num2=0;
	list<int>::iterator i;
	cout << "请输入元素:" << endl;
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(l));

	for (i = l.begin(); i != l.end(); i++)
	{
		if (*i == 0)
		{
			num1++;
		}
		if (isPrime(*i))
		{
			num2++;
		}
	}

	cout << endl;
	cout << "0的个数：" << num1<<endl;
	cout << "素数的个数" << num2 << endl;
	return 0;

} 