#include<iostream>

using namespace std;

class MyManip{

private:
 int Mwidth, Mprecision;
 char Mfillc;

public:
 MyManip(int W, int P, char F)
 {
    Mwidth = W;
    Mprecision = P;
    Mfillc = F;
 }

friend ostream& operator<<(ostream& out, MyManip MM)
{
    out.width(MM.Mwidth);
    out.precision(MM.Mprecision);
    out.fill(MM.Mfillc);
    out<<flush;
return out;
}
};

MyManip setwpf(int w, int p , char f){
 return MyManip(w, p, f);
}

int main()
{
cout<<setwpf(15,7,'|')<<3839.3442323121;
return 0;
}
