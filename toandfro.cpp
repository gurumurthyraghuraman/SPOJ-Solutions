#include <iostream>
#include <string>

using namespace std;

string originalMessage(string inputString,int n){
    string strResMessage;
    int i,j,k,p,strLength;
    strLength = inputString.length();
    i=1;
    j=2*n-i;
    k=1;
    while(i<=n){
        p=i;
        while(p<=strLength){
            strResMessage+=inputString[p-1];
            p+=j;
            if(p<=strLength){
                strResMessage+=inputString[p-1];
                p+=k;
            }
        }
        i++;
        j=j-2;
        k=k+2;

    }
    return strResMessage;

}


int main(){
    int n;
    string inputString;
    cin>>n;
    while(n!=0){
        cin>>inputString;
        cout<<originalMessage(inputString,n)<<endl;
        cin>>n;
    }

    return 0;
}
