#include <iostream>
#include <string>

using namespace std;


void initializeCharCount(int charCount[4]){
    for(int i=0;i<4;i++)
        charCount[i]=1;
}

string lastRow(int n, string strRow1){
    int charCount[4];
    initializeCharCount(charCount);
    //int noOfColumns=2*n;
    string result;
    string parRes;
    //divide string 1 into parts of size 2
    for(int i=0;i<=(2*n-2);i=i+2){
        for(int j=i;j<i+2;j++){
            charCount[strRow1[j]-'A']--;
        }
        for(int k=0;k<4;k++){
            if(charCount[k]==1) {
                parRes+=('A'+k);
            }
        }
        if(result.length()==0){
            result+=parRes[0];
            result+=parRes[1];
        }
        else{
            if(result[result.length()-1]==parRes[0]){
                result+=parRes[1];
                result+=parRes[0];
            }
            else{
                result+=parRes[0];
                result+=parRes[1];
            }

        }
        initializeCharCount(charCount);
        parRes="";
    }
    return result;
}


int main(){
    int n;
    string strRow1,strRow2;
    cin>>n;
    cin>>strRow1;
    cout<<lastRow(n,strRow1)<<endl;
    return 0;
}
