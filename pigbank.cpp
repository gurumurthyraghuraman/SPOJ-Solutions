#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

long calMinimumAmount(int bankWeight,vector<int> &value, vector<int> &weight, int vecSize) {
    long arr[10001];
    for(int i=0;i<10001;i++)
        arr[i]=LONG_MAX;
    arr[0]=0;
    for(int i=1;i<=bankWeight;i++) {
        for(int j=0;j<vecSize;j++) {
            if(weight[j]<=i) {
                if(arr[i-weight[j]]!=LONG_MAX)
                    arr[i]=min(arr[i],arr[i-weight[j]]+value[j]);
            }
        }
    }


    return arr[bankWeight];
}


int main() {
    int t,temp;
    int e,f,n;
    long minValue;
    vector<int> value;
    vector<int> weight;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        value.clear();
        weight.clear();
        scanf("%d",&e);
        scanf("%d",&f);
        scanf("%d",&n);
        for(int j=0;j<n;j++) {
            scanf("%d",&temp);
            value.push_back(temp);
            scanf("%d",&temp);
            weight.push_back(temp);
        }
        minValue=calMinimumAmount(f-e,value,weight,n);
        if(minValue!=LONG_MAX) {
            printf("The minimum amount of money in the piggy-bank is %ld.\n", minValue);
        }
        else {
            printf("This is impossible.\n", minValue);

        }
    }

    return 0;

}
