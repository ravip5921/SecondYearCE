#include <iostream>
#include <cstdlib>

using namespace std;

class Employee
{
public:
    int year,id;
    float bonus,overtime;
    void setpara(Employee * e1)
    {
        cout<<"Enter year: ";
        cin>>e1->year;
        cout<<"Enter the Employee Id: ";
        cin>>e1->id;
        cout<<"Enter the bonus for employee(Id= "<<e1->id<<"): ";
        cin>>e1->bonus;
        cout<<"Enter total overtime done by employee(Id= "<<e1->id<<"): ";
        cin>>e1->overtime;
    }
    void displayReport(int id,int yr,float bon, float ot)
    {
        cout<<"\n\nEmployee with id: "<<id<<" has received Rs."<<bon<<endl<<"and \nhad worked ";
        cout<<ot<<" hours as a overtime in the year "<<yr<<endl;
    }
};
int main()
{
    Employee e[100];
    int count_num=0;
    char selection;
    do{
        cout<<"\t\tData Entry\n\n";
        e[count_num].setpara(&e[count_num]);
        cout<<"\n\n\n\nWanna Continue ?[Y,N]: ";
        cin>>selection;
        system("cls");
        count_num++;
    }while(selection=='Y' || selection=='y');
    system("cls");
    cout<<"\t\tEntered Records\n\n";

    for(int a=0;a<count_num;a++)
    {
        e[a].displayReport(e[a].id,e[a].year,e[a].bonus,e[a].overtime);
        for(int l=0;l<10;l++)
            cout<<"------------";
    }
}
