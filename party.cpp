#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<int,int> minCostMaxFun(vector<pair<int,int> > party, int budget, int vecSize) {
	int dpArr[501][100];
	for(int i=0;i<=budget;i++)
		for(int j=0;j<vecSize;j++) {
			if(i==0)
				dpArr[i][j]=0;
			else if(j==0) {
				if(i-party[j].first>=0)
					dpArr[i][j]=party[j].second;
				else dpArr[i][j]=0;
			}
			else if(i-party[j].first>=0){
					dpArr[i][j]=max(party[j].second+dpArr[i-party[j].first][j-1],
									dpArr[i][j-1]);
			}
			else dpArr[i][j]=dpArr[i][j-1];

	}
	int totalFun=dpArr[budget][vecSize-1];
	int minCost=budget;
	while(dpArr[minCost][vecSize-1]==totalFun) {
		minCost--;
	}
	minCost++;
	pair<int,int> retPair(minCost,totalFun);

	return retPair;
}


/*int minCostMaxFun(vector<pair<int,int> > party, int index, int vecSize, int budget) {
	if(index==vecSize)
		return 0;

	if(budget-party[index].first>=0){
		return max(party[index].second+minCostMaxFun(party,index+1,vecSize,budget-party[index].first),
			minCostMaxFun(party,index+1,vecSize,budget));
	}
	return minCostMaxFun(party,index+1,vecSize,budget);


}*/


int main() {
	// your code goes here
	int budget,n,cost, fun;
	cin>>budget>>n;
	vector<pair<int,int> > party;
	while(budget!=0 && n!=0) {
		party.clear();
		for(int i=0;i<n;i++) {
			cin>>cost>>fun;
			pair<int,int> eachPair(cost,fun);
			party.push_back(eachPair);
		}
		pair<int,int> ans=minCostMaxFun(party,budget,n);
		cout<<ans.first<<" "<<ans.second<<endl;
		cin>>budget>>n;
	}
	return 0;
}
