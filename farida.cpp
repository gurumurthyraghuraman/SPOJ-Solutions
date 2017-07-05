#include <iostream>
#include <vector>

using namespace std;

long long maxNoOfCoins(vector<int> &monsterVec){
    long long dpArr[10001];
    int vecSize=monsterVec.size();
    if(vecSize==0){
        return 0;
    }
    dpArr[0]=0;
    dpArr[1]=monsterVec[0];
    for(int i=1;i<vecSize;i++) {
        if(dpArr[i]>monsterVec[i]+dpArr[i-1])
            dpArr[i+1]=dpArr[i];
        else
            dpArr[i+1]=monsterVec[i]+dpArr[i-1];
    }

    return dpArr[vecSize];

}


int main(){
    int t,n,tempIn;
    cin>>t;
    vector<int> inputVec;
    for(int i=0;i<t;i++) {
        cin>>n;
        inputVec.clear();
        for(int j=0;j<n;j++) {
            cin>>tempIn;
            inputVec.push_back(tempIn);
        }
        cout<<"Case "<<i+1<<": "<<maxNoOfCoins(inputVec)<<endl;
    }

}
