#include<iostream>
using namespace std;

class CStack {
private:
	int data[10000];
	int top;
public:
	CStack();
	void Push(int num);
	void Pop();
	bool isEmpty();
	int GetTop();
	void Show();
};
CStack::CStack() {
	this->top = -1;
}
void CStack::Push(int num) {
	this->top++;
	data[this->top] = num;
}
void CStack::Pop()
{
	this->top--;
}
bool CStack::isEmpty()
{
	if (this->top == -1)
	{
		return true;
	}
	else
		return false;
}
int CStack::GetTop() {
	return data[this->top];
}
void CStack::Show() {
	for (int i = top; i >= 0; i--)
	{
		cout << this->data[i] << " ";
	}
	cout << endl;
}
int main() {
	CStack z1;
	CStack z2;
	int v, x;
	while (cin >> v >> x)
	{
		if (v == 1) {
			z1.Push(x);
		}
		else if (v == 2) {
			z2.Push(x);
		}
	}
	z1.Show();
	z2.Show();
}