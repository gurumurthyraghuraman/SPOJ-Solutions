#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    unsigned long long sum=0;
    int eachNum;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>eachNum;
            sum+=eachNum;
        }
        if(sum%n==0)
            cout<<n<<endl;
        else{
            cout<<n-1<<endl;
        }
    }
    return 0;

}
