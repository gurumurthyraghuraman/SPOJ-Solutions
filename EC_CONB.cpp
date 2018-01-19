#include <iostream>

using namespace std;

int reverseNum(int a) {
    int revNum = 0;
    while(a != 0) {
        revNum = revNum << 1;
        if(a % 2 == 1) {
            revNum += 1;
        }
        a = a >> 1;
    }
    return revNum;

}


int main() {
    int n, a;
    cin>>n;
    for(int i = 0; i < n ; i++) {
        cin>>a;
        if(a % 2 == 0) {
            cout<<reverseNum(a)<<endl;
        }
        else {
            cout<<a<<endl;

        }
    }
    return 0;


}
