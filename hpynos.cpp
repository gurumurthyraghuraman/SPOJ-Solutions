#include <iostream>
#include <unordered_map>

using namespace std;



int numAfterBreaking(int n) {
    int squaredSum = 0;
    int digit;
    while (n) {
        digit = n % 10;
        squaredSum += digit*digit;
        n = n  / 10;
    }
    return squaredSum;

}


int main() {
    int n;
    int squaredSumNum;
    int ans = 0;
    unordered_map <int, bool> visitedNums;
    cin>>n;
    visitedNums[n] = true;
    squaredSumNum = n;
    while (1) {
        squaredSumNum = numAfterBreaking(squaredSumNum);
        //cout<<squaredSumNum<<endl;
        ans++;
        if (squaredSumNum == 1){
            break;
        }
        if (visitedNums.find(squaredSumNum) != visitedNums.end()) {
            ans = -1;
            break;
        }
        visitedNums[squaredSumNum] = true;
    }
    cout<<ans<<endl;
    return 0;
}
