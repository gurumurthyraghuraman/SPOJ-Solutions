#include <iostream>

using namespace std;

long long noOfSeconds(long long n, long long k, long long m) {

    long long time = 0;
    long long atomsEmitted;
    if (k <= m/n) {
        time++;
        atomsEmitted = n*k;
        while(k <= m/atomsEmitted) {
            time++;
            atomsEmitted *= k;
        }
    }
    return time;
}


int main() {
    int p;
    long long n,k,m;
    cin>>p;
    for (int i = 0; i < p; i++) {
        cin>>n>>k>>m;
        cout<<noOfSeconds(n,k,m)<<endl;
    }
    return 0;
}
