#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,start,end,i,d,m,sum;
    cout<<"求n位自幂数，输入n：";
    cin>>n;
    while(n>0){
        start=pow(10,n-1);
        end=pow(10,n)-1;
        cout<<n<<"n位自幂数：";
        for(i=start;i<=end;i++)
        {
            m=i;
            sum=0;
            while(m!=0)
            {
                d=m%10;
                sum+=pow(d,n);
                m/=10;
            }

            if(sum==i)
                cout<<i<<" ";
        }
        cout<<endl;
        cout<<"求n位自幂数，输入n：";
        cin>>n;
    }
    cout<<endl;
    system("pause");
    return 0;

}