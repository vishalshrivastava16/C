#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double num1,num2;
    char op;
    double result;
    char caption1[30]="Error,Divided by 0!";
    char caption2[30]="Invalid operator!";
    cout<<"Please input the expression:";
    cin>>num1>>op>>num2;
    switch(op)
    {
        case '+':   
            result=num1+num2;
            cout<<num1<<op<<num2<<"="<<result<<endl;
            break;
        case '-':   
            result=num1-num2;
            cout<<num1<<op<<num2<<'='<<result<<endl;
            break;
        case '*':
            result=num1*num2;
            cout<<num1<<op<<num2<<'*'<<result<<endl;
            break;
        case '/':
            if(abs(num2)<1.0e-8)
                cout<<caption1<<endl;
            else{
                result=num1/num2;
                cout<<num1<<op<<num2<<"="<<result<<endl;
                break;
            }
            break;
        default:
            cout<<caption2<<endl;
    }
    system("pause");
    return 0;
}