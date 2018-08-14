#include <iostream>

using namespace std;

long long dpArr[65][10];

void initializeArray() {
    for (int j = 0; j < 10; j++) {
        dpArr[0][j] = 1;
    }
    for (int i = 1; i <= 64; i++) {
        dpArr[i][0] = 1;
    }
}

void preComputeNonDecreasingNumbers() {
    initializeArray();
    for (int i = 1; i <=64; i++) {
        for (int j = 1; j < 10; j++) {
            dpArr[i][j] = dpArr[i - 1][j] +  dpArr[i][j - 1];
        }
    }
}


int main() {
    int t;
    int datasetNumber, numberOfDigits;
    preComputeNonDecreasingNumbers();
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>datasetNumber>>numberOfDigits;
        cout<<datasetNumber<<" "<<dpArr[numberOfDigits][9]<<endl;
    }
    return 0;
}
