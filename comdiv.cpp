#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int sieveArr[1000001];

void printSieveArr() {
    for (int i = 2; i <= 1000000; i++) {
        if (sieveArr[i] == -1) {
            cout<<i<<endl;
            break;
        }
    }
}

void initializeSieveArr() {
    for (int i = 0; i <= 1000000; i++) {
        sieveArr[i] = -1;
    }
}

void markAllValues(int p) {
    for (int i = p; i <= 1000000; i += p) {
        if (sieveArr[i] == -1)
            sieveArr[i] = p;
    }
}

int computeSieve() {
    int maxValue = sqrt(1000000);
    for (int i = 2; i <= maxValue + 1; i++) {
        if (sieveArr[i] == -1)
            markAllValues(i);
    }

}



int gcd(int a, int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a >= b) {
        return gcd(a % b, b);
    }
    return gcd(a, b % a);
}


int noOfCommonFactors(int num1, int num2) {
    int totalNumberOfFactors = 0;
    int hcf = gcd(num1, num2);
    /*if (hcf == 1)
        return 1;
    int factors = 1;
    int nextFactor = hcf / sieveArr[hcf];
    int c = 1;
    int dup = sieveArr[hcf];
    while (nextFactor != 1) {
        if (dup == sieveArr[nextFactor]) {
            c++;
        } else {
            factors *= (c + 1);
            c = 1;
            dup = sieveArr[nextFactor];
        }
        if (sieveArr[nextFactor] != -1)
            nextFactor = nextFactor / sieveArr[nextFactor];
        else nextFactor = 1;
    }
    return factors*(c + 1);
    */
    int sqrtHcf = sqrt(hcf);
    for (int i = 1; i <= sqrtHcf; i++) {
        if (hcf % i == 0) {
            if (i == hcf /i)
                totalNumberOfFactors++;
            else totalNumberOfFactors += 2;
        }
    }
    return totalNumberOfFactors;
}


int main() {
    int n;
    int num1,num2;
    scanf("%d", &n);
    //initializeSieveArr();
    //computeSieve();
    //printSieveArr();
    for (int i = 0; i < n; i++) {
        scanf("%d %d",&num1, &num2);
        printf("%d\n", noOfCommonFactors(num1, num2));
    }
    return 0;
}
