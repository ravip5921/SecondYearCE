#include <iostream>
using namespace std;
class BaseComp
{
protected:
    float real;
    float imag;
public:
    BaseComp(float a=0, float b=0)
    {
        real =a;
        imag =b;
    }
};
class DerB;
class DerA:public BaseComp
{
private:
    float real;
    float imag;
public:
    DerA(float r=0,float i=0,float br=0,float bi=0):BaseComp(br,bi)
    {
        real=r;
        imag=i;
    }
    void addWithBase()
    {
        real+=BaseComp::real;
        imag+=BaseComp::imag;
    }
    void show()
    {
        cout<<real<<" + ";
        cout<<imag<<"i\n";
    }
    friend class DerB;
};
class DerB:public BaseComp
{
public:
    DerB(float r,float i):BaseComp(r,i)
    {
    }
    void diff(DerA com1)
    {
        real-=com1.real;
        imag-=com1.imag;
    }
    void show()
    {
        cout<<real<<" + ";
        cout<<imag<<"i\n";
    }
};
int main()
{
    DerA a(5,7,8,9);
    DerB b(20,20);
    a.addWithBase();
    a.show();
    b.diff(a);
    b.show();
    return 0;
}
