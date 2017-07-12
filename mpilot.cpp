#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int dpArr[5001][5001];
int minimumCost(vector<pair<int,int> >& pilot, int captain, int assistant, int vecSize) {
    dpArr[0][0]=0;
    for(int i=0;i<=assistant;i++) {
        for(int j=1;j<=captain;j++) {
            if(i==0){
                dpArr[i][j]=dpArr[i][j-1]+pilot[vecSize-j].first;
            }
            if(i>0 && i==j){
                dpArr[i][j]=dpArr[i-1][j]+pilot[vecSize-i-j].second;

            }
            if(i>0 && i<j) {
                dpArr[i][j]=min(dpArr[i][j-1]+pilot[vecSize-i-j].first, dpArr[i-1][j]+pilot[vecSize-i-j].second);
            }
        }
    }
    return dpArr[captain][assistant];

    /*if(assistant==0){
        if(captain>0){
            return pilot[index].first+minimumCost(pilot,index+1,captain-1,assistant);
        }
        else return 0;
    }


    if(assistant==captain){
        return pilot[index].second + minimumCost(pilot,index+1,captain,assistant-1);
    }
    else {
        return min(pilot[index].first+minimumCost(pilot,index+1,captain-1,assistant), pilot[index].second+minimumCost(pilot,index+1,captain,assistant-1));
    }*/


}




int main() {
    int n;
    cin>>n;
    vector<pair<int,int> > pilot;
    int csalary,asalary;
    for(int i=0;i<n;i++) {
        cin>>csalary>>asalary;
        pair<int,int> tempPair(csalary,asalary);
        pilot.push_back(tempPair);
    }
    cout<<minimumCost(pilot,n/2,n/2,n)<<endl;

    return 0;

}
