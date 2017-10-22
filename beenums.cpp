#include <iostream>

using namespace std;

int main(){
    int num;
    int i;
    cin>>num;
    while(num!=-1){
        if(num==1)
            cout<<"Y"<<endl;
        else{
            i=1;
            num--;
            while(num>0){
                num=num-(6*i);
                i++;
            }
            if(num==0)
                cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
        cin>>num;

    }
    return 0;




}
