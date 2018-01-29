#include <iostream>
#include <map>

using namespace std;

long long noOfUniqueArrays(long long n, map<int, long long> occurrences) {
    long long subcount = 0;
    long long result = n*(n-1) / 2;
    for (map<int,long long>::iterator it=occurrences.begin(); it!=occurrences.end(); ++it)
        subcount += (it->second) * (it->second - 1) / 2;
    if(subcount == 0)
        return result;
    return result - subcount + 1;

}


int main() {
    int t;
    int temp, subcount;
    long long n;
    map<int, long long> occurrences;
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        subcount = 0;
        occurrences.clear();
        for(int j = 0; j < n; j++) {
            cin>>temp;
            if(occurrences.find(temp)!=occurrences.end()) {
                occurrences[temp] += 1;
            }
            else {
                occurrences[temp] = 1;
            }
        }
        cout<<noOfUniqueArrays(n, occurrences)<<endl;

    }
    return 0;
}
