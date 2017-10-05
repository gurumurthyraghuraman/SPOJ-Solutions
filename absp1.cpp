#include <iostream>
using namespace std;

unsigned long long distinctSum(unsigned long long arr[10000],int n){
	unsigned long long result=0;
	for(int i=0;i<n;i++){
		result+=i*arr[i];
		result-=arr[i]*(n-1-i);
	}
	return result;


}

int main() {
	int t,n;
	unsigned long long arr[10000];
	unsigned long long temp;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>temp;
			arr[j]=temp;
		}
		cout<<distinctSum(arr,n)<<endl;

	}
	// your code goes here
	return 0;
}
