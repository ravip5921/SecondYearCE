#include<iostream>

using namespace std;

class String
{
private:
    int len;
    char * str;
public:
    String (const char *s ='\0')
    {
        for(int i=0;*(s+i)!='\0';i++)
        {
            len = i;
        }
        len++;
        str = new char[50];
        for(int i=0;i<len;i++)
        {
        *(str+i) = *(s+i);
        }
       *(str+len) = '\0';
    }
     void display()
     {
         cout<<"\n"<<str<<"\n";
     }

     void concatenate(String s2)
     {
         *(str+len)=' ';
         for(int i=0;i<=s2.len;i++)
         {
             *(str+len+i+1) = *((s2.str)+i);
         }
         *(str+len+s2.len+1) = '\0';
     }

     ~String()
     {
         delete[] str;
     }
};

int main()
{
    String s1("Engineers are");
    s1.display();

    String s2("creatures of logic");
    s2.display();

    s1.concatenate(s2);
    s1.display();
}
