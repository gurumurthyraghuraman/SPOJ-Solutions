#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> primesUptoSqrt(int largeNum){
    if(largeNum<=1)
        return vector<int>();


    vector<bool> flags(largeNum+1,false);
    vector<int> primes;
    int sqrtNum = sqrt(largeNum);
    primes.push_back(2);
    //cout<<"Entered Method"<<endl;
    for(int i=3;i<=sqrtNum; i=i+2) {
        if(i<=sqrtNum && !flags[i]) {
            primes.push_back(i);
            for(int j=i*i; j<=largeNum;j=j*i) {
                if(j<=largeNum)
                    flags[j]=true;
            }
        }
    }
    for(int k=3;k<=largeNum;k=k+2){
        if(k<=largeNum && !flags[k]) primes.push_back(k);
    }
    return primes;
}

vector<int> getPrimes(int m, int n){
    if(m==1 && n==1) {
        return vector<int>();
    }
    int sqrtNum=sqrt(n);
    vector<int> allPrimes;
    vector<bool>flags(n-m+1, false);
    vector<int> primesSqrtN=primesUptoSqrt(sqrtNum);
    //cout<<"Sqrt Size"<<primesSqrtN.size()<<endl;
    int qForM;
    if(m==1) flags[0]=true;
    for(int i=0; i<primesSqrtN.size();i++) {
        qForM=m/primesSqrtN[i];
        for(int j=primesSqrtN[i]*qForM;j<=n;j=j+primesSqrtN[i]) {
            if(j>=m && j<=n && j!=primesSqrtN[i]) {
                flags[j-m]=true;
            }
        }
    }
    if(m<=2 && n>=2) allPrimes.push_back(2);
    if(m%2==0) {
        for(int k=1;k<flags.size();k=k+2){
            if(k<flags.size() && !flags[k])
                allPrimes.push_back(m+k);
        }
    }
    else{
        for(int k=0;k<flags.size();k=k+2){
            if(k<flags.size() && !flags[k])
                allPrimes.push_back(m+k);
        }
    }
    return allPrimes;

}
int main() {
    int noOfTestCases;
    int m;
    int n;
    vector<int> primeVector;
    cin>>noOfTestCases;
    for(int i=0;i<noOfTestCases;i++){
        cin>>m>>n;
        primeVector=getPrimes(m,n);
        for(int j=0;j<primeVector.size();j++)
            cout<<primeVector[j]<<endl;
        cout<<endl;
    }
    return 0;
}
