#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string inputStr) {
    int inputLen = inputStr.length();
    for (int i = 0; i <= inputLen/2; i++) {
        if (inputStr[i] != inputStr[inputLen -1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string inputString;
    int t;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>inputString;
        if (isPalindrome(inputString)) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}
