#include <iostream>
using namespace std;
struct date
{
    int year,month,day;
}d1;

int read(struct date *s1)
{
    cout<<"Enter year:";
    cin>>(*s1).year;
    cout<<"Enter month:";
    cin>>(*s1).month;
    cout<<"Enter day:";
    cin>>s1->day;

    return 0;
}

int show(struct date s1)
{
    cout<<"The date you entered is:"<<endl;
    cout<<s1.month<<"/"<<s1.day<<"/"<<s1.year;
}
int main()
{
    read(&d1);
    show(d1);

    return 0;
}
