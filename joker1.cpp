#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


unsigned long long joker1(vector<int> vectMaxNums) {
    unsigned long long noOfPerm = 1;
    sort(vectMaxNums.begin(), vectMaxNums.end());
    for(int i = 0; i < vectMaxNums.size(); i++) {
            noOfPerm = (noOfPerm * (vectMaxNums[i] - i)) % 1000000007;

    }
    return noOfPerm;
}


int main() {
    int t, n, maxNum, temp;
    vector<int> vectMaxNums;
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        vectMaxNums.clear();
        for(int j = 0; j < n; j++) {
            cin>>temp;
            vectMaxNums.push_back(temp);
        }
        cout<<joker1(vectMaxNums)<<endl;
    }
    cout<<"KILL BATMAN"<<endl;
    return 0;
}


