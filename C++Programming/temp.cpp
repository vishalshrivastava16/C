#include<iostream>
using namespace std;

struct SongList{
    char song[50];
    char singer[20];
    int point;
};

int main(){
    SongList List[5],tmp;
    int i,j;
    //  ‰»Î
    for(i=0;i<5;i++)
        cin>>List[i].song>>List[i].singer>>List[i].point;

    // ≈≈–Ú
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(List[i].point<List[j].point){
                tmp=List[i];
                List[i]=List[j];
                List[j]=tmp;
            }
        }
    }

    //  ‰≥ˆ
    for(i=0;i<5;i++)
        cout<<List[i].song<<' '<<List[i].singer<<' '<<List[i].point<<endl;


    system("pause");
	return 0;
}
