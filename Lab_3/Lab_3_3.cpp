#include <iostream>
#include <cstdlib>

using namespace std;

class Carpark
{
private:
int car_id,charge_hr=20;
float time;
public:
    void setdata()
    {
        cout<<"Enter Car Id: ";
        cin>>car_id;
        cout<<"Enter parking time: ";
        cin>>time;
    }
    void showdata()//Carpark c1)
    {
        system("cls");
        float charge = time*charge_hr;
        cout<<"Car Id: "<<car_id<<endl<<"Parking Time: "<<time<<endl<<"Total Charge: Rs."<<charge<<endl;
    }
};
void show_data(Carpark c1)
{
    c1.showdata();
}
int main()
{
    char n;
    Carpark car1;
    car1.setdata();
    //car1.showdata();
    show_data(car1);
    cin>>n;
}
