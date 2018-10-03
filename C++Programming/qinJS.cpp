#include<iostream>
using namespace std;

double qinJS(double a[],int n, double x)
{
    double y=0;
    for(int i=n-1;i>=0;i--){
        y=a[i]+x*y;
    }
    return y;
}


int main(){
    int n;
    double x,y, a[100];
    cout<<"项数?"<<endl;
    cin>>n;
    cout<<"x=?"<<endl;
    cin>>x;
    cout<<"输入各项系数:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"结果：";
    y=qinJS(a,n,x);
    cout<<y<<endl;

    system("pause");
	return 0;
}
