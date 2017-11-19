#include <iostream>
#include <stdio.h>

using namespace std;

int noOfRectangles(int n){
    return n*(n+1)*(2*n+1)/6;
}


int main(){
    int n;
    scanf("%d",&n);
    while(n!=0){
        printf("%d\n",noOfRectangles(n));
        scanf("%d",&n);
    }
    return 0;


}
