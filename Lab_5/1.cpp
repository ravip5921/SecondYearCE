#include <iostream>
using namespace std;
class co {
private:
   float x,y;
public:
   co(float a=0,float b=0)
   {
       x=a;
       y=b;
   }
    co operator-(co a);
   // {                         //member function to overload -
    //    return(co(x-a.x,y-a.y));
    //}
    friend co operator+(co a, co b);//non -member function to overload +
    //{
      //  return(co(a.x+b.x,a.y+b.y));
    //}
    friend class work;
};
co operator+(co a, co b)
    {
        return(co(a.x+b.x,a.y+b.y));
    }
co co::operator-(co a)
    {
        return(co(x-a.x,y-a.y));
    }
class work {
public:
    co add(co a,co b)
    {
        return(co(a.x+b.x,a.y+b.y));
    }

   void show(co a)
   {
       cout<<a.x<<","<<a.y<<endl;
   }
};
int main() {
   co o1(1,2),o2(3,4);
   work obj2;
   obj2.show(obj2.add(o1,o2));
   co a;
   a=o1-o2;
   obj2.show(a);
   a=o1+o2;
   obj2.show(a);
   return 0;
}
