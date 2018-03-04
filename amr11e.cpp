#include <iostream>


using namespace std;

int sieveArr[2701] = {0};
int luckyNumbers[1000];

void generateLuckyNumbers() {
    int j = 0;
    for (int i = 30; i <= 2700; i++) {
        if (sieveArr[i] >= 3) {
            luckyNumbers[j] = i;
            j++;
        }
        if (j == 1000)
            break;
    }
}

void markAllValues(int primeNum) {
    for (int i = primeNum; i <= 2700; i += primeNum) {
        sieveArr[i]++;
    }
}

void computeSieve() {
    for (int i = 2; i <= 2700; i++) {
        if (sieveArr[i] == 0) {
            markAllValues(i);
        }
    }
}


int main() {
    int t,n;
    scanf("%d",&t);
    computeSieve();
    for (int i = 0; i < t; i++) {
        scanf("%d",&n);
        generateLuckyNumbers();
        cout<<luckyNumbers[n-1]<<endl;
    }
    return 0;
}
