//virtual base
#include<iostream>
using namespace std;
class person
{
protected:
  char* name;
  int age;
public:
  void setData()
  {
    name=new char[20];
    cout << "Enter name:";
    cin >> name;
    cout << "Enter age:";
    cin >> age;
  }
  void display()
  {
    cout << "Name:" <<name<<"\n"<<"Age:"<<age<<"\n";
  }
  virtual ~person()
  {
    delete []name;
  }
};

class employee:public virtual person
{
protected:
  int salary;
public:
  void setDataE()
  {
    cout << "Enter salary:";
    cin >> salary;
  }
  void displayE()
  {
    cout << "Salary:"<<salary <<endl;
  }
};

class student:public virtual person
{
protected:
  char grade;
public:
  void setDataS()
  {
    cout << "Enter grade:";
    cin >> grade;
  }
  void displayS()
  {
    cout << "Grade:"<<grade <<endl;
  }
};

class manager:public employee,public student{
protected:
  char* company;
public:
  void setData()
  {
    person::setData();
    employee::setDataE();
    student::setDataS();
    company= new char[20];
    cout << "Enter company:";
    cin >> company;
  }
  void display()
  {
    person::display();
    employee::displayE();
    student::displayS();
    cout << "Company:" <<company <<endl;
  }
  ~manager()
  {
    delete []company;
  }
};

int main()
{
  manager m;
  m.setData();
  m.display();
  return 0;
}
