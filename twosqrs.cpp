#include <iostream>
#include <math.h>

using namespace std;

bool isSumOfSquares(long long n) {
    unsigned long long maxIter = sqrt(n);
    unsigned long long startIter = 0;
    unsigned long long sumOfSquare;
    while(startIter <= maxIter) {
        sumOfSquare = startIter*startIter + maxIter*maxIter;
        if (sumOfSquare == n) {
            return true;
        } else if (sumOfSquare < n) {
            startIter++;
        } else {
            maxIter--;
        }
    }
    return false;
}



int main() {
    int c;
    unsigned long long n;
    scanf("%d",&c);
    for (int i = 0; i < c; i++) {
        scanf("%llu", &n);
        if (isSumOfSquares(n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
