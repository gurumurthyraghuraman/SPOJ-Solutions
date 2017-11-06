#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n,ans;
    cin>>n;
    while(n!=0){
        ans=log2(n);
        cout<<ans<<endl;
        cin>>n;
    }


    return 0;
}
