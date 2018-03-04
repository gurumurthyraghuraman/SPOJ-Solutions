#include <iostream>
#include <iomanip>

using namespace std;

double expectedNumberOfThrows(int n) {
    double ans = 1;
    for(int i = n - 1; i >= 1; i--) {
        ans += 1.0/(i*1.0/n);
    }
    return ans;
}



int main() {
    int t,n;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>n;
        cout<<setprecision(2)<<fixed<<expectedNumberOfThrows(n)<<endl;

    }

}
