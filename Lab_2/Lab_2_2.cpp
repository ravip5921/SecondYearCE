//Shows the meaning of overloading function
#include<iostream>
#include<iomanip>

using namespace std;
float feettoinches()
{
    float feet;
     cout << "Enter feet: B"<<endl;
    cin>>feet;
    cout <<"Feet: B = "<< feet*12 << " Inches" <<endl;
}
float feettoinches(float feet)
{
    float ans;
    ans = feet*12;
    return ans;
}
float feettoinches(float* feet, float* ans)
{
    float y;
    *ans = *feet*12;
    return 0;
}
int main()
{
    float feet,y;
    float answ;
    cout << "Enter feet: A"<<endl;
    cin >> feet;
   feettoinches();
   y=feettoinches(feet);
   cout << "Feet A ="<<y<<" Inches"<<endl;
   feettoinches(&feet,&answ);
   cout << "Feet: A="<<answ<<" Inches";
}




