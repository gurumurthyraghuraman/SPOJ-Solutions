#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<int> appleCost, int k) {
	int dpArr[101];
	int minVal;
	dpArr[0]=0;
	for(int i=1;i<=k;i++){
		minVal=10000001;
		for(int j=0;j<k;j++) {
			if(j+1<=i && appleCost[j]!=-1 && dpArr[i-(j+1)]!=-1){
				if(dpArr[i-(j+1)]+appleCost[j]<minVal)
					minVal=dpArr[i-(j+1)]+appleCost[j];
			}
		}
		if(minVal==10000001)
			dpArr[i]=-1;
		else dpArr[i]=minVal;

	}

	return dpArr[k];
}


int main() {
	// your code goes here
	int t,n,k,eachAppleCost;
	vector<int> appleCost;
	cin>>t;
	for(int i=0;i<t;i++) {
		appleCost.clear();
		cin>>n>>k;
		for(int j=0;j<k;j++){
			cin>>eachAppleCost;
			appleCost.push_back(eachAppleCost);
		}
		cout<<minCost(appleCost,k)<<endl;
	}
	return 0;
}
