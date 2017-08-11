#include <iostream>
#include <stdio.h>
using namespace std;

int cashAfterReduction(int matrixArr[1000][1000], int n){
	int amountGot,amountOwed,maxVal;
	maxVal=amountGot=amountOwed=0;
	int eachBankArr[1000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			amountOwed+=matrixArr[i][j];
			amountGot+=matrixArr[j][i];
		}
		if(amountGot-amountOwed>0)
			maxVal+=amountGot-amountOwed;
		amountGot=amountOwed=0;
	}
	return maxVal;

}

int main() {
	// your code goes here
	int n,eachVal,initSum,t;
	scanf("%d",&n);
	t=1;
	int matrixArr[1000][1000];
	while(n!=0){
		initSum=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&eachVal);
				initSum+=eachVal;
				matrixArr[i][j]=eachVal;
			}
		cout<<t<<". "<<initSum<<" "<<cashAfterReduction(matrixArr,n)<<endl;
		t++;
		scanf("%d",&n);
	}
	return 0;
}
