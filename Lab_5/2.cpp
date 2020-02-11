#include<iostream>

using namespace std;

class Coord

{
private:
    float x,y,z;
public:
    Coord()
    {
        x=0;
        y=0;
        z=0;
    }
    Coord(float xx, float yy, float zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }

    friend Coord operator+(Coord c1, Coord c2)      //friend functs are "not member functs" class_name.func_name isn't used only
    {                                               //funct_name to call
        return Coord(c1.x+c2.x,c1.y+c2.y,c1.z+c2.z);
    }

    friend Coord operator-(Coord c1, Coord c2)
    {
        return Coord(c1.x-c2.x,c1.y-c2.y,c1.z-c2.z);
    }
    friend void show(Coord c)
    {
        cout<<"("<<c.x<<","<<c.y<<","<<c.z<<")"<<endl;
    }
};
//friend void op(Coord c1, Coord c2)

int main()
{
    Coord c1(2,3,4),c2(4,3,4);
    Coord c3;
    c3 =c1+c2;
    show(c3);
    show(c1-c2);
}

