//Use of default and parameterized Constructors
#include <iostream>
#include <cstring>
using namespace std;

class Dynam
{
private:
    char *name;

    //int *a1;
    //string a;
public:
    Dynam()
    {
    }
    Dynam(char na[4])
    {
      //  a1= new int;
      //  *a1=5;
        int n;
        n=strlen(na);
        cout<<n;
        name = new char [n];
        name = na;
      //  name[6] ='j';//na;
    }
     char* join(Dynam ob1, Dynam ob2)
    {
        char* finalStr;
        //cout<<ob1.name[0];
        int c1=0,c2=0;//c3=0;
        while(ob1.name[c1]!='\0')       //Determines length of strings without using library function.
        {
            cout<<"a";
            c1++;
        }
        while(ob2.name[c2]!='\0')
        {
            c2++;
        }
        //c3=c1+c2;
     /*   for(int i=0;i<(c1+c2);i++)
        {
            if(i<=c1)
            {
                finalStr[i]=ob1.name[i];
            }
            else{
                finalStr[i]=ob2.name[i-c1];
            }
        }*/
        return finalStr;
    }
    void show()
    {
        //cout<<*a1<<name[6];
        cout<<name<<endl;
    }
};


int main()
{
    Dynam d1("Engineers are");
    Dynam d2("Creatures of logic");
    Dynam d3;
    cout<<d2.join(d1,d2)<<endl;
    d1.show();d2.show();//d3.show();
    return 0;
}
