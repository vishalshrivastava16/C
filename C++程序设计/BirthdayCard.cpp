#include <iostream>
using namespace std;
int main()
{
    char name1[50], name2[50];// 字符数组
    cin.getline(name1,50);// 按行输入
    cin.getline(name2,50);
    cout<<"##############################"<<endl;
    cout<<name1<<endl;
    cout<<endl;
    cout<<"Happy Birthday To You!"<<endl;
    cout<<endl;
    cout<<"          sincerely yours "<<name2<<endl;
    cout<<"##############################"<<endl;

    system("pause");
    return 0;

}