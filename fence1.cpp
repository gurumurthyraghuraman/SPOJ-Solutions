#include <iostream>
#include <iomanip>

using namespace std;

double maxArea(int n) {
    double r = n/3.14159;
    return (3.14159 * r * r)/2;
}


int main() {
    int n;
    cin>>n;
    while(n != 0) {
        cout<<setprecision(2)<<fixed<<maxArea(n)<<endl;
        cin>>n;
    }
    return 0;
}
