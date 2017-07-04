#include <iostream>
#include <string>

using namespace std;


string halfOfHalf(string strInput) {
    string retString = "";
    if(strInput.length()==0)
        return retString;
    if(strInput.length()<=2){
        retString+=strInput[0];
        return retString;
    }

    int halfLength=strInput.length()/2;
    int i=0;
    while(i<halfLength) {
        retString+=strInput[i];
        i=i+2;
    }
    return retString;

}

int main() {
    int t;
    string strInput;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>strInput;
        cout<<halfOfHalf(strInput)<<endl;
    }
    return 0;
}
