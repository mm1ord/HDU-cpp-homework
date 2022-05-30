#include<iostream>
using namespace std;

class CSet
{
public:
	CSet();									//构造函数
	~CSet();								//析构函数，释放链表
	CSet(const CSet&);						//拷贝构造函数
	CSet(CSet&&) noexcept;					//移动构造函数
	bool Remove(int x);						//删除元素x
	bool In(int x);							//是否包含元素x
	CSet& operator = (const CSet& rhs);		//复制赋值
	CSet& operator = (CSet&& rhs)noexcept;	//移动赋值
	bool Add(int x);						//增加元素 
	void Display();							//显示集合
	CSet Join(const CSet& rhs)const;		//结果为A、B交集                                                                                                                                                            集
	CSet Union(const CSet& rhs)const;       //结果为A、B并集
	CSet Differ(const CSet& rhs)const;		//结果为差集
	void Delete(int num);					//删除某一元素
private:
	struct Node {
		int data;
		Node* next;
	}* m_pHead;			//集合采用递增排序单链表表示
};

CSet::CSet() {
	m_pHead = new Node;
	m_pHead->next = NULL;
}
CSet::~CSet() {
	while (m_pHead) {
		Node* p = m_pHead;
		m_pHead = p->next;
		delete p;
	}
}
bool CSet::Add(int x) {
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
void CSet::Display() {
	Node* p = m_pHead->next;
	cout << "{";
	while (p) {
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;
}
CSet CSet::Join(const CSet& rhs) const {
	CSet result;
	Node* last = result.m_pHead;
	Node* p = m_pHead->next;
	Node* q = rhs.m_pHead->next;
	while (p && q) {
		if (p->data == q->data) {
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;
			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data)
		{
			p = p->next;
		}
		else {
			q = q->next;
		}
	}
	last->next = NULL;
	return result;
}
CSet CSet::Union(const CSet&rhs)const {
	CSet result;
	Node* last = result.m_pHead;
	Node* p = m_pHead->next;
	Node* q = rhs.m_pHead->next;
	while (p && q) {
		if (p->data == q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;
			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data) {
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;
			p = p->next;
		}
		else {
			Node* s = new Node;
			s->data = q->data;
			last->next = s;
			last = s;
			q = q->next;
		}
	}
	while (p) {
		Node* s = new Node;
		s->data = p->data;
		last->next = s;
		last = s;
		p = p->next;
	}
	while (q) {
		Node* s = new Node;
		s->data = q->data;
		last->next = s;
		last = s;
		q = q->next;
	}
	last->next = NULL;
	return result;
}
CSet CSet::Differ(const CSet& rhs)const {
	CSet result;
	Node* last = result.m_pHead;
	Node* p = m_pHead->next;
	Node* q = rhs.m_pHead->next;
	while (p && q) {
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;
			p = p->next;
		}
		else {
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;
			q = q->next;
		}
	}
	last->next = NULL;
	return result;
}
void CSet::Delete(int num) {
	Node* s = new Node;
	s = this->m_pHead;
	int k=0;
	while (s->next)
	{
		if (s->next->data == num)
		{
			s->next = s->next->next;
			k+=1;
		}
		s = s->next;
	}
	if (k == 0)
	{
		cout << "没有该元素，发生错误";
		exit(0);
	}
}
bool CSet::In(int x) {
	Node* p = m_pHead;
	while(p->next && (p->next->data < x))
	{
		p = p->next;
	}
	if (p->next && p->next->data == x)
	{
		return true;
	}
	return false;
}

CSet::CSet(const CSet& rhs) {
	m_pHead = new Node;
	Node* last = m_pHead;
	Node* p = rhs.m_pHead->next;
	while (p) {
		Node* q = new Node;
		q->data = p->data;
		last->next = q;
		last = q;
		p = p->next;
	}
	last->next = NULL;
}
CSet::CSet(CSet&& rhs) noexcept {
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}
CSet& CSet::operator=(const CSet& rhs){
	CSet tmp(rhs);
	
	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;

	return *this;
}
CSet& CSet::operator=(CSet&& rhs)noexcept {
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;

	return *this;
}

int main() {
	CSet A, B, S, S2, S3;
	int i, m, n, x;
	cin >> m >> n;
	for (i = 0; i < m; i++)
	{
		cin >> x;
		A.Add(x);
	}
	for (i = 0; i < n; i++)
	{
		cin >> x;
		B.Add(x);
	}
	A.Display();
	B.Display();
	S = A.Join(B);
	S.Display();
	S2 = A.Union(B);
	S2.Display();
	S3 = A.Differ(B);
	S3.Display();
	A.Delete(1);
	A.Display();
}













