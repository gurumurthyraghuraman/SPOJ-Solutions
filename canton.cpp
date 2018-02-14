#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> findStartNumber(int num) {
    vector<int> result;
    int maxNum = (-1 + sqrt(1 + 8*num))/2;

    int startNum = maxNum*(maxNum+1)/2.0;
    result.push_back(maxNum);
    result.push_back(startNum);
    return result;
}

vector<int> numeratorDenominator(vector<int> startAndMaxNum, int n) {
    vector<int> result;
    int startNum = startAndMaxNum[1];
    int maxNum = startAndMaxNum[0];
    int denominator,numerator;
    if (n > startNum) {
        maxNum++;
    }
    else {
        startNum = (maxNum - 1)*maxNum/2.0;
    }
    if(maxNum % 2 == 0) {
        denominator = maxNum;
        numerator = 1;
    } else {
        denominator = 1;
        numerator = maxNum;
    }
    if (maxNum % 2 == 0) {
        for (int i = startNum+1; i < n; i++) {
            denominator--;
            numerator++;
        }
    } else {
        for (int i = startNum+1; i < n; i++) {
            denominator++;
            numerator--;
        }
    }

    result.push_back(numerator);
    result.push_back(denominator);
    return result;
}

int main() {
    int t,n,startNumber;
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        vector<int> maxAndStartNum = findStartNumber(n);
        vector<int> result = numeratorDenominator(maxAndStartNum, n);
        cout<<"TERM "<<n<<" IS "<<result[0]<<"/"<<result[1]<<endl;
    }
    return 0;
}
