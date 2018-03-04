#include <iostream>

using namespace std;

int noOfRectangles(int n) {
    int noOfRect = n;
    for (int i = 2; i <= n/2; i++) {
        if (n/i - (i - 1) > 0)
            noOfRect += n/i - (i - 1);
        else {
            return noOfRect;
        }
    }
    return noOfRect;
}



int main () {
    int n;
    cin>>n;
    cout<<noOfRectangles(n)<<endl;
    return 0;

}
