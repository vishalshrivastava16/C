#include<iostream>
using namespace std;
int main()
{
	int n;
	n=sizeof(short int);
	cout<<"short int "<<n<<endl;
	n=sizeof(int);
	cout<<"int       "<<n<<endl;
	n=sizeof(long int);
	cout<<"long int  "<<n<<endl;
	n=sizeof(char);
	cout<<"char      "<<n<<endl;
	n=sizeof(bool);
	cout<<"bool      "<<n<<endl;
	n=sizeof(float);
	cout<<"float     "<<n<<endl;
	n=sizeof(double);
	cout<<"double    "<<n<<endl;
	
	
	
	return 0;
}
 
