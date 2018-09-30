#include<iostream>
#include<cstring>
using namespace std;

struct WordList{
	char word[20];//一个单词
	int freq;//单词出现频率
};

int main()
{
	WordList list[1000];
	int N=0;//实际单词数
	int i,j,k;
	char tmp[20];
	cout<<"请输入一系列英语单词，以xyz表示输入结束"<<endl;
	cin>>tmp;
	while(strcmp(tmp,"xyz")!=0){
		for(i=0;i<N;i++){
			if(strcmp(list[i].word,tmp)==0){
				list[i].freq++;
				break;
			}
		}
		if(i>=N){
			strcpy(list[i].word,tmp);
			list[i].freq=1;
			N++;
		}
		cin>>tmp;
	}

	// 排序输出
	for(i=0;i<N-1;i++){
		k=i;
		for(j=i+1;j<N;j++){
			if(strcmp(list[j].word,list[k].word)<0){
				k=j;
			}
		}
		if(k!=i){
			WordList tmp;
			tmp=list[i];
			list[i]=list[k];
			list[k]=tmp;
		}
	}

	cout<<"统计结果："<<endl;
	for(i=0;i<N;i++)
		cout<<list[i].word<<"\t\t"<<list[i].freq<<endl;

	system("pause");
	return 0;
}
