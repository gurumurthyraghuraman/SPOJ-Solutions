#include <iostream>

using namespace std;

int maxNoOfStones(int tiles[100][100], int n, int m) {
    int dpArr[100][100];
    for (int j = 0; j < m; j++) {
        dpArr[0][j] = tiles[0][j];
    }
    for (int i = 1; i < n; i++)  {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                dpArr[i][j] = tiles[i][j] + max(dpArr[i -1][j], dpArr[i -1][j + 1]);
            }
            else if (j == m - 1) {
                dpArr[i][j] = tiles[i][j] + max(dpArr[i - 1][j], dpArr[i - 1][j - 1]);
            }
            else {
                dpArr[i][j] = tiles[i][j] + max(dpArr[i - 1][j - 1], max(dpArr[i - 1][j], dpArr[i - 1][j + 1]));
            }
        }

    }
    int maxStones = dpArr[n - 1][0];
    for (int j = 1; j < m; j++) {
        if (dpArr[n-1][j] > maxStones) {
            maxStones = dpArr[n-1][j];
        }
    }
    return maxStones;
}

int main() {
    int t,n,m,noOfStones;
    int tiles[100][100];
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n>>m;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin>>noOfStones;
                tiles[j][k] = noOfStones;
            }
        }
        cout<<maxNoOfStones(tiles, n, m)<<endl;
    }
    return 0;
}
