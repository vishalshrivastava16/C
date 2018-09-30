#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"sum:"<<a+b<<endl;
    cout<<"sub:"<<a-b<<endl;
    cout<<"mult:"<<a*b<<endl;
    cout<<""<<a%b<<endl;
    cout<<a<<""<<a*a*a<<endl;
    cout<<a<<""<<pow(a,3.5)<<endl;
    cout<<"exp("<<a<<")="<<exp(a)<<endl;
    cout<<"log("<<a<<")="<<log(a)<<endl;
    cout<<"log10("<<a<<")="<<log10(a)<<endl;
    cout<<"sin("<<a<<")="<<sin(a)<<endl;
    system("pause");
    return 0;
}