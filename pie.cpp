#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const double pi=acos(-1);


double reqdFrnds(vector<double> &pieList, double mid,int noOfFrnds) {
    int frndsReqd=0;
    if(mid==0)
        return 0;
    for(int i=0;i<pieList.size();i++) {
        frndsReqd+=(int)(pieList[i]/mid);
    }
    if(frndsReqd>=noOfFrnds)
        return 1;
    else return 0;


}

double sizeOfPie(vector<double> &pieList,double low, double high, int noOfFrnds) {
    double mid=low + (high-low)/2;
    while(fabs(high -low)>1e-6) {
        mid = (low + high)/2;
        if(reqdFrnds(pieList,mid,noOfFrnds)==1)
            low =mid;
        else high = mid;
    }
    return low;

}

int main() {
    int t;
    int n,f,r;
    vector<double> lstPieVol;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        lstPieVol.clear();
        scanf("%d",&n);
        scanf("%d",&f);
        for(int j=0; j<n;j++) {
            scanf("%d", &r);
            lstPieVol.push_back(pi*r*r);
        }
        sort(lstPieVol.begin(),lstPieVol.end());
        printf("%f\n",sizeOfPie(lstPieVol,0,lstPieVol[n-1],f+1));
    }


    return 0;

}
