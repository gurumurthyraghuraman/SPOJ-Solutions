#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

/*int maxLis(int arr[5000],int index, int n, int lastIndex){
	if(index>n)
		return 0;
	int a;
	int b=0;
	if(lastIndex==-1){
		a=1+maxLis(arr,index+1,n,index);
		return a;
	}
	a=maxLis(arr,index+1,n,lastIndex);

	if(fabs(arr[lastIndex])<fabs(arr[index]) &&
	   ((arr[lastIndex]>0 && arr[index]<0) || (arr[lastIndex]<0 && arr[index]>0)))
			b=1+maxLis(arr,index+1,n,index);

	return max(a,b);

}*/

int sign(int a){
    if(a<0)
        return -1;

    return 1;

}

int maxLis(int arr[5000],int n){
    int lisArr[5000];
    for(int p=0;p<n;p++)
        lisArr[p]=1;
    int maxVal;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(abs(arr[j])<abs(arr[i]) && sign(arr[j])!=sign(arr[i])){
                if(lisArr[j]+1>lisArr[i]){
                    lisArr[i]=lisArr[j]+1;
                }
            }
        }
    }
    maxVal=-1;
    for(int k=0;k<n;k++){
        maxVal=max(lisArr[k],maxVal);
    }
    return maxVal;
}

int main() {
	// your code goes here
	int n,tempNo;
	int arr[5000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tempNo;
		arr[i]=tempNo;
	}
	cout<<maxLis(arr,n)<<endl;
	return 0;
}
