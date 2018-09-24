#include<iostream>
using namespace std;
int main()
{
    char c;
    char ec;
    int k;
    cout<<"Please input c and k: ";
    cin>>c>>k;
    ec=(c-'a'+k)%26+'a';
    cout<<ec<<endl;
    system("pause");
    return 0;
}