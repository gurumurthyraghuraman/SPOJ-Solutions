#include <iostream>
#include <string>

using namespace std;


bool isUpper(char c){
        if(c>='A' && c<='Z')
            return true;
        return false;

}

/*bool isLower(char c){
        if(c>='a' && c<='z')
            return true;
        return false;
}*/


int eDist(string inStr){
    if(inStr.length()==0 || inStr.length()==1)
            return 0;
    bool prev;
    int dist=0;
    int dist2=1;
    prev=isUpper(inStr[0]);
    for(int i=1;i<inStr.length();i++){
        if(prev==isUpper(inStr[i])){
            dist++;
        }
        prev=!prev;
    }
    prev=!isUpper(inStr[0]);
    for(int i=1;i<inStr.length();i++){
        if(prev==isUpper(inStr[i])){
            dist2++;
        }
        prev=!prev;
    }
    if(dist<dist2)
        return dist;
    return dist2;
}


int main(){

    string inputStr;
    while(cin>>inputStr){
        cout<<eDist(inputStr)<<endl;
    }
    return 0;
}
