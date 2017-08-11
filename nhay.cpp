#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> matchedIndexes(string needle, string hayStack,int needleLen){
    vector<int> lps;
    vector<int> resultVector;
    //int needleLen=needle.length();
    int hayStackLen=hayStack.length();
    if(needleLen>hayStackLen)
        return resultVector;
    int j=0;
    int i=1;
    int prefixLen=0;
    lps.push_back(0);
    while(i<needleLen){
        if(needle[i]==needle[j]){
            i++;
            j++;
            prefixLen++;
            lps.push_back(prefixLen);
        }
        else{
            if(j==0){
                i++;
                lps.push_back(prefixLen);
            }
            else {
                j=lps[lps[j-1]];
                prefixLen=j;
            }
        }

    }
    i=0;
    j=0;
    while(i<hayStackLen){
        if(hayStack[i]==needle[j]){
            i++;
            j++;
            if(j==needleLen){
                resultVector.push_back(i-j);
                j=lps[j-1];
            }
        }
        else{
            if(j==0)
                i++;
            else
                j=lps[j-1];

        }

    }
    return resultVector;

}



int main(){
    int n;
    string needle,hayStack;
    while(cin>>n){
        cin>>needle>>hayStack;
        vector<int> result=matchedIndexes(needle,hayStack,n);
        for(int k=0;k<result.size();k++)
            cout<<result[k]<<endl;
        cout<<endl;


    }
    return 0;
}
