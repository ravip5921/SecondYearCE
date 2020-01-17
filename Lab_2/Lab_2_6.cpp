//use of default arguments.c

#include <iostream>

void displaySal(float sal=10000, float inc=12)
{
    float finalSal;
    finalSal = (1+(inc)/100)*sal;
    std::cout<<"Final Salary is:"<<finalSal<<std::endl;
    std::cout<<std::endl;
}
int main()
{
    char pname[30];
    float sal,inc;
    for(int i=1;i<=4;i++)
    {


        std::cout<<"Enter the post name";
        std::cin>>pname;
        std::cout<<"Enter salary in year 2019";
        std::cin>>sal;
        std::cout<<"Enter increment in %";
        std::cin>>inc;
        displaySal(sal, inc);
    }
}
