#include <iostream>

using namespace std;

int main() {
    int t,n, eachCoke;
    long long sum;
    long long reqdCoke;
    cin>>t;
    for(int i = 0; i < t; i++) {
        sum = 0;
        reqdCoke = 0;
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>eachCoke;
            sum += eachCoke;
            if (sum <= 0) {
                reqdCoke += 1 + sum*-1;
                sum = 1;
            }
        }
        if (reqdCoke == 0)
            reqdCoke = 1;
        cout<<"Scenario #"<<i+1<<": "<<reqdCoke<<endl;
    }

    return 0;
}
