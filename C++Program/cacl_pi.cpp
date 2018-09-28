// 计算圆周率 pi=4*(1-1/3+1/5-1/7+……)
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double pi=0, d;
    double n=1;
    do{
        d=pow(-1,n-1)/(2*n-1);
        n++;
        pi+=d;
    }while(abs(d)>=1.0e-8);
    cout<<4*pi<<endl;

    system("pause");
    return 0;
}
