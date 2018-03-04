#include <iostream>

using namespace std;

int treats[2000];
int dpArr[2000][2000];

void initialize() {
    for (int i = 0; i < 2000; i++)
        for (int j = 0; j < 2000; j++)
            dpArr[i][j] = -1;
}

int maxRevenue(int i, int j, int days) {
    if (i == j) {
        dpArr[i][j] = treats[i]*days;
        return dpArr[i][j];
    }
    if (dpArr[i][j] == -1)
        dpArr[i][j] = max(days*treats[j] + maxRevenue(i,j-1,days + 1), days*treats[i] + maxRevenue(i+1, j, days + 1));
    return dpArr[i][j];
}


int main() {
    int n,treatVal;
    initialize();
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>treatVal;
        treats[i] = treatVal;
    }
    cout<<maxRevenue(0,n-1,1)<<endl;
    return 0;
}
