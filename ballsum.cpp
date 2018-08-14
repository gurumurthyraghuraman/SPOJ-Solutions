#include <iostream>

using namespace std;

unsigned long long sumLessThanK(int n, int k) {
    unsigned long long result = 0;
    result = k/2;
    if (k % 2 == 0) {
        result = result * (result - 1);
    } else {
        result = result*result;
    }
    return result;
}

unsigned long long totalNumberOfCombinations(int n, int k) {
    unsigned long long totalNumberOfBalls = n;
    return (totalNumberOfBalls*(totalNumberOfBalls - 1))/2;
}

unsigned long long gcd(unsigned long long numerator, unsigned long long denominator) {
    if (numerator == 0) {
        return denominator;
    }
    if (denominator == 0) {
        return numerator;
    }

    if (numerator < denominator) {
        return gcd(numerator, denominator % numerator);
    }
    return gcd(numerator % denominator, denominator);
}

int main() {
    int n,k;
    unsigned long long numerator, denominator, commonDivisor;
    scanf("%d %d", &n, &k);
    while(n != -1 &&  k != -1) {
        if (k == 0 || k == 1) {
            printf("%d\n",0);
        } else {
            numerator = sumLessThanK(n, k);
            denominator = totalNumberOfCombinations(n, k);
            commonDivisor = gcd(numerator, denominator);
            if (numerator == 0) {
                printf("%d\n",0);
            } else if (numerator == denominator) {
                printf("%d\n", 1);
            } else {
                printf("%llu/%llu\n", numerator/commonDivisor, denominator/commonDivisor);
            }
        }
        scanf("%d %d", &n, &k);
    }

    return 0;
}
