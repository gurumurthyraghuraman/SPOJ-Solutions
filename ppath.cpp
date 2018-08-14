#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int sieveArr[10000];

void initializeArr() {
    for (int i = 0; i <= 9999; i++) {
        sieveArr[i] = 0;
    }
}

void markPrimes(int p) {
    for (int j = 2*p; j <= 9999; j = j + p) {
        sieveArr[j] = 1;
    }
}

void computeSieveArr() {
    int i = 2;
    for (int i = 2; i <= 100; i++) {
        if (sieveArr[i] == 0) {
            markPrimes(i);
        }
    }
}


vector<int> changeOneDigit(int number) {
    vector<int> retList;
    int fourthDigit = number % 10;
    number = number / 10;
    int thirdDigit = number % 10;
    number = number / 10;
    int secondDigit = number % 10;
    number = number / 10;
    int firstDigit = number % 10;
    number = number / 10;
    for (int i = 0; i <= 9 ; i++) {
        if (i != 0 && i != firstDigit && sieveArr[i*1000 + secondDigit*100 + thirdDigit*10 + fourthDigit] == 0) {
            retList.push_back(i*1000 + secondDigit* 100 + thirdDigit*10 + fourthDigit);
        }
        if (i != secondDigit && sieveArr[firstDigit*1000 + i*100 + thirdDigit*10 + fourthDigit] == 0) {
            retList.push_back(firstDigit*1000 + i*100 + thirdDigit*10 + fourthDigit);
        }
        if (i != thirdDigit && sieveArr[firstDigit*1000 + secondDigit*100 + i*10 + fourthDigit] == 0) {
            retList.push_back(firstDigit*1000 + secondDigit*100 + i*10 + fourthDigit);
        }
        if (i != fourthDigit && sieveArr[firstDigit*1000 + secondDigit*100 + thirdDigit*10 + i] == 0) {
            retList.push_back(firstDigit*1000 + secondDigit*100 + thirdDigit*10 + i);
        }

    }
    return retList;
}


int bfsPrime(int firstPrime, int lastPrime) {
    queue<int> bfsQueue;
    vector<int> changedNums;
    bool visited[10000] = {false};
    int depth = 0;
    bfsQueue.push(firstPrime);
    while (!bfsQueue.empty()) {
        int queueSize = bfsQueue.size();
        for (int i = 0; i < queueSize; i++) {
            int topOfQueue = bfsQueue.front();
            if (!visited[topOfQueue]) {
                if (topOfQueue == lastPrime)
                    return depth;
                changedNums = changeOneDigit(topOfQueue);
                for (int j = 0; j < changedNums.size(); j++) {
                    bfsQueue.push(changedNums[j]);
                }
                visited[topOfQueue] = true;
            }
            bfsQueue.pop();
        }
        depth++;
    }
    return -1;
}

int main() {
    int t;
    int firstPrime, lastPrime;
    int result;
    initializeArr();
    computeSieveArr();
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &firstPrime, &lastPrime);
        result = bfsPrime(firstPrime, lastPrime);
        if (result == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", result);
        }
    }
    return 0;
}
