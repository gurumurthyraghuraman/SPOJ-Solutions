#include <iostream>

using namespace std;

void print(int x, int y) {
    int arr[99][99];
    for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++){
            if(i==0 && j==0){
                arr[i][j]=0;
                cout<<"*";
            }
            else {
                if((j>0 && arr[i][j-1]==0) || (i>0 && arr[i-1][j]==0) ) {
                        arr[i][j]=1;
                        cout<<".";
                }
                else {
                    arr[i][j]=0;
                    cout<<"*";
                }

            }
        }
        cout<<endl;
    }

}

int main() {
    int t;
    int l,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>l>>m;
        print(l,m);
        cout<<endl;
    }
    return 0;

}
