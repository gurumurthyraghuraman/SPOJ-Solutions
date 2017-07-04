#include <iostream>
#include <string>

using namespace std;

bool isWithin26(char first, char second) {
    if(first=='1' || (first=='2' && second<='6'))
        return true;
    return false;

}

unsigned long long noOfDecodings(string strIn){
    unsigned long long dpArr[5001];
    dpArr[0]=dpArr[1]=1;
    int strSize=strIn.size();
    for(int i=1;i<strSize;i++){
        if(strIn[i]!='0' && isWithin26(strIn[i-1],strIn[i])){
            dpArr[i+1]=dpArr[i]+dpArr[i-1];
        }
        else if(strIn[i]=='0' && (strIn[i-1]=='0' || strIn[i-1]>'2')){
            return 0;
        }
        else if(strIn[i]=='0'){
                if(i-1>=0){
                    dpArr[i+1]=dpArr[i-1];
                }
                else dpArr[i+1]=dpArr[i];
        }
        else dpArr[i+1]=dpArr[i];
    }
    return dpArr[strSize];
}




int main() {
    string strInput;
    cin>>strInput;
    while(strInput[0]!='0' || strInput.size()!=1){
        if(strInput[0]=='0')
            cout<<0<<endl;
        else cout<<noOfDecodings(strInput)<<endl;
        cin>>strInput;
    }
    return 0;
}
