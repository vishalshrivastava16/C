#include<iostream>
using namespace std;
int main()
{
	//取子字符串
	char str[101];// 原字符串
	char sub[101];// 子字符串
	int len;//源字符串长度
	int k,l;//子字符串起始位置，长度
	int i,j;

	cout<<"请输入字符串"<<endl;
	cin.getline(str,100);

	// 求字符串长度
	len=0;
	while(str[len]!='\0')
		len++;

	cout<<"请输入子字符串起始位置和长度"<<endl;
	cin>>k>>l;
	while(k!=0&&l!=0){
		j=0;
		for(i=k-1;i<len&&i<k-1+l;i++){
			sub[j++]=str[i];
		}
		sub[j]='\0';
		cout<<sub<<endl;
		cout<<"请输入子字符串起始位置和长度"<<endl;
		cin>>k>>l;
	}

	system("pause");
	return 0;
}
