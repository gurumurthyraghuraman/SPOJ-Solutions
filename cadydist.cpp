#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


unsigned long long minAmount(vector<int> students, vector<int> price, int n){
    unsigned long long result=0;
    unsigned long long eachClass;
    unsigned long long eachPrice;
    sort(students.begin(),students.end());
    sort(price.begin(),price.end());
    for(int i=0;i<n;i++){
        eachClass=students[n-1-i];
        eachPrice=price[i];
        result+=eachClass*eachPrice;
    }
    return result;


}

int main(){
    vector<int> students;
    vector<int> price;
    int n,temp;
    scanf("%d",&n);
    while(n!=0){
        students.clear();
        price.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            students.push_back(temp);
        }
        for(int j=0;j<n;j++){
            scanf("%d",&temp);
            price.push_back(temp);
        }
        printf("%llu\n",minAmount(students,price,n));
        scanf("%d",&n);
    }


    return 0;
}
