#include <iostream>
#include <map>

using namespace std;

int arr[1000000];
long long prefixSum[1000000];


long long noOfSubSeq(int n){
    long long subSeq=0;
    prefixSum[0]=arr[0];
    map<long long, long long> prefixMap;
    prefixMap[arr[0]]=1;
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+arr[i];
        if(prefixMap.find(prefixSum[i])!=prefixMap.end())
            prefixMap[prefixSum[i]]=prefixMap[prefixSum[i]]+1;
        else prefixMap[prefixSum[i]] = 1;
    }

    for(map<long long,long long>::iterator it=prefixMap.begin(); it!=prefixMap.end(); ++it){
        if(it->first!=0){
            subSeq+=(it->second)*(it->second - 1)/2;
        }
        else{
            subSeq+=(it->second) + (it->second)*(it->second - 1)/2;
        }
    }

    return subSeq;



}


int main(){
    int t;
    int n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        cout<<noOfSubSeq(n)<<endl;
    }

    return 0;
}
