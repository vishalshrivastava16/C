//求两点的直线的斜率
#include <iostream>
using namespace std;
int main()
{
    double x1,x2,y1,y2;
    double k;
    cin>>x1>>y1>>x2>>y2;
    k=(y2-y1)/(x2-x1);
    cout<<k<<endl;
    return 0;
}