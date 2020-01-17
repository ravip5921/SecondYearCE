//Shows use of return by reference
#include <iostream>

using namespace std;
float& maxtempishun(float* t1, float* t2);
int main()
{
    float t1, t2, max_temp;
    cout <<"Enter two temperatures";
    cin>>t1;
    cin>>t2;
    maxtempishun(&t1, &t2) = 100;   //*mastempishun if if is used
    cout<< "t1="<<t1<<"t2="<<t2;
    return 0;
}
float& maxtempishun(float* t1,float* t2)
{
   return (*t1>*t2)? *t1:*t2;
}
//use if and float * maxtempishun
