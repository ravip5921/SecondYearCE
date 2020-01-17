#include <iostream>

using namespace std;

class DepartInfo
{
public:
    int id;
    char* name;
public:
    DepartInfo()
    {
        id=0;
        name =new char[30];
        for(int i=0;i<29;i++)
            *(name+i)=' ';
        *(name+30)='\0';
    }
    DepartInfo(int ide,const char* nam='\0')
    {
        int len;
        id =ide;
        name = new char[50];
        for(int i=0;*(nam+i)!='\0';i++)
        {
          // len = i;
            *(name+i)=*(nam+i);
           *(name+i+1)='\0';
        }
        //len++;
        /* for(int i=0;i<len;i++)
        {
            *(name+i)=*(nam+i);
           *(name+i+1)='\0';
        }*/
        cout<<"Records of "<<name<< " are being saved.\n";
    }
    ~DepartInfo()
    {
        delete[] name;
        //cout<<"Records of "<<name<<" are being deleted.\n";
        cout<<"Object "<<id<<" goes out of scope.\n";
    }
    void show()
    {
    cout<<id<<"\t"<<name<<endl;
    }
};
int main()
{
    char n;
    DepartInfo d1(1,"Ravi"),d2(2,"A name"),d3(3,"Another Name");
    d1.show();
    d2.show();
    d3.show();
    cin>>n;
}
