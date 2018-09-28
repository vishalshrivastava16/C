#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,s,A;
    cout<<"Three edges: "<<endl;
    cin>>a>>b>>c;
    s=(a+b+c)/2;
    A=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"The area is "<<A<<endl;
    system("pause");
    return 0;

}