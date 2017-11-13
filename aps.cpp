#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

//int arr[10000001];
long long dpArr[10000001];
int factor[10000001];


void initArray(){
    for(int i=0;i<=10000000;i++){
        //arr[i]=1;
        factor[i]=0;
    }
}

int pickNextElement(int prevIndex, int n){
    for(int i=prevIndex+1;i<=n;i++){
        if(factor[i]==0){
            return i;
        }
    }
    return 0;


}

void computeSieve(int n){
    int startIndex;
    startIndex=2;
    int multiplier,i;
    while(startIndex!=0){
        multiplier=2;
        factor[startIndex]=startIndex;
        i=startIndex*multiplier;
        while(i<=n){
            if(factor[i]==0)
                factor[i]=startIndex;
            multiplier++;
            i=startIndex*multiplier;
        }
        startIndex=pickNextElement(startIndex, n);
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
    initArray();
    maxN=-1;
    minN=10000002;
    dpArr[0]=dpArr[1]=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        testCaseArr[i]=n;
        if(n<minN){
            minN=n;
        }
        if(n>maxN){
            maxN=n;
        }
    }
    computeSieve(maxN);
    sequenceNumber(maxN);
    for(int j=0;j<t;j++)
        printf("%lld\n",dpArr[testCaseArr[j]]);

    return 0;
}
