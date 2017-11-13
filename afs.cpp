#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

long long dpArr[1000001];
long long factor[1000001];


void initArray(){
    for(int i=0;i<=1000001;i++){
        factor[i]=1;

    }
}

void preCal(int n){
    for(int i=2;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            factor[j]+=i;
        }

    }
}



long long sequenceNumber(int n){
    for(int i=2;i<=n;i++){
            dpArr[i]=dpArr[i-1]+factor[i];
    }
    return dpArr[n];
}

int main(){
    int t;
    int testCaseArr[100];
    int n,maxN,minN;
    maxN=-1;
    dpArr[0]=dpArr[1]=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        testCaseArr[i]=n;
        if(n>maxN){
            maxN=n;
        }
    }
    initArray();
    preCal(maxN);
    sequenceNumber(maxN);
    for(int j=0;j<t;j++)
        printf("%lld\n",dpArr[testCaseArr[j]]);

    return 0;
}
