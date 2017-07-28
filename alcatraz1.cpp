#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(string s){
    int n=s.length();
    int result=0;
    for(int i=0;i<n;i++) {
        result+=s[i]-'0';
    }
    return result;

}


int main() {
    string s;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<sumOfDigits(s)<<endl;
    }
    return 0;
}
