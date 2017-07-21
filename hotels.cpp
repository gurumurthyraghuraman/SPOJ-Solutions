#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int maxCost(vector<int> &hotels,int n, int m) {
	int totalSum=0;
	int totalMaxSum=-1;
	int first=0;
	int last=0;
	while(last<=n){
		if(totalSum<=m) {
			if(last<n) {
				totalSum+=hotels[last];
			}
			last++;
		}
		else{
			totalSum-=hotels[first];
			first++;
		}
		if(totalSum<=m && totalSum>totalMaxSum)
			totalMaxSum=totalSum;
	}
	return totalMaxSum;
}



int main() {
	int n,m,temp;
	vector<int> hotels;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&temp);
		hotels.push_back(temp);
	}
	printf("%d\n",maxCost(hotels,n,m));
	return 0;
}
