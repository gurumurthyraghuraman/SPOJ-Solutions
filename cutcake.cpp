#include <iostream>

using namespace std;

long long noOfCuts(long long n){
    long long cuts=0;
    long long noOfPieces=0;
    if(n==1)
        return 0;
    while(noOfPieces<n){
        cuts++;
        noOfPieces=(cuts*cuts+cuts+2)/2;
    }
    return cuts;
}

int main(){
    int t;
    long long n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<noOfCuts(n)<<endl;
    }
    return 0;
}

