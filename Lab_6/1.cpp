#include <iostream>

using namespace std;
class Dist
{
    private:
    int meter;
    float centimeter;

    public:
    Dist(int a=0,int b=0)
    {
        meter = a;
        centimeter = b;
    }               //a= static_cast<float<(b); == a = (float) b;
    Dist(float a)
    {
        meter = static_cast<int>(a);
        centimeter = (a-meter)*100;
    }
     operator float()
    {
        return(meter+(static_cast<float>(centimeter))/100);
    }
    show()
    {
        cout<<"\n"<<meter<<" meter "<<centimeter<<" cm";
    }
};
int main()
{
    int m,cm;
    cout<<"Enter Meters";
    cin>>m;
    cout<<"Enter Centimeters";
    cin>>cm;
    Dist d1(m,cm);
    float b=d1;
    cout<<b<<" meters "<<endl;
    Dist d2;
    d2=b;
    d2.show();
}
