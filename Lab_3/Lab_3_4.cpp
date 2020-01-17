#include <iostream>
#include <cmath>
#include<cstdlib>

using namespace std;

class Triangle
{
private:
   float s1,s2,s3;
public:
    float s;
    int setsides()
    {
        cout<<"Enter the sides of the triangle";
        cin>>s1;
        cin>>s2;
        cin>>s3;
        s=(s1+s2+s3)*0.5;
        if(s<=s1 || s<=s2 || s<=s3)
       {
           cout<<"Invalid dimensions for a triangle!!!\n";
           return 0;
       }
       else
        return 1;
    }
    float peri()
    {
        return s1+s2+s3;
    }
    float area()
    {
        return sqrt(s*(s-s1)*(s-s2)*(s-s3));
    }
};
class Circle
{
private:
    float radius;
    const float pi=3.14;
public:
    void set_radius()
    {
        cout<<"Enter the radius of the circle: ";
        cin>>radius;
    }
    float circumference()
    {
        return 2.0*pi*radius;
    }
    float area()
        {
            return pi*radius*radius;
        }
};
class Rectangle
{
private:
    float length,breadth;
public:
    void set_dimensions()
    {
        cout<<"Enter the length and breadth of the rectangle: ";
        cin>>length;
        cin>>breadth;
    }
    float peri()
    {
        return 2.0*(length+breadth);
    }
    float area()
    {
        return length*breadth;
    }
};
int main()
{
    Triangle t;
    Circle c;
    Rectangle r;
    int choice,a;
    char option;
    do{
    cout<<"Select the shape you want to evaluate:";
    cout<<"\n1)Triangle\n2)Circle\n3)Rectangle\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        a=t.setsides();
        if(a!=0)
            cout<<"Perimeter = "<<t.peri()<<"\nArea = "<<t.area()<<endl;
        break;
    case 2:
        c.set_radius();
        cout<<"Circumference = "<<c.circumference()<<"\nArea = "<<c.area()<<endl;
        break;
    case 3:
        r.set_dimensions();
        cout<<"Perimeter = "<<r.peri()<<"\nArea = "<<r.area()<<endl;
        break;
    default:
        cout<<"Sorry!Shape not Available\n";
        break;
    }
    cout<<"More?[Y,N]";
    cin>>option;
    system("cls");
}while(option=='Y' || option=='y');
return 0;
}
