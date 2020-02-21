#include<iostream>
using namespace std;
class shape{
public:
  shape()
  {
    cout << "Base Constructor\n";
  }
  virtual void area()
  {
    cout << "Base Area function\n";
  }
  virtual void display()
  {
    cout << "Base display function";
  }

  virtual ~shape()
  {
   cout << "Base Destructor\n";
  }

};

class circle:public shape
{
private:
float radius;
float areaC;

public:
  circle(float r=0)
  {
    radius=r;
  }
  void area()
  {
    areaC=3.1415*radius*radius;
  }
  void display()
  {
    cout << "Area of circle is " <<areaC <<endl;
  }
  ~circle()
  {
    cout << "\nCircle Destructor " <<endl;
  }
};

class rectangle:public shape
{
private:
float length;
float  breadth;
float  areaR;

public:
  rectangle(float l=0,float b=0)
  {
    length=l;
    breadth=b;
  }
  void area()
  {
    areaR=length*breadth;
  }
  void display()
  {
    cout << "Area of rectangle is "<<areaR<<endl;
  }
  ~rectangle()
  {
    cout << "\nRectangle Destructor" <<endl;
  }
};

class trapezoid:public shape{

float longBase;
float shortBase;
float altitude;
float areaT;
public:

  trapezoid(int a=0,int b=0,float h=0)
  {
    longBase=a;
    shortBase=b;
    altitude=h;
  }
  void area()
  {
    areaT=((longBase+shortBase)/2)*altitude;
  }
  void display()
  {
    cout << "Area of trapezoid is "<<areaT <<endl;
  }
  ~trapezoid()
  {
    cout << "\nTrapezoid Destructor" <<endl;
  }
};


int main() {
//pointer of base class(i.e. shape class)
  shape* ptr;

//circle class
  circle c(1.5);
  ptr =&c;
  ptr->area();
  ptr->display();

//rectangle class
  rectangle r(2.5,4);
  ptr=&r;
  ptr->area();
  ptr->display();

//trapezoid class
  trapezoid t(2,4,2.5);
  ptr=&t;
  ptr->area();
  ptr->display();

  return 0;
}
