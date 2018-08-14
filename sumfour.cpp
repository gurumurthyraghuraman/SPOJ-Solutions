#include <iostream>
#include <algorithm>

using namespace std;

int numberList[4000][4];
int firstSecondColumnSum[16000000];
int thirdFourthColumnSum[16000000];


int findFrequency(int index, int maxIndex, int arrayNum) {
    int freq = 1;

    if (arrayNum == 1) {
        while(index + 1 < maxIndex && firstSecondColumnSum[index + 1] == firstSecondColumnSum[index]) {
            freq++;
            index++;
        }
    }
    else {
        while(index - 1 >= 0 && thirdFourthColumnSum[index - 1] == thirdFourthColumnSum[index]) {
            freq++;
            index--;
        }
    }
    return freq;
}



int zeroSumValues(int n) {
    int retValue = 0;
    int index = 0;
    int freq1, freq2;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            firstSecondColumnSum[index] = numberList[i][0] + numberList[j][1];
            thirdFourthColumnSum[index] = numberList[i][2] + numberList[j][3];
            index++;
        }
    }

    sort(firstSecondColumnSum, firstSecondColumnSum + index);
    sort(thirdFourthColumnSum, thirdFourthColumnSum + index);

    int p,q, sum;
    p = 0;
    q = index - 1;
    while(p < index && q >= 0) {
        sum = firstSecondColumnSum[p] + thirdFourthColumnSum[q];
        if (sum == 0) {
            freq1 = findFrequency(p, index, 1);
            freq2 = findFrequency(q, index, 2);
            retValue += freq1*freq2;
            p += freq1;
            q -= freq2;
        } else if (sum > 0){
            q--;
        } else {
            p++;
        }
    }
    return retValue;
}



int main() {
    int a,b,c,d,n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d",&a, &b, &c, &d);
        numberList[i][0] = a;
        numberList[i][1] = b;
        numberList[i][2] = c;
        numberList[i][3] = d;
    }
    printf("%d\n", zeroSumValues(n));
    return 0;
}
