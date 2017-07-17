#include <iostream>
#include <vector>
#include <climits>
#include <stdio.h>
using namespace std;

vector<int> computePplAndStation(vector<int> &ppl,int target, int noOfStations) {
    vector<int> result;
    result.push_back(INT_MAX);
    result.push_back(0);
    int first,last,totalSum;
    first=0;
    last=0;
    totalSum=0;
    while(last<noOfStations) {
       totalSum+=ppl[last];
       if(totalSum<=target) {
            if(last-first+1>result[1] ){
                result[1]=last-first+1;
                result[0]=totalSum;
            }
        }
        else {
            totalSum-=ppl[first];
            first++;

        }
        if(first<=last && last-first+1==result[1] && totalSum<result[0]) {
                result[0]=totalSum;
                result[1]=last-first+1;
            }
        last++;
    }
    if(result[0]==INT_MAX)
        result[0]=0;
    return result;
}




int main() {
    int t;
    int noOfStations,seeNoOfPpl,tempNoOfPpl;
    vector<int> pplInStation;
    vector<int> retVector;
    cin>>t;

    for(int i=0;i<t;i++) {
        pplInStation.clear();
        retVector.clear();
        scanf("%d",&noOfStations);
        scanf("%d",&seeNoOfPpl);
        for(int j=0;j<noOfStations;j++) {
            scanf("%d",&tempNoOfPpl);
            pplInStation.push_back(tempNoOfPpl);
        }
        retVector=computePplAndStation(pplInStation,seeNoOfPpl,noOfStations);
        printf("%d %d\n",retVector[0], retVector[1]);
        //cout<<retVector[0]<<" "<<retVector[1]<<endl;


    }

    return 0;
}
