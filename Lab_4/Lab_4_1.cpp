//Use of default and parameterized Constructors
#include <iostream>
using namespace std;
class Time {
private:
    int hour, minu, sec;
public:
    Time()
    {
        cout<<"Default constructor is used!";
        hour = 0;
        minu = 0;
        sec = 0;
    }
    Time(int hr, int mi, int se)
    {
        hour = hr;
        minu = mi;
        sec = se;
    }
    Time addTime(Time t1)
    {
        t1.sec += sec;
        t1.minu+=minu;
        t1.hour +=hour;
        if(t1.sec>=60)
        {
            t1.sec=t1.sec-60;
            t1.minu++;
        }
        if(t1.minu>=60)
        {
            t1.minu=t1.minu-60;
            t1.hour++;
        }
        return t1;
    }
    void showtime()
    {
        cout << hour<<"-"<<minu<<"-"<< sec<< endl;
    }
};
int main()
{
    int hr,mi,se;
    cout<<"Enter time t1:(Hours<enter>minutes<enter>seconds)\n ";
    cin>>hr>>mi>>se;
    Time t2(hr,mi,se);
    cout<<"Enter time t2:(Hours<enter>minutes<enter>seconds)\n ";
    cin>>hr>>mi>>se;
    Time t3(hr,mi,se);
    Time t1;
    t1.showtime();
    t2.showtime();
    t3.showtime();
    Time t4;
    //t4.showtime();
    t4=t2.addTime(t3);
    cout<<"\nAdded Time is:\n";
    t4.showtime();
    return 0;
}
