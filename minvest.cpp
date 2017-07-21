#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;


int dpArr[100000];

int maxInterest(int totalAmnt, vector<pair<int, int> > bonds, int d, int prevTotalAmnt) {
	int noOfRows=totalAmnt/1000;
	int begin=prevTotalAmnt/1000;
	int maxVal;
	for(int i=begin;i<=noOfRows;i++) {
		if(i==0)
			dpArr[i]=0;
		else {
			maxVal=0;
			for(int j=0;j<d;j++) {
				if(i-(bonds[j].first/1000)>=0) {
					if(bonds[j].second+dpArr[i-(bonds[j].first/1000)]>maxVal)
						maxVal=bonds[j].second+dpArr[i-(bonds[j].first/1000)];
				}
			}
			dpArr[i]=maxVal;
		}
	}
	return dpArr[noOfRows];

}

void initializeArray() {
	for(int i=0;i<100000;i++)
		dpArr[i]=0;

}

int roundTotalAmnt(int totalAmnt) {
	int quo=totalAmnt/1000;
	totalAmnt=quo*1000;
	return totalAmnt;
}

int main() {
// your code goes here

	int t,noOfYrs,bondValue,interest,recdInterest,d,totalAmnt,prevTotal;
	vector<pair<int, int> > bonds;
	cin>>t;
	for(int i=0;i<t;i++){
		initializeArray();
		bonds.clear();
		prevTotal=0;
		cin>>totalAmnt>>noOfYrs;
		//totalAmnt=roundTotalAmnt(totalAmnt);
		cin>>d;
		for(int j=0;j<d;j++) {
		cin>>bondValue>>interest;
		bonds.push_back(make_pair(bondValue,interest));
		}
		for(int k=1;k<=noOfYrs;k++) {
			recdInterest=maxInterest(totalAmnt,bonds, d,prevTotal);
			prevTotal=totalAmnt;
			totalAmnt=totalAmnt+recdInterest;

		}
		cout<<totalAmnt<<endl;


	}
return 0;
}
