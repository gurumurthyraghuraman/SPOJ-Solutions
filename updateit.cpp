#include <stdio.h>

using namespace std;

int arr[100000];

void initializeArr() {
    for (int i = 0; i < 100000; i++) {
        arr[i] = 0;
    }
}


void calcPrefixSum(int n) {
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
}


int main() {
    int t,n,u,q,l,r,val, index;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        initializeArr();
        scanf("%d %d",&n, &u);
        for (int j = 0; j < u; j++) {
            scanf("%d %d %d", &l, &r, &val);
            arr[l] += val;
            if (r < (n - 1))
                arr[r + 1] -= val;
        }
        calcPrefixSum(n);
        scanf("%d", &q);
        for (int k = 0; k < q; k++) {
            scanf("%d", &index);
            printf("%d\n", arr[index]);
        }
    }
    return 0;
}
