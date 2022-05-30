#include<iostream>
#include<string>
using namespace std;
class People {
private:
	string name;
	int year;
	int height;
	int weight;
	static int people_num;
public:
	People();
	void Show();
	void set_People(string name, int year, int height, int weight);
	static void Show_num();
	static void num_add();
};


People::People() {
	this->name = "exit";
	this->year = 0;
	this->height = 0;
	this->weight = 0;
}
void People::Show() {
	cout << this->name << " " << this->year << " " << this->height << " " << this->weight << endl;
}
void People::Show_num() {
	cout << people_num;
}
void People::num_add() {
	people_num++;
}
int People::people_num = 0; //静态变量初始化

int main() {
	People *p = new People[100];
	int k = 0;
	string name;
	int year;
	int height;
	int weight;
	while (cin >> name >> year >> height >> weight)
	{
		if (name == "exit")
		{
			break;
		}
		p[k].set_People(name, year, height, weight);
		People::num_add();
		k++;
	}
	People::Show_num();
}