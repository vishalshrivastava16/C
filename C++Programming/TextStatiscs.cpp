#include<iostream>
using namespace std;
int main()
{
	// 文本统计
	const int N=101;
	char str[N],c;
	int len=0,capital=0,smallletter=0,digit=0,others=0;
	int i=0;
	cin.getline(str,N);

	// 处理
	while(str[i]!='\0'){
		len++;
		c=str[i];
		if(c<='Z'&&c>='A')
			capital++;
		else if(c<='z'&&c>='a')
			smallletter++;
		else if(c<='9'&&c>='0')
			digit++;
		else
			others++;
		i++;
	}

	cout<<"字符串总长度："<<len<<endl;
	cout<<"大写字母个数："<<capital<<endl;
	cout<<"小写字母个数："<<smallletter<<endl;
	cout<<"数字个数    ："<<digit<<endl;
	cout<<"其他字符个数："<<others<<endl;
	

	system("pause");
	return 0;
}
