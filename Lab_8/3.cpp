#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float imag;
public:
    Complex(float rl=0,float im=0)
    {
        real= rl;
        imag =im;
    }
    friend ostream& operator<<(ostream& o,Complex c);
    friend istream& operator>>(istream& i,Complex& c);

};
ostream& operator<<(ostream& o,Complex c)
{
    o<<c.real<<" + "<<c.imag<<"i ";
    return o;
}
istream& operator>>(istream& i,Complex& r)
{
    i>>r.real;
    i>>r.imag;

}
int main()
{
        Complex c1(1,5),c2;
        //cin>>c1;        //1 and 5 get overridden
        cout<<"Enter Real and Imaginary Parts: ";
        cin>>c2;
        cout<<c1<<endl;
        cout<<c2;
}

