#include<iostream>
using namespace std;
int main()
{
	//√∞≈›≈≈–Ú

	//  ‰»Î
	int n,i,j,tmp;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	// ≈≈–Ú
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j]<a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	//  ‰≥ˆ
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	system("pause");
	return 0;
}
