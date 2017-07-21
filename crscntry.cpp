#include <iostream>
#include <vector>
using namespace std;

int LCS(vector<int> agnes, vector<int> tom) {
	int dpArr[2001][2001];
	int m=agnes.size();
	int n=tom.size();
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=n;j++) {
			if(i==0 || j==0)
				dpArr[i][j]=0;
			else {
				if(agnes[i-1]==tom[j-1]) {
					dpArr[i][j]=dpArr[i-1][j-1]+1;
				}
				else {
					dpArr[i][j]=max(dpArr[i-1][j],dpArr[i][j-1]);
				}
			}
		}
	}
	return dpArr[m][n];

}

int main() {
	// your code goes here
	int noOfSets;
	cin>>noOfSets;
	vector<int> agnes;
	vector<int> tom;
	int i=0;
	int m=0;
	int input=1;
	int tomInput=1;
	while(i<noOfSets) {
		agnes.clear();
		input=1;
		while(input!=0) {
			cin>>input;
			agnes.push_back(input);
		}
		cin>>input;
		m=0;
		while(input!=0){
			tom.push_back(input);
			tomInput=1;
			while(tomInput!=0) {
				cin>>tomInput;
				tom.push_back(tomInput);
			}
			m=max(m,LCS(agnes,tom));
			tom.clear();
			cin>>input;
		}
		cout<<m-1<<endl;
		i++;
	}
	return 0;
}
