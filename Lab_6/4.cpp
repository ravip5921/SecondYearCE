#include <iostream>

using namespace std;

class Person
{
protected:
    const char* obj_name;
    char name[20];
    int age;
public:
    Person( const char * nm)
    {
        obj_name=nm;
    }
    void getinfo()
    {
        cout<<"Name=";
        cin>>name;
        cout<<"Age=";
        cin>>age;
    }
    void showinfo()
    {
        cout<<"Name = "<<name<<endl<<"Age ="<<age<<endl;
    }
    void id()
    {
        cout<<obj_name<<"'s address="<<this<<endl;
    }
};
class Student:public Person
{

private:
    const char* obj_name;
    char degree[20];
public:
    Student(const char* nms,const char*nmp):Person(nmp)
        {
            obj_name=nms;
        }

    void getinfo()
    {
        Person::getinfo();
        cout<<"Degree=";
        cin>>degree;
    }
    void showinfo()
    {
        Person::showinfo();
        cout<<"Degree of "<<Person::name<<" is "<<degree<<endl;

    }
    void id()       //overwrites base's id()
    {
        cout<<obj_name<<"'s address="<<this<<endl;
    }


};

class Employee:public Person
{
private:
    const char* obj_name;
    char post[20];
public:
    Employee(const char* nme,const char* nmp):Person(nmp)
    {
        obj_name=nme;
    }
    void getinfo()
    {
        Person::getinfo();
        cout<<"Post=";
        cin>>post;
    }
    void showinfo()
    {
        Person::showinfo();
        cout<<"Post of "<<Person::name<< " is "<<post<<endl;
    }
    void id()
    {
        cout<<obj_name<<"'s address="<<this<<endl;
    }
};
int main()
{
    Person p1("Base1"),p2("Base2");
    Student s1("s1","p1"),s2("s2","p2");
    Employee e1("e1","p3"),e2("e2","p4");

    s1.getinfo();
    s2.getinfo();
    e1.getinfo();
    e2.getinfo();

    s1.showinfo();
    s2.showinfo();
    e1.showinfo();
    e2.showinfo();

    p1.id();
    p2.id();
    s1.id();
    s2.id();
    e1.id();
    e2.id();
}
