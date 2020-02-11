#include<iostream>
///*
class Date
{
private:
    int day,month,year;
public:
    Date(int dd=0,int mm=0,int yy=0)
    {
        day = dd;
        month = mm;
        year = yy;
    }
    /*
    friend Date operator++( Date d1)
    {
    Date d;
    d.day = d1.day+1;
    d.month = d1.month+1;
    d.year = d1.year+1;
    if(d.day>30)
    {
        d.day=d.day-30;
        d.month++;
        if(d.month>12)
        {
            d.month=d.month-12;
            d.year++;
        }
    }
    if(d.month>12)
        {
            d.month=d.month-12;
            d.year++;
        }
    return d;
}
    friend int operator++(int )Date d1)
    {
        std:cout<<"Hi:";
        return 0;
    }
    */



    Date & operator++()//Date d1)
    {
        day++;
       // month++;
       // year++;
        if(day>30)
        {
            day=day-30;
            month++;
            if(month>12)
            {
                month=month-12;
                year++;
            }
        }
        if(month>12)
            {
                month=month-12;
                year++;
            }
        return *this;
    }


    Date operator++(int)
    {
        Date temp=*this;
        ++*this;
        return *this;
    }
    friend showDate(Date d)
    {
        std::cout<<d.day<<"-"<<d.month<<"-"<<d.year<<std::endl;
    }
};

int main()
{
    Date a(28,1,1);
    showDate(a);
    Date b(2,3,2);
    b=a++;
    showDate(b);
    showDate(b++);
    showDate(++a);
    b=++a;
    Date c=a++;
    showDate(c);
    showDate(a);
    showDate(b);
    showDate(b++);
                                    /*
                                        int a=0;
                                        int b=a++;
                                        int c=++a;
                                        a=0;
                                        int d=++a;
                                        std::cout<<b<<std::endl<<c<<std::endl<<d;
                                    */
}
