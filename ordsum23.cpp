#include <iostream>
#include <stdio.h>

using namespace std;

int dpArr[1000001];

void ordSum(int n) {
    dpArr[0] = 0;
    dpArr[1] = 0;
    dpArr[2] = 1;
    dpArr[3] = 1;
    for(int i = 4; i <=n; i++) {
        dpArr[i] = (dpArr[i - 2] + dpArr[i - 3]) % 1000000007;
    }
    /*if(n == 2 || n == 3 )
        return 1;
    if (n < 2)
        return 0;
    return ordSum(n-2) + ordSum(n-3);*/

}

int main() {
    int t,n;
    scanf("%d",&t);
    ordSum(1000000);
    for(int i = 0; i < t; i++) {
        scanf("%d",&n);
        printf("%d\n",dpArr[n]);
    }
    return 0;
}
