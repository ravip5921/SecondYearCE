#include <iostream>

using namespace std;

class statdem
{
private:
    static int cou;
    int objNum;
    char *name;
public:
    statdem()
    {
        cou++;
        cout<<"\n\tObject "<<cou<<" has been created!\n";
        objNum=cou;
    }
    /*statdem(char* nam)
    {
     cou++;
     for(int i=0;*(nam+i)!='\0';i++)
     {
         *(name+i)=*(nam+i);
         *(name+i+1)='\0';
     }
     objNum = cou;
       cout<<"\n\tObject "<<cou<<" has been created!\n"// with name"<<name<<"\n";
    }*/
    void showobjnum()
    {
        //cout<<"\n"<<cou<<" Objects exist at this moment.\n";
        cout<<"This is object no. "<<objNum<<endl;
    }
    static void TotObjs()
    {
        cout<<cou<<" objects exists at this moment.\n";
    }
    ~statdem()
    {
        cout<<"\n\tObject "<<cou<<" has been deleted.\n";
        cou--;
    }
};
int statdem::cou;
int main()
{
    statdem s1,s2,s3,s4;
    s1.showobjnum();
    statdem::TotObjs();
}
