#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int noOfCommonDiv(int a, int b){
    int minNum=min(a,b);
    int result=0;
    for(int i=1;i<=minNum;i++){
        if(a%i==0 && b%i==0){
            result++;
        }
    }
    return result;


}


int main(){
    int t,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",noOfCommonDiv(a,b));

    }
    return 0;


}
