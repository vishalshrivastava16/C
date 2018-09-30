#include<iostream>
using namespace std;
int main()
{
	const int M=20,N=20,K=20;
	double A[M][N],B[N][K],C[M][K];
	int M1,N1,N2,K2;
	int i,j,k;
	
	// 输入
	cout<<"请输入第一个矩阵的维数 M N"<<endl;
	cin>>M1>>N1;
	cout<<"请按行输入第一个矩阵度元素"<<endl;
	for(i=0;i<M1;i++){
		for(j=0;j<N1;j++)
			cin>>A[i][j];
	}

	cout<<"请输入第二个矩阵的维数 N K"<<endl;
	cin>>N2>>K2;
	while(N2!=N1){
		cout<<"矩阵二的行数应等于矩阵一的列数，请重新输入：";
		cin>>N2>>K2;
	}

	cout<<"请按行输入第二个矩阵的元素"<<endl;
	for(i=0;i<N1;i++){
		for(j=0;j<K2;j++)
			cin>>B[i][j];
	}

	// 乘法
	for(i=0;i<M1;i++){
		for(j=0;j<K2;j++){
			C[i][j]=0;
			for(k=0;k<N1;k++)
				C[i][j]+=A[i][k]*B[k][j];
		}
	}

	// 输出
	for(i=0;i<M1;i++){
		for(j=0;j<K2;j++){
			cout<<C[i][j]<<'\t';
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
