#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;
class mystring {
private:
	char* buf;
public:
	mystring() {
		buf = new char[MAX];
		cout << "construct 0" << endl;
	}
	mystring(char* ch) {
		buf = new char[MAX];
		strcpy(buf, ch);
		cout << "construct 1" << endl;
	}
	void operator=(mystring& s) {
		strcpy(buf, "c++");
		strcat(buf, s.buf);
	}
	void display() {
		cout << buf << endl;
	}
	~mystring() {
		delete buf;
		cout << "destruct" << endl;
	}
};
int main()
{
	char* str = new char[MAX];
	cin >> str;
	mystring str1(str);
	str1.display();
	mystring str2;
	str2 = str1;
	str2.display();
	return 0;
}