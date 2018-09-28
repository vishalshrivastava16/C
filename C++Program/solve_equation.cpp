#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c;

    if(a==0)
    {
        if(b==0)
            cout<<"not an equation"<<endl;
        else
            cout<<-c/b<<endl;
    }else{
        d=b*b-4*a*c;
        if(d>0){
            d=sqrt(d);
            cout<<(-b+d)/2/a<<endl;
            cout<<(-b-d)/2/a<<endl;
        }else{
            d=sqrt(-d);
            cout<<-b/2/a<<" + j*"<<d/2/a<<endl;
            cout<<-b/2/a<<" - j*"<<d/2/a<<endl;
        }
    }
    system("pause");
    return 0;
}