#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxMinDist(vector<int> &loc, int low, int high, int noOfCows, int vectorSize) {
    int mid,current_val,cowsFitted;
    while(low<high) {
        mid=low+(high-low+1)/2;
        cowsFitted=1;current_val=0;
        for(int i=0;i<vectorSize-1;i++) {
            if(current_val + loc[i+1]-loc[i]<mid)
                current_val+=loc[i+1]-loc[i];
            else {
                cowsFitted++;
                current_val=0;

            }
        }
        if(cowsFitted>=noOfCows)
            low=mid;
        else high=mid-1;

    }
    return low;

}

int main() {
    int t,n,c,tempStallLoc;
    cin>>t;
    vector<int> stallLoc;
    for(int i=0;i<t;i++) {
        cin>>n>>c;
        stallLoc.clear();
        for(int j=0;j<n;j++) {
            cin>>tempStallLoc;
            stallLoc.push_back(tempStallLoc);
        }
        sort(stallLoc.begin(),stallLoc.end());
        cout<<maxMinDist(stallLoc,1,stallLoc[n-1],c,n)<<endl;
    }

}
