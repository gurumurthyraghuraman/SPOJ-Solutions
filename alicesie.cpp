#include <iostream>
#include <vector>

using namespace std;

int sieveResults[1000001];

void initializeResults() {
    sieveResults[0] = sieveResults[1] = 0;
    sieveResults[2] = 1;
    int i;
    int ans = 2;
    i = 3;
    while (i < 1000001) {
        for (int k = 0; k < 2; k++) {
            sieveResults[i] = ans;
            i++;
        }
        ans++;
    }
}

int main() {
    int t,n;
    cin>>t;
    initializeResults();
    for (int i = 0; i < t; i++) {
        cin>>n;
        cout<<sieveResults[n]<<endl;
    }
    return 0;
}
