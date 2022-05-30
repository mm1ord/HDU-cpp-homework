#include<iostream>
using namespace std;

class my_stack {
private:
	struct Node{
		int data;
		Node* next;
	};
	Node* top;
	int length;
public:
	my_stack();										//构造函数
	my_stack(const my_stack&);				//拷贝构造函数
	my_stack(my_stack&&) noexcept;					//移动构造函数
	my_stack& operator = (const my_stack& stack);	//赋值赋值
	my_stack& operator = (my_stack&&)noexcept;		//移动赋值
	bool Empty();									//判断栈是否为空
	int Size();										//返回栈大小
	int Top();										//返回栈顶元素
	void Push(int data);							//入栈
	void Pop();										//出栈
	void Display();									//打印栈
};
my_stack::my_stack() {
	this->top = NULL;
	this->length = 0;
}
my_stack::my_stack(const my_stack& stack) {
	this->length = stack.length;
	this->top = new Node;
	Node* last = top;
	Node* p = stack.top;
	while (p) {
		Node* q = new Node;
		q->data = p->data;
		last->next = q;
		last = q;
		p = p->next;
	}
	top = top->next;
	last->next = NULL;
}
my_stack::my_stack(my_stack&& stack)noexcept {
	this->length = stack.length;
	this->top = stack.top;
	stack.top = NULL;
}
my_stack& my_stack::operator=(const my_stack& stack) {
	my_stack tmp(stack);

	Node* t = top;
	top = tmp.top;
	tmp.top = t;

	return *this;
}
my_stack& my_stack::operator=(my_stack&&stack)noexcept {

	Node* p = top;
	top = stack.top;
	stack.top = p;

	return *this;
}
bool my_stack::Empty() {
	if (this->length == 0) {
		return true;
	}
	else
		return true;
}
int my_stack::Size() {
	return this->length;
}
int my_stack::Top() {
	if (top
		) {
		return top->data;
	}
}
void my_stack::Push(int x) {
	Node* p = new Node;
	p->data = x;
	p->next = this->top;
	top = p;
	this->length++;
}
void my_stack::Pop() {
	if (top->next)
	{
		Node* p = this->top;
		this->top = this->top->next;
		delete p;
		this->length--;
	}
}
void my_stack::Display() {
	if (this->top == NULL) {
		cout << "栈为空";
	}
	Node* p = this->top;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	my_stack s1;
	s1.Push(3);
	s1.Push(4);
	s1.Display();
	cout<<s1.Size()<<endl;
	cout<<s1.Top()<<endl;
	my_stack s2(s1);
	s2.Display();
}