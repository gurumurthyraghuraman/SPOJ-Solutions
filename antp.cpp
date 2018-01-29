#include <iostream>
#include <stdio.h>

using namespace std;

long long arr[1000001];
long long arr2[1000001];

void noOfWays() {
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 1;
    arr2[3] = 1;
    int j = 2;
    for(int i = 4; i <= 1000000; i++) {
        arr2[i] = arr2[i-1] + j;
        arr[i] = arr2[i] + arr[i-1];
        j++;
    }

}



int main() {
    int t,x,y;
    long long result;
    noOfWays();
    scanf("%d", &t);
    for(int i = 0; i<t; i++) {
        result = 0;
        scanf("%d %d",&x, &y);
        result = (arr[y] - arr[x-1]) % 1000000007;
        cout<<result<<endl;
    }
    return 0;
}
