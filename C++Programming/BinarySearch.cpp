#include<iostream>
using namespace std;

int Search(int a[],int n,int key)
{
    int low,high,mid;
    low = 0;
    high = n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(key==a[mid])
            return mid+1;
        else if(key>a[mid])
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main(){
    int a[]={3,5,6,9,10,11,12,15,19,22,23,29,30,45,50,54};
    int k,x;
    char again='n';
    do
    {
        cout<<"你要找的数？";
        cin>>x;
        k=Search(a,18,x);
        if(k>=0)
            cout<<x<<"是第"<<k<<"个数"<<endl;
        else
            cout<<x<<"不在序列中"<<endl;
        cout<<"还要找另一个数吗？(y/n)";
        cin>>again;
    }while(again!='n');
    system("pause");
	return 0;
}
