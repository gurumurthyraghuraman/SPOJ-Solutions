#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long dpArr[1000010];
unsigned long long ansArr[1000010];

void preCal(){
    dpArr[0]=0;
    ansArr[0]=0;
    for(long long i=1;i<1000010;i++){
        dpArr[i]=(dpArr[i-1]+i*i*i)%1000000003;
        ansArr[i]=(ansArr[i-1]+dpArr[i])%1000000003;
    }


}



int main(){
    int t,n;
    preCal();
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        printf("%llu\n",ansArr[n]);
    }


    return 0;
}
