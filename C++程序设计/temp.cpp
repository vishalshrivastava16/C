#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int e=8;
    double f=6.4, g=8.9;
    cout<<(f+int(e/3*int(f+g)/2)%4)<<endl;

    system("pause");
    return 0;
}