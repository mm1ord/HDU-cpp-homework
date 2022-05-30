#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>

using namespace std;

int main()
{

	vector<int> v;
	deque<int> d;

	auto isPrime = [](int n) {
		if (n == 1 || n == -1 || n == 0)
		{
			return 0;
		}
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return 0;
			}
		}
		return 1;
	};
	//向vector中输入元素
	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(v));
	cout << "vector：" << endl;
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	copy_if(v.begin(), v.end(), inserter(d,d.begin()), isPrime); 
	cout << "deque：" << endl;
	copy(d.begin(), d.end(), ostream_iterator <int>(cout, " "));

}