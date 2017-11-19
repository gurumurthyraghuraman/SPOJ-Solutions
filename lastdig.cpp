#include <stdio.h>

using namespace std;

int lastDigit(int a, int b){
    int arr[4];
    int num;
    num = a;
    if(b == 0)
        return 1;
    if(a == 0)
        return 0;
    for(int i=0;i<4;i++){
        arr[i]=num%10;
        num = num * a;
    }
    if(b%4!=0)
        return arr[(b%4)-1];
    else return arr[3];
}

int main(){
    int t,a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",lastDigit(a,b));
    }

    return 0;



}
