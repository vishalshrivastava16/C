#include<iostream>
using namespace std;
int main()
{
    char month[12][10]={"January","Feburary","March","April","May","June",
                        "July","August","September","October","November","December"};
    int m;
    cin>>m;
    if(m>0&&m<13)
        cout<<month[m-1]<<endl;
    else
        cout<<"ÊäÈëÔÂ·Ý´íÎó"<<endl;


    system("pause");
    return 0;
}