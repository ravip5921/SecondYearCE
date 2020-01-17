#include <iostream>

using namespace std;

class Celsius
{
    private:
        float cel;
    public:
        void gettemp()
        {
            cout<<"Enter temp in Celsius";
            cin>>cel;
            //return c1;
        }
        void toFah()
        {
            float fa;
            fa = (1.8*cel)+32;
            cout<<"Temperature in Fahrenheit is:"<< fa<<endl;
        }
};
class Fahrenheit
{
private:
    float fah;
public:
    void gettempf()
        {
            cout<<"Enter temp in Fahrenheit"<<endl;
            cin>>fah;
            //return c1;
        }
    void toCel()
        {
            float ce;
           // cout <<fah;
            ce = ((fah-32)*float(5)/float(9));
            cout<<"Temperature in Celsius is:"<<ce<<endl;
        }
};
int main()
{
    char sel,exi;
    do{
    cout<<"Select conversion \n1)->Celsius to Fahrenheit \n2)->Fahrenheit to Celsius"<<endl;
    cin>>sel;
    if(sel=='1')
    {
        Celsius a;
        a.gettemp();
        a.toFah();
    }
    else if(sel=='2')
    {
        Fahrenheit b;
        b.gettempf();
        b.toCel();
    }
    else
    {
        cout<<"Invalid Selection"<<endl;
    }
    cout<<"Do you wish to continue?[Y,N]"<<endl;
    cin>>exi;
    }while(exi=='Y' || exi=='y');
    return 0;
}
