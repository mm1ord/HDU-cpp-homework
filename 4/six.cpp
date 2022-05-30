#include<iostream>
using namespace std;

class CSamplePart {
private:
	struct Node {
		int data;
		Node* next;
	}*m_pHead;
public:
	CSamplePart();						//构造函数
	CSamplePart(const CSamplePart&);	//拷贝构造函数
	CSamplePart(CSamplePart&&)noexcept;
	CSamplePart& operator=(const CSamplePart& rhs);
	CSamplePart& operator=(CSamplePart&& rhs)noexcept;
	bool Add(int x);
	void Display();
};
bool CSamplePart::Add(int x) {
	Node* p = m_pHead;
	while (p->next && p->next->data < x) {
		p = p->next;
	}
	if (p->next && p->next->data == x) {
		return false;
	}
	Node* q = new Node;
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}
void CSamplePart::Display() {
	Node* p = m_pHead->next;
	cout << "{";
	while (p) {
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;
}
CSamplePart::CSamplePart() {
	m_pHead = new Node;
	this->m_pHead->next = NULL;
}
CSamplePart::CSamplePart(const CSamplePart &rhs) {
	m_pHead = new Node;
	Node* last = m_pHead;
	Node* p = rhs.m_pHead->next;
	while (p)
	{
		Node* q = new Node;
		q->data = p->data;
		last->next = q;
		last = q;
		p = p->next;
	}
	last->next = NULL;
}
CSamplePart::CSamplePart(CSamplePart&& rhs)noexcept {
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}
CSamplePart& CSamplePart::operator=(const CSamplePart& rhs) {
	CSamplePart tmp(rhs);

	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
}
CSamplePart& CSamplePart::operator=(CSamplePart&& rhs)noexcept {
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;

	return *this;
}
class CSamplePartTest {
public:
	CSamplePart C;
	CSamplePartTest() {
	};
	CSamplePartTest(const CSamplePart&cc) {
		C = cc;
	}
};
int main() {
	CSamplePart c1,c2;
	c1.Add(2);
	c1.Add(3);
	c1.Add(4);
	c1.Display();
	c2 = c1;
	c2.Display();
	CSamplePartTest *cc1 = new CSamplePartTest(c1);
	cc1->C.Display();
}