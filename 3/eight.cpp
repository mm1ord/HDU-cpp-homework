#include <iostream>
using namespace std;
#define Maxsize 1000
class Queue {
private:
    int data[Maxsize];
    int first, rear;
public:
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
    this->first = this->rear = 0;
}
bool Queue::empty() {
    if (this->first == this->rear)
    {
        return true;
    }
    else
        return false;
}
void Queue::push(int x) {
    if ((this->rear + 1) % Maxsize == this->first)
    {
        throw"队列已满";
    }
    else {
        data[this->rear] = x;
        this->rear = (this->rear + 1) % Maxsize;
    }
}
void Queue::pop() {
    if (this->rear == this->first)
    {
        throw"队列已空";
    }
    else {
        this->first = (this->first + 1) % Maxsize;
    }
}
int Queue::size() {
    return (this->rear - this->first + Maxsize) % Maxsize;
}
int Queue::front() {
    if (this->rear == this->first)
    {
        throw"队列已空，异常";
    }
    else {
        return data[first];
    }
}
int Queue::back() {
    if (this->rear == this->first)
    { 
        throw"队列已空，异常";
    }
    else {
        return data[this->rear-1];
    }
}
int main()
{
    Queue *q = new Queue();
    q->push(5);
    q->push(6);
    cout << q->size();
    return 0;
}
