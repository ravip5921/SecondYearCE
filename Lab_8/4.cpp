#include<iostream>
#include<fstream>

using namespace std;

struct Student
{

//public: //bu default
char* name = new char[20];
int studentId;
char* department = new char[25];
char* address = new char[15];

};

int main()
{
    char* line = new char[30];
    Student stu;
    cout<<"Enter name:";
    cin>>stu.name;
    cout<<"Enter student id:";
    cin>>stu.studentId;
    cout<<"Enter department:";
    cin>>stu.department;
    cout<<"Enter address:";
    cin>>stu.address;

    ofstream f1out;
    f1out.open("Student.txt");      //Opens Student.txt
    if(!f1out){
            cout<<"File could not be created.\n";
    }
    else
    {
        f1out << stu.name<<endl;
        f1out << stu.studentId<<endl;
        f1out << stu.department<<endl;
        f1out << stu.address<<endl;
    }
    f1out.close();

    //cout<<endl;

    ifstream f1in;
    f1in.open("Student.txt");
    if(!f1in){
            cout<<"The file could not be opened.\n";
    }

    while(f1in >> line)
        {
        cout<<line<<endl;
    }
    f1in.close();
    delete[] line;
    return 0;
}
