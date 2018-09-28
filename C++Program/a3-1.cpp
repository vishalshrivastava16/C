#include<iostream>
using namespace std;

int main()
{
	cout<<"1-abced\n#12345\n";
	cout<<"2-abced\r#12345\n";
	cout<<"3-abced\t#12345\n";
	cout<<"4-abced\f#12345\n";
	cout<<"5-abced\b#12345\n";
	cout<<"6-abced\\#12345\n";
	cout<<"7-abced\'#12345\n";
	cout<<"8-abced\"#12345\n";
	cout<<"9-abced\0#12345\n";
	cout<<"10-abced\141#12345\n";
	
	return 0;
	
}
