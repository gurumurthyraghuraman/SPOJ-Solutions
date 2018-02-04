#include <iostream>

using namespace std;


long initialPoints(int arr[1000], int n) {
    long prefixSum = 0;
    long reqdCoins = 0;
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if (prefixSum <= 0) {
            reqdCoins += prefixSum*(-1) + 1;
            prefixSum = 1;
        }
    }
    return reqdCoins;


}

int main() {
    int t;
    cin>>t;
    int n,arrVal;
    int arr[1000];
    for (int i = 0; i < t; i++){
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>arrVal;
            arr[j] = arrVal;
        }
        cout<<initialPoints(arr,n)<<endl;
    }
    return 0;
}
