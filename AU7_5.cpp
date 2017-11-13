#include <iostream>

using namespace std;


unsigned long long noOfPermutations(int n, int k){
    if(k>=n){
        return 0;
    }
    unsigned long long ans=0;
    int endPos;
    for(int i=2;i<=n;i++){
        endPos=1+(k+1)*(i-1);
        if(endPos>n)
            break;
        else{
            ans=ans + 1 + (n-endPos)*(n-endPos+1)*(i-1)/2;

        }

    }
    return ans+noOfPermutations(n,k+1);

}

int main(){
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        cout<<(noOfPermutations(n,k)+n+1)%5000011<<endl;
    }
    return 0;
}
