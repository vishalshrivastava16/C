#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num,d25,d10,d5,count=0;
    cin>>num;
    if(num>99||num<0)
        cout<<"the money is invalid!"<<endl;
    else{
        for(d25=0;d25<=(num/25);d25++){
            for(d10=0;d10<=(num-d25)/10;d10++){
                for(d5=0;d5<=(num-d25-d10)/5;d5++){
                    if(25*d25+10*d10+5*d5<=num)
                        count++;
                }
            }
        }
    cout<<count<<endl;        
    }

    system("pause");
    return 0;
}