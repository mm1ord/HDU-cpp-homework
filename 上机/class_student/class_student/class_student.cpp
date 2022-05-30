#include <iostream>
using namespace std;

class student {
private:
	int id;
	double score;
public:
	student() {
		this->id = 0;
		this->score = 0;
	}
	void set_student(int id,double score);
	friend double average(student *p,int count);
};
void student::set_student(int id, double score)
{
	this->id = id;
	this->score = score;
}
double average(student* p, int count) {
	double sum=0;
	for (int i = 0; i < count; i++) {
		sum += p[i].score;
	}
	return sum / count;
}
int main()
{
	int x, k = 0;
	double y;
	student *st = new student[100];
	while (cin >> x >> y)
	{
		if (x == 0)
		{
			break;
		}
		st[k].set_student(x, y);
		k++;
	}
	double num = average(st, k);
	cout << num;
}
