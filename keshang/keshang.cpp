#include<iostream>
#include<string>
#include<vector>
using namespace std;

class HDUPerson{
protected:
    string name;
    char sex;
    int age;
public:
    HDUPerson(string name, char sex, int age) : name(name), sex(sex), age(age) {}
    const string getName() const {
        return name;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        HDUPerson::sex = sex;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        HDUPerson::age = age;
    }
    void IntroduceSelf(){
        cout<<name<<" "<<sex<<" "<<age<<" "<<endl;
    }
    virtual void GetCurrentNum() = 0;
};

class Student:public HDUPerson{
protected:
    int class_num;
public:
    Student(string name, char sex, int age,int class_num) : HDUPerson(name,sex,age),class_num(class_num){}

    void GetCurrentNum() {
        cout<<"class_num:"<<class_num<<endl;
    }

    void IntroduceSelf(){
        cout<<"Student"<<" "<<name<<" "<<sex<<" "<<age<<" "<<endl;
    }
};
class Teacher:public HDUPerson{
protected:
    int class_num;
public:
    Teacher(string name, char sex, int age,int class_num) : HDUPerson(name,sex,age),class_num(class_num){}

    void GetCurrentNum() {
        cout<<"class_num:"<<class_num<<endl;
    }

    void IntroduceSelf(){
        cout<<"Teacher"<<" "<<name<<" "<<sex<<" "<<age<<" "<<endl;
    }
};

int main()
{
    Student *p1 = new Student("Tom",'n', 18,6);
    Teacher *p2 = new Teacher("Mary",'m', 31,8);
    p1->IntroduceSelf();
    p2->IntroduceSelf();
    p1->GetCurrentNum();
    p2->GetCurrentNum();
    delete p1;
    delete p2;
}