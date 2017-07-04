#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int noOfTuples(vector<int> &lhs, vector<int> &rhs) {
    int i,j,k;
    int totalCount=0;
    i=j=0;
    vector<int>::iterator lBegin=lhs.begin();
    vector<int>::iterator rBegin=rhs.begin();
    vector<int>::iterator upperBound,lowerBound;
    int lhsCount,rhsCount;
    int lhsSize=lhs.size();
    while(i<lhsSize) {
        lowerBound=lower_bound(lhs.begin()+i,lhs.end(),lhs[i]);
        upperBound=upper_bound(lhs.begin()+i,lhs.end(),lhs[i]);
        lhsCount=(upperBound-lBegin)-(lowerBound-lBegin);
        k=(upperBound-lBegin);
        lowerBound=lower_bound(rhs.begin(),rhs.end(),lhs[i]);
        upperBound=upper_bound(rhs.begin(),rhs.end(),lhs[i]);
        i=k;
        if(lowerBound!=upperBound) {
            j=(upperBound-rBegin);
            rhsCount=(upperBound-rBegin)-(lowerBound-rBegin);
            totalCount+=lhsCount*rhsCount;
        }
    }
    return totalCount;
}


int main() {
    int N,tempInput;
    vector<int> input, arr1, arr2;
    scanf("%d",&N);
    for(int i=0;i<N;i++) {
        scanf("%d",&tempInput);
        input.push_back(tempInput);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++) {
                arr1.push_back(input[i]*input[j]+input[k]);
                if(input[i]!=0)
                    arr2.push_back(input[i]*(input[j]+input[k]));
            }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    printf("%d\n",noOfTuples(arr1,arr2));

    return 0;

}
