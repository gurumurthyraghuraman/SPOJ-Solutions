#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int frndsNeeded(int sum, vector<int> frnds, int noOfFrnds){
    sort(frnds.begin(),frnds.end());
    int frndSum=0;
    for(int k=noOfFrnds-1;k>=0;k--){
        frndSum+=frnds[k];
        if(frndSum>=sum)
            return noOfFrnds-k;

    }
    return -1;
}


int main(){
    int t,noOfStamps,noOfElements,temp,retValue;
    cin>>t;
    vector<int> elem;
    for(int i=0;i<t;i++){
        elem.clear();
        cin>>noOfStamps>>noOfElements;
        for(int j=0;j<noOfElements;j++){
            cin>>temp;
            elem.push_back(temp);
        }
        cout<<"Scenario #"<<i+1<<":"<<endl;
        retValue=frndsNeeded(noOfStamps,elem,noOfElements);
        if(retValue>0)
            cout<<retValue<<endl;
        else cout<<"impossible"<<endl;
        cout<<endl;
    }
    return 0;
}
