//abstract class
#include<iostream>
using namespace std;

class student
{
protected:
  char* name;
  int age;
  float marks;
  char field;
public:
  void setData()
  {
    name= new char[20];
    cout << "Enter name:";
    cin >> name;
    cout << "Enter age:";
    cin >> age;
    cout << "Enter marks:";
    cin >> marks;
    cout<<"\n";
  }
//pure virtial function
  virtual void display()=0;

  ~student()
  {
    delete[]name;
  }
};
class engineering:public student
{
public:
  void setData()
  {
    student::setData();

  }
  void display()
  {
    field ='E';
    cout << "\nName:" <<name<<"\nAge:"<<age<<"\nMarks:"<<marks<<"\nField:"<<field<<endl;
  }
};

class medicine:public student
{
public:
  void setData()
  {
    student::setData();

  }
  void display()
  {
    field ='M';
    cout << "\nName:" <<name<<"\nAge:"<<age<<"\nMarks:"<<marks<<"\nField:"<<field<<endl;
  }
};

class science:public student
{
public:
  void setData()
  {
    student::setData();

  }
  void display()
  {
    field='S';
    cout << "\nName:" <<name<<"\nAge:"<<age<<"\nMarks:"<<marks<<"\nField:"<<field<<endl;
  }
};

int main()
{
//create derived class objects
  engineering e;
  medicine m;
  science s;
//base class pointer array
  student *ptr[3];
//assign pointer to derived objects
  ptr[0]=&e;
  ptr[1]=&m;
  ptr[2]=&s;
//set values
  ptr[0]->setData();
  ptr[1]->setData();
  ptr[2]->setData();
//show values
  ptr[0]->display();
  ptr[1]->display();
  ptr[2]->display();

  return 0;
}
