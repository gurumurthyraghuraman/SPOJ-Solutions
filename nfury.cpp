#include <iostream>
#include <vector>
using namespace std;

int dpArr[1001];
vector<int> squaredList;

void preComputation() {
    for(int i = 1; i*i <=1000; i++) {
        squaredList.push_back(i*i);
    }

}

void initialize() {
    for(int k = 2; k <=1000; k++) {
        dpArr[k] = 1001;
    }

}

void minPieces() {
    dpArr[0] = 0;
    dpArr[1] = 1;
    for(int i = 2; i <= 1000; i++) {
        for(int j =0; j < squaredList.size(); j++) {
            if (i - squaredList[j] >= 0) {
                dpArr[i] = min(dpArr[i], 1 + dpArr[i - squaredList[j]]);

            }
            else {
                break;
            }

        }

    }

}

int main() {
    int t,n;
    initialize();
    preComputation();
    minPieces();
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        cout<<dpArr[n]<<endl;

    }
    return 0;
}
