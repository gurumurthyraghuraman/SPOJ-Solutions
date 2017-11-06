#include <iostream>
#include <map>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> numMap;
    int eachNum;
    int noOfPairs=0;
    for(int i=0;i<n;i++){
        cin>>eachNum;
        if(numMap.find(eachNum)!=numMap.end()){
            numMap[eachNum]+=1;

        }
        else{
            numMap[eachNum]=1;
        }
        if(numMap.find(eachNum+k)!=numMap.end())
            noOfPairs++;
        if(numMap.find(eachNum-k)!=numMap.end())
            noOfPairs++;
    }
    cout<<noOfPairs<<endl;
    return 0;

}
