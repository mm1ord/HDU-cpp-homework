#include<iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode* next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    ListNode* head;
    ListNode* tail;
    int Size;
    //构造函数，对队列进行初始化
    Queue();
    //判断队列是否为空
    bool empty();
    //入队列操作
    void push(int x);
    //出队列操作
    void pop();
    //返回队列的长度
    int size();
    //返回队首元素
    int front();
    //返回队尾元素
    int back();
};
Queue::Queue() {
    this->head = NULL;
    this->tail = NULL;
    Size = 0;
}
bool Queue::empty() {
    if (this->head == this->tail)
    {
        return true;
    }
    else {
        return false;
    }
}
void Queue::push(int x) {
    ListNode* temp = new ListNode(x);
    if (this->head == NULL)
    {
        this->head = temp;
        this->tail = temp;
    }
    else {
        this->tail->next = temp;
    }
    this->tail = temp;
    this->Size++;
}
void Queue::pop() {
    if (this->head != NULL)
    {
        ListNode* p = this->head->next;
        delete this->head;
        this->head = p;
        this->Size--;
    }
    else {
        throw"链表为空不能删除";
    }
}
int Queue::size() {
    return Size;
}
int Queue::front() {
    if (this->head == this->tail) {
        throw"链表为空";
    }
    else {
        return this->head->data;
    }
       
}
int Queue::back() {
    if (this->head == this->tail) {
        throw"链表为空";
    }
    else {
        return this->tail->data;
    }
}
int main()
{
    Queue* q = new Queue();
    q->push(5);
    q->push(6);
    cout << q->size();

	return 0;
}