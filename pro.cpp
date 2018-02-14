#include <iostream>
#include <queue>
#include <set>

using namespace std;

multiset<long long> billList;



int main() {
    int t,n;
    long long bill, result;
    multiset<long long>::iterator itStart,itEnd;

    result = 0;
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        for(int j = 0; j < n; j++) {
            cin>>bill;
            billList.insert(bill);
        }
        itStart = billList.begin();
        itEnd = billList.end();
        itEnd--;
        result += (*itEnd - *itStart);
        billList.erase(itStart);
        billList.erase(itEnd);
    }
    cout<<result<<endl;

    return 0;
}
