//Determines net salary using inline function
#include <iostream>

using namespace std;
inline float netSal(float sal)
{
    float finalSal;
    finalSal = 0.9*sal;
    return finalSal;
}
int main()
{
    float sal;
    cout << "Enter your salary:";
    cin >> sal;
    cout << "Your net salary is:"<< netSal(sal);
    return 0;
}

