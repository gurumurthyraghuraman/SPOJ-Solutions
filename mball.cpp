#include <iostream>
using namespace std;

long long dpArr[100001][5];

long long noOfWays(int n,int index, int arrPoints[5]){
	long long a,b;
	for(int i=0;i<=n;i++) {
		for(int j=0;j<5;j++) {
			if(i==0) {
				dpArr[i][j]=1;
			}
			else {
					if(j-1>=0)
						a=dpArr[i][j-1];
					else a=0;

					if(i-arrPoints[j]>=0)
						b=dpArr[i-arrPoints[j]][j];
					else b=0;

					dpArr[i][j]=a+b;

			}
		}

	}

return dpArr[n][4];

	/*if(n<0 || index<0)
		return 0;
	if(n==0)
		return 1;
	return noOfWays(n,index-1,arrPoints) + noOfWays(n-arrPoints[index],index,arrPoints);*/
}


int main() {
	int t,n;
	int arrPoints[5]={2,3,6,7,8};
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		cout<<noOfWays(n,4,arrPoints)<<endl;

	}
	return 0;
}
