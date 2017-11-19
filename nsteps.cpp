#include <iostream>
#include <stdio.h>

using namespace std;

int returnPoint(int x, int y){
    if(x == y || y == x - 2){
        if(x%2==0 && y%2==0)
            return x + y;
        return x + y- 1;
    }
    return -1;

}


int main(){
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        if(returnPoint(x,y)==-1){
            printf("No Number\n");
        }
        else printf("%d\n",returnPoint(x,y));

    }
    return 0;


}
