#include <iostream>

using namespace std;

int inputArr[100000][3];
long long dpArr[100000][3];

long long leastCost(int n) {

    dpArr[n - 1][1] = dpArr[n - 1][2] = inputArr[n - 1][1];
    if (inputArr[n - 1][0] < 0) {
        dpArr[n - 1][0] = inputArr[n - 1][0] + dpArr[n - 1][1];
    } else {
        dpArr[n - 1][0] = dpArr[n - 1][1];
    }

    for (int i = n - 2; i >= 0; i--) {
        dpArr[i][2] = inputArr[i][2] + min(dpArr[i + 1][1], dpArr[i + 1][2]);
        dpArr[i][1] = inputArr[i][1] + min(min(dpArr[i + 1][0], min(dpArr[i + 1][1], dpArr[i + 1][2])), dpArr[i][2]);
        dpArr[i][0] = inputArr[i][0] + min(dpArr[i + 1][0], min(dpArr[i + 1][1], dpArr[i][1]));
    }

    return dpArr[0][1];
}


int main() {
    int n;
    int testCaseNumber = 1;
    scanf("%d",&n);
    while(n) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d",&inputArr[i][0], &inputArr[i][1], &inputArr[i][2]);
        }
        printf("%d. %lld\n",testCaseNumber,leastCost(n));
        testCaseNumber++;
        scanf("%d",&n);
    }

}
