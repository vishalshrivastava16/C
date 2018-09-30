#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int len=0,i=0;
    char str[100];
    cin.getline(str,100);
    while(str[i++]!='\0'){
        len++;
    }
    cout<<len;
    system("pause");
	return 0;
}
