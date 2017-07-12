#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int cal_UpperEnv(vector<pair<int,int> >& rect,int noOfRect) {
    vector<pair<int,int> > dpArr(1000);
    int normal,rotated;
    dpArr[0].first=rect[0].first;
    dpArr[0].second=rect[0].second;
    for(int i=1;i<noOfRect;i++) {

        normal=rect[i].first+max(dpArr[i-1].first+abs(rect[i].second-rect[i-1].second), dpArr[i-1].second+abs(rect[i].second-rect[i-1].first));
        rotated=rect[i].second+max(dpArr[i-1].first+abs(rect[i].first-rect[i-1].second),dpArr[i-1].second+abs(rect[i].first-rect[i-1].first));
        dpArr[i].first=normal;
        dpArr[i].second=rotated;
    }

    return max(dpArr[noOfRect-1].first, dpArr[noOfRect-1].second);
}


int main() {
    int n,x,y;
    vector<pair<int,int> > rectPair;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x>>y;
        pair<int,int> tempRect(x,y);
        rectPair.push_back(tempRect);
    }
    cout<<cal_UpperEnv(rectPair,n)<<endl;
    return 0;

}
