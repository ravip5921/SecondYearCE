#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Transaction
{

 private:
  char firstName[25];
  char lastName[25];
  int accountNumber;
  int totalBalance;

 public:
  Transaction(){};

  Transaction(char fnm[], char lnm[], int anm, int tb):accountNumber(anm),totalBalance(tb)
  {
    strncpy(firstName,fnm,25);
    strncpy(lastName,lnm,25);
  }

  friend istream& operator>>(istream& in, Transaction& obj)
  {
  cout <<"\nFirst Name: ";
  in >> obj.firstName;
  cout << "Last Name: ";
  in >> obj.lastName;
  cout << "Account Number: ";
  in >> obj.accountNumber;
  cout << "Total Balance: ";
  in >> obj.totalBalance;
  cout<<endl;
  return in;
}
  friend ostream& operator<<(ostream& out, Transaction obj)
  {
  out << "\nFirst Name: " << obj.firstName;
  out << "\nLast Name: " << obj.lastName;
  out << "\nAccount Number: " << obj.accountNumber;
  out << "\nTotal Balance: " << obj.totalBalance << endl;
  return out;
}

};

int main()
{
  int choice;

  do
  {
    cout << "Choose:\n1.create record\n2.add record\n3.delete record\n4.edit record\n5.display record\n6.exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    fstream file;
    if(choice== 1)
    {
        char ans;
        file.open("account.txt",ios::out|ios::binary);

        do
        {
            Transaction obj;
            cin >> obj;
            file.write(reinterpret_cast<char *>(&obj),sizeof(obj));
            if (!file)
            {
                cerr << "Could not write the data to the file";
                return 1;
            }
            cout << "Do you want to continue (y/n) : ";
            cin >> ans;
        }while(ans=='y' || ans =='Y');

        file.close();
    }
  else if(choice == 2)
    {
        char ans;
        file.open("account.txt",ios::out|ios::app|ios::binary);
        do
        {
            Transaction obj;
            cin >> obj;
            file.write(reinterpret_cast<char *>(&obj),sizeof(obj));
            if (!file)
            {
                cerr << "Could not modify the data of the file";
                return 2;
            }
            cout << "Do you want to continue (y/n) : ";
            cin >> ans;
        }while(ans=='y');

    file.close();
  }
  else if(choice == 3)
  {
        char ans;
        Transaction obj;
        file.open("account.txt",ios::in|ios::binary);

        fstream newfile;
        newfile.open("temp.txt",ios::out|ios::binary);
        if(!newfile)
        {
        cerr << "could not create temp record file";
        }

        while(!file.eof())
        {
            file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
            if (file)
            {
                cout << obj;
                cout << "Do you want to delete this record (y/n) :";
                cin >> ans;

                if (ans != 'y')
                {
                    newfile.write(reinterpret_cast<char *>(&obj),sizeof(obj));

                    if(!newfile)
                    {
                        cerr << "unable to write to a temp file";
                        return 3;
                    }
                }
                else
                {
                    cout << "record deleted" << endl;
                }
            }
        }

        file.close();
        newfile.close();

        remove("account.txt");
        rename("temp.txt","account.txt");
  }
  else if(choice == 4)
  {
        char ans;
        file.open("account.txt",ios::in|ios::binary|ios::out);
        while(!file.eof())
        {
        Transaction obj;
        int pos = file.tellg();

        file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
        if (file)
        {
            cout << obj;
            cout << "Do you want to edit this record (y/n):";
            cin >> ans;
            if (ans == 'y')
            {
                cin >> obj;
                file.seekp(pos);
                file.write(reinterpret_cast<char *>(&obj),sizeof(obj));

                if(file)
                {
                    cout << "Record sucessfully edited"<< endl;
                }
                else
                {
                    cerr<< "Unable to modify the record";
                    return 4;
                }
            }
        }
    }

    file.close();
  }

  else if (choice == 5)
  {
        file.open("account.txt",ios::in|ios::binary);
        while(!file.eof())
        {
            Transaction obj;
            file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
            if(file)
            {
                cout << obj;
            }
            else
            {
                cerr << "Could not read through the file" << endl;
            }
        }
    file.close();
  }

}while(choice <= 5 && choice > 0 );
  return 0;
}
