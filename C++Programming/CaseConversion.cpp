//Сдת��д
#include<iostream>
using namespace std;
int main(){
    char str[50];
    int i=0;
    cin>>str;
    while(str[i]!='\0')
    {
        str[i++]-=32;
    }
    cout<<str<<endl;

    system("pause");
    return 0;
}