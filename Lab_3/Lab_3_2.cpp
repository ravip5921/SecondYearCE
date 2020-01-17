#include <iostream>
#include <cstdlib>

using namespace std;

class Prime
{
//private:
   //int a1;
public:
    int primen;
    void getnum()
    {
        cout<<"Enter a number: ";
        cin>>primen;
        //a1=primen;
    }
    void isPrime(int a)
    {
        if(a!=1)
        {
        int res=0;
        for(int i=2;i<a;i++)
        {
            if(a%i==0)
            {
                res++;
            }
        }
        if(res==0)
            cout<<"Prime"<<endl;
        else
            cout<<"Not Prime"<<endl;
        }
        else
            cout<<"1 is inconclusive.";
        }
};

int main()
{
    Prime p1;
    char op ='y';
    while(op=='y')
    {
        p1.getnum();
        p1.isPrime(p1.primen);
        //p1.isPrime(p1.a1);
        cout<<"\nWanna Continue?[y,n]";
        cin>>op;
        system("cls");
    }
    return 0;
}
