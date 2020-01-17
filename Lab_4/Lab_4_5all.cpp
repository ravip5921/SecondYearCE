#include<iostream>

class Test
{
private:
    int num;
public:
    Test(int n = 0)
    {
        num = n;
    }

 /*   void getNum()
    {
        cout<<"\nObject num"<<num;
    }
    */
    void constFunct() const
    {
        std::cout<<"\n\nThis doesnot modify object. Object no: "<<num;
    }

    void nonConstFunct()
    {
        num++;
        std::cout<<"\nThis changed object no to "<<num;
    }
};

int main()
{
    const Test t1;
    Test t2;

    //t1.nonConstFunct();  //error: passing 'const Test' as 'this' argument discards qualifiers [-fpermissive]
    t1.constFunct();

    t2.constFunct();
    t2.nonConstFunct();
}

