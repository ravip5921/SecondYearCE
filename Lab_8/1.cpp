#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char const *argv[]) {

  cout<<setw(70)<<setfill('*')<<"ABC Department store"<<setw(51)<<setfill('*')<<'\n';

    cout.width(65);
  cout<<setfill(' ')<< "Invoice\n\n";
    cout.width(64);

  cout<<right<<" DESCRIPTION || ITEM || ";

  cout<<left<<" QUANTITY || PRICE\n\n\n";
    cout<<"\n\n\n";

  cout<<setw(115)<<right<<"\tThank you!!\t"<<endl;
  return 0;
}
