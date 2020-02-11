#include <iostream>

using namespace std;

class Metric;

class Eng
{
private:
    int feet;
    float inch;
public:
    Eng(int f=0, float i=0)
    {
        feet =f;
        inch =i;
    }
    Eng(Metric a );


    int ft()
    {
        return(feet);
    }
    float in()
    {
        return(inch);
    }

};

class Metric
{
private:
    int meter;
    float centimeter;
public:
    Metric(int a=0, float b= 0)
    {
        meter = a;
        centimeter = b;
    }
    Metric(Eng a)
    {
        int fe;
        float inc;
        fe=a.ft();
        inc=a.in();
        centimeter=inc*2.54;
        float dmeter = fe*(0.305);
        meter = static_cast<int>(dmeter);
        centimeter = centimeter+(dmeter-meter)*100;
        if (centimeter>=100)
        {
            meter++;
            centimeter=centimeter-100;
        }
    }
    int me()
    {
        return meter;
    }
    float cme()
    {
            return centimeter;
    }
    show()
    {
        cout<<meter<<" m "<<centimeter<<" cm "<<endl;
    }
};

Eng::Eng(Metric a)
    {
        int met;
        float dfet,cmet;
        met=a.me();
        cmet=a.cme();
        dfet = met*3.28084;
        inch=cmet*0.393701;
        feet = static_cast<int>(dfet);
        inch =inch + (dfet-feet)*12;
    }
int main()
{
    int a;
    float b;
    cout<<"Enter Meter and cm"; cin >>a>>b;
    Metric m(a,b);
    cout<<"Enter feet and inch"; cin >>a>>b;
    Eng e(a,b);
    Metric m1=e;
    m1.show();
    Metric m2(1,6);
    Eng e2=m2;
    Metric m3(e2);
    m3.show();

}
