#include <iostream>
#include <cstdlib>

using namespace std;

class Employee
{
private:
    int id, year;
    float bonus,overtime;
public:
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
    void showpara(Employee *e1)
    {
        cout<<"\n\nEmployee with id: "<<e1->id<<" has received Rs."<<e1->bonus<<endl<<"and \nhad worked ";
        cout<<e1->overtime<<" hours as a overtime in the year "<<e1->year<<endl;
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
        system("cls");
        e[count_num].showpara(&e[count_num]);
        cout<<"\n\n\n\nWanna Continue ?[Y,N]: ";
        cin>>selection;
        count_num++;
    }while(selection=='Y' || selection=='y');
}
