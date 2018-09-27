#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double money,years,rate,sum;
    cout<<"请输入本金 存款年限 利息"<<endl;
    cin>>money>>years>>rate;
    while(money>0){
        sum=money*pow(1+rate,years);
        cout<<"本息共 "<<sum<<endl;
        cin>>money>>years>>rate;
    }
    system("pause");
    return 0;
}