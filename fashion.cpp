#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int sumOfBonds(vector<int> men, vector<int> women, int n){
    int sum = 0;
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    for(int i = 0; i < n; i++){
        sum+=men[i]*women[i];
    }
    return sum;
}

int main(){
    vector<int> men;
    vector<int> women;
    int n,rating,t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        men.clear();
        women.clear();
        for(int j=0;j<n;j++){
            scanf("%d",&rating);
            men.push_back(rating);

        }
        for(int k=0;k<n;k++){
            scanf("%d",&rating);
            women.push_back(rating);

        }
        printf("%d\n",sumOfBonds(men,women,n));

    }
    return 0;
}
