//namespaces
#include <iostream>

namespace square
{
    int num;
    int fun(int nums)
    {
        return nums*nums;
    }
};
namespace cube
{
    int num;
    int fun(int num1)
    {
        return num1*num1*num1;
    }
};
int main()
{
    square::num=5;
    cube::num=6;

    std::cout<<"Square of the \"num\" in cube namespace is:"<<square::fun(cube::num)<<std::endl;
    std::cout<<"Cube of the \"num\" variable in square namespace is:"<<cube::fun(square::num);

}
