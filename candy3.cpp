#include <iostream>

using namespace std;

int main() {
    long long t,n,sum;
    long long noOfCandies;
    cin>>t;
    for (long long i = 0; i < t; i++) {
        cin>>n;
        sum = 0;
        for(long long j = 0; j < n; j++) {
            cin>>noOfCandies;
            sum = (sum % n + noOfCandies % n) % n;
        }
        if (sum % n == 0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}
