#include <iostream>
#include <bitset>
using namespace std;

int main(){
    for(int n=0;n<32;n++){
        cout<<bitset<5>(n)<<endl;
    }
    return 0;

}
