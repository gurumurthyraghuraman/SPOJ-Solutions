#include <iostream>

using namespace std;

int fareArray[100][100];

int minimumCost(int n, int m) {
    int dpArr[100][100];
    int result;
    for(int j = 0; j < m ; j++) {
        dpArr[0][j] = fareArray[0][j];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (j == 0) {
                dpArr[i][j] = fareArray[i][j] + min(dpArr[i-1][j], dpArr[i-1][j+1]);
            }
            else if (j == m - 1) {
                dpArr[i][j] = fareArray[i][j] + min(dpArr[i-1][j-1], dpArr[i-1][j]);
            }
            else {
                dpArr[i][j] = fareArray[i][j] + min(dpArr[i-1][j-1], min(dpArr[i-1][j],dpArr[i-1][j+1]));
            }
        }
    }
    result = dpArr[n-1][0];
    for(int j = 1; j < m; j++) {
        if (dpArr[n-1][j] < result) {
            result = dpArr[n-1][j];
        }
    }
    return result;

}

int main() {
    int n,m,k;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>k;
            fareArray[i][j] = k;
        }
    }
    cout<<minimumCost(n, m)<<endl;
    return 0;
}
