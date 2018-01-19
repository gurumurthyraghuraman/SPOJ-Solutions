#include <iostream>

using namespace std;

bool oddEvenBits(long long p, int k) {
    long long oddBits, evenBits, digCount;
    digCount = oddBits = evenBits = 0;
    while(p!=0) {
        if(p%2 == 1) {
            if(digCount % 2 == 0) {
                oddBits++;
            }
            else{
                evenBits++;

            }

        }
        digCount++;
        p = p >> 1;
    }

    if(evenBits - oddBits == k || oddBits - evenBits == k)
        return true;

    return false;
}


int main() {
    int t,k,ans;
    cin>>t;
    long long m,n;

    for(int i = 0; i < t; i++){
        cin>>m>>n>>k;
        ans = 0;
        for(long long j = m; j <=n ; j++) {
            if(oddEvenBits(j, k)) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
