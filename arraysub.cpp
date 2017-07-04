#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> maxSubArray(vector<int> &arr, int k) {
    vector<int> result;
    int maxInArr=0;
    int arrSize=arr.size();
    for(int i=0;i<k;i++){
        if(arr[i]>maxInArr) maxInArr=arr[i];
    }
    result.push_back(maxInArr);
    for(int j=k;j<arrSize;j++) {
        if(arr[j]>maxInArr) {
            maxInArr=arr[j];
            result.push_back(maxInArr);
        }
        else if(arr[j]<maxInArr && arr[j-k]!=maxInArr) {
            result.push_back(maxInArr);
        }
        else {
            maxInArr=0;
            for(int i=j-k+1;i<=j;i++) {
                if(arr[i]>maxInArr) maxInArr=arr[i];
            }
            result.push_back(maxInArr);
        }
    }
    return result;
}



int main() {
    int n,k,tempInt,resSize;
    vector<int> arr;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&tempInt);
        arr.push_back(tempInt);
    }
    scanf("%d",&k);
    vector<int> res=maxSubArray(arr,k);
    resSize=res.size();
    for(int i=0;i<resSize-1;i++) {
        printf("%d ", res[i]);
    }
    printf("%d\n",res[resSize-1]);
    return 0;
}
