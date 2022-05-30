#include<iostream>
#include<string>
using namespace std;
static double sales_money;
class Person{
protected:
    int id;
    string name;
    double wages;
    int time;
public:
    Person();
    Person(int id,string name,int time){
        this->id = id;
        this->name = name;
     //   this->wages = wages;
        this->time = time;
    }

    double getSalesMoney() const {
        return sales_money;
    }

    void setSalesMoney(double salesMoney) {
        sales_money = salesMoney;
    }

    virtual void show() = 0;
    virtual void cal_wages() =0;
};

class manager :public Person{
public:
    manager() :Person(){

    };
    manager(int id,string name,int time) : Person(id,name,time)
    {

    }
    virtual void show()
    {
        cout<<"id:"<<id<<"name:"<<name<<"wages:"<<wages<<"time:"<<time<<" "<<endl;
    }
    virtual void cal_wages()
    {
        this->wages = 8000;
    }
};
class salesman :public Person{
public:
    salesman() :Person(){

    };
    salesman(int id,string name,int time) : Person(id,name,time)
    {

    }
    virtual void show()
    {
        cout<<"id:"<<id<<"name:"<<name<<"wages:"<<wages<<"time:"<<time<<" "<<endl;
    }
    virtual void cal_wages()
    {
        this->wages = 0.04 * sales_money;
    }
};
class technician :public Person{
public:
    technician() :Person(){

    };
    technician(int id,string name,int time) : Person(id,name,time)
    {

    }
    virtual void show()
    {
        cout<<"id:"<<id<<"name:"<<name<<"wages:"<<wages<<"time:"<<time<<" "<<endl;
    }
    virtual void cal_wages()
    {
        this->wages = 100 * this->time;
    }
};

class salesmanager :public Person{
public:
    salesmanager() :Person(){

    };
    salesmanager(int id,string name,int time) : Person(id,name,time)
    {

    }
    virtual void show()
    {
        cout<<"id:"<<id<<"name:"<<name<<"wages:"<<wages<<"time:"<<time<<" "<<endl;
    }
    virtual void cal_wages()
    {
        this->wages = 5000 + 0.005*sales_money;
    }

    void setSalesMoney(double salesMoney) {
        sales_money = salesMoney;
    }

};

int main(){
    manager *p1 = new manager(1,"manager",10);
    salesman *p2 = new salesman(2,"manager",10);
    technician *p3 = new technician(3,"manager",10);
    salesmanager *p4 = new salesmanager(4,"manager",10);
    p4->setSalesMoney(10000);
    p1->cal_wages();
    p2->cal_wages();
    p3->cal_wages();
    p4->cal_wages();
    p1->show();
    p2->show();
    p3->show();
    p4->show();
}