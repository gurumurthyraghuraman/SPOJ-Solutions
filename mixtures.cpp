#include <iostream>

using namespace std;


void bestMixture(int dpArrSmoke[100][100], int dpArrColor[100][100], int p, int q) {
    int k = 0;
    int minSmoke = -1;
    int minColor;
    while(k < q - p) {
        if (minSmoke == -1) {
            minSmoke = dpArrSmoke[p][p + k] + dpArrSmoke[p+k+1][q] + dpArrColor[p][p + k]*dpArrColor[p + k +1][q];
            minColor =  (dpArrColor[p][p + k] + dpArrColor[p + k +1][q]) % 100;
        } else {
            if (minSmoke > dpArrSmoke[p][p + k] + dpArrSmoke[p+k+1][q] + dpArrColor[p][p + k]*dpArrColor[p +k +1][q]) {
                minSmoke = dpArrSmoke[p][p + k] + dpArrSmoke[p+k+1][q] + dpArrColor[p][p + k]*dpArrColor[p +k +1][q];
                minColor = (dpArrColor[p][p + k] + dpArrColor[p + k +1][q]) % 100;
            }
            if (minSmoke == dpArrSmoke[p][p + k] + dpArrSmoke[p+k+1][q] + dpArrColor[p][p + k]*dpArrColor[p +k +1][q])
                if (((dpArrColor[p][p + k] + dpArrColor[p + k +1][q]) % 100) < minColor) {
                    minSmoke = dpArrSmoke[p][p + k] + dpArrSmoke[p+k+1][q] + dpArrColor[p][p + k]*dpArrColor[p +k +1][q];
                    minColor = (dpArrColor[p][p + k] + dpArrColor[p + k +1][q]) % 100;
                }
        }
        k++;
    }
    dpArrColor[p][q] = minColor;
    dpArrSmoke[p][q] = minSmoke;
}

int minSmoke(int inputColorArr[100], int dpArrSmoke[100][100], int dpArrColor[100][100], int n) {
    for (int i = 0; i < n; i++) {
        dpArrColor[i][i] = inputColorArr[i];
        dpArrSmoke[i][i] = 0;
    }
    int k = 1;
    while(k <= n - 1) {
        for (int i = 0; i < n - k; i++) {
            bestMixture(dpArrSmoke, dpArrColor, i, i + k);
        }
        k++;
    }
    return dpArrSmoke[0][n-1];

}


int main() {
    int dpArrSmoke[100][100];
    int dpArrColor[100][100];
    int inputColorArr[100];
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i = 0; i < n; i++) {
            cin>>inputColorArr[i];
        }
        if (n == 1)
            cout<<0<<endl;
        else cout<<minSmoke(inputColorArr,dpArrSmoke,dpArrColor,n)<<endl;
    }
    return 0;
}
