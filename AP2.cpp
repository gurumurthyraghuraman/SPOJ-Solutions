#include <iostream>

using namespace std;

long long numberOfTerms(long long thirdTerm, long long thirdLastTerm, long long sumOfTerms) {

    long long n = (2 * sumOfTerms)/ (thirdTerm + thirdLastTerm);

    return n;
}

long long distance(long long diff, long long n) {

    return diff/(n-5);
}

long long firstElement(long long dist, long long thirdTerm) {

    return thirdTerm - 2*dist;
}

void printTerms(long long a, long long d, long long n) {
    cout<<n<<endl;
    for(int i = 0; i < n; i++) {
        cout<<a + i*d<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    long long thirdTerm, thirdLastTerm, sumOfTerms, noOfTerms, dist, firstTerm;
    cin>>t;
    for(int i = 0; i < t ; i++) {
        cin>>thirdTerm>>thirdLastTerm>>sumOfTerms;
        noOfTerms = numberOfTerms(thirdTerm, thirdLastTerm, sumOfTerms);
        dist = distance(thirdLastTerm - thirdTerm, noOfTerms);
        firstTerm = firstElement(dist, thirdTerm);
        printTerms(firstTerm, dist, noOfTerms);
    }
    return 0;
}
