#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long root(long long n) {
    long long d;
    d = 1 - 8*n*(-1);
    long long root1 = (-1 + sqrt(d)) / 2 ;
    return root1;

}

vector<unsigned long long> amountOfCoins(long long n, int k) {
    vector<unsigned long long> result;
    long long nthTerm;
    long long noOfTerms;
    long long remCoins;
    long long lastTerm;
    int lastBandit = -1;
    unsigned long long eachRes;
    nthTerm = root(n);
    remCoins = n - (nthTerm * (nthTerm + 1)/2);
    for(int i = 1; i <= k ; i++){
        noOfTerms = (nthTerm - i)/k;
        noOfTerms += 1;
        lastTerm = i + (noOfTerms - 1)*k;
        if(lastTerm == nthTerm) {
            if (i == k) {
                result[0] += remCoins;
            }
            else {
                lastBandit = i + 1;
            }
        }
        eachRes = (noOfTerms * 1.0 / 2)*(2*i + (noOfTerms - 1)*k);
        if(i == lastBandit) {
            eachRes += remCoins;
        }
        result.push_back(eachRes);
    }
    return result;
}


int main() {
    int t,k;
    long long n;
    cin>>t;
    for(int i = 0; i<t; i++) {
        cin>>n>>k;
        vector<unsigned long long> result = amountOfCoins(n,k);
        for(int j = 0; j < result.size(); j++) {
            cout<<result[j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}
