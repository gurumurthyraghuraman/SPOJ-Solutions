#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int minDiff(vector<int> arr1, vector<int> arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int i,j;
    i=j=0;
    int minDiff=1000001;
    while(i<arr1.size() && j<arr2.size()){
        if(abs(arr2[j]-arr1[i])<minDiff){
            minDiff=abs(arr2[j]-arr1[i]);
            if(minDiff==0)
                return minDiff;
        }
        else{
            if(arr2[j]>arr1[i]){
                i++;
            }
            else{
                j++;
            }
        }

    }
    return minDiff;

}


int main(){
    int t,n,temp;
    cin>>t;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<t;i++){
        arr1.clear();
        arr2.clear();
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            arr1.push_back(temp);
        }
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            arr2.push_back(temp);
        }
        cout<<minDiff(arr1, arr2)<<endl;
    }
    return 0;
}
