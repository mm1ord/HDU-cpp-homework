#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Shape{
public:
    virtual double GetArea()const = 0;
    virtual void Show() = 0;
    void Input();
};

class Rectangle: public Shape{
protected:
    double length;
    double width;
public:
    Rectangle();
    Rectangle(double length,double width):length(length),width(width){

    }
    virtual double GetArea() const{
        return length*width;
    }
    void Input(double length, double width){
        this->length = length;
        this->width = width;
    }
    virtual void Show(){
        cout<<"Rectangle "<<"长length:"<<length<<"宽width:"<<width<<endl;
    }
};
class Cube: public Rectangle{
protected:
    double height;
public:
    Cube();
    Cube(double length,double width,double height):Rectangle(length,width),height(height){

    }
    virtual double GetArea() const{
        return (length*height+length*width+height*width)*2;
    }
    void Input(double length, double width,double height){
        this->length = length;
        this->width = width;
        this->height = height;
    }
    virtual void Show(){
        cout<<"Cube "<<"长length:"<<length<<"宽width:"<<width<<"高height:"<<height<<endl;
    }
};
int main()
{
    vector<Shape*>vecShapes;
    string strShape;
    double sum_area=0;
    while(cin>>strShape)
    {
        if(strShape == "rectangle")
        {
            double length,width;
            cin>>length>>width;
            vecShapes.push_back(new Rectangle(length,width));
        }
        else if(strShape == "cube")
        {
            double length,width,height;
            cin>>length>>width>>height;
            vecShapes.push_back(new Cube(length,width,height));
        }
        else if(strShape == "stop")
        {
            break;
        }
    }
    for(unsigned int i=0;i<vecShapes.size();i++)
    {
        vecShapes[i]->Show();
        sum_area+=vecShapes[i]->GetArea();
    }
    cout<<"总面积为:"<<sum_area<<endl;
    for(unsigned int i=0;i<vecShapes.size();i++)
    {
        delete vecShapes[i];
    }
}