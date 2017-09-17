#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> positionOfPattern(string inputStr, string pattern){
    int inputLen=inputStr.length();
    int patternLen=pattern.length();
    vector<int> lps;
    vector<int> result;
    lps.push_back(0);
    int i=1;
    int j=0;
    int prefixLen=0;
    while(i<patternLen){
        if(pattern[i]==pattern[j]){
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
            else{
                j=lps[lps[j-1]];
                prefixLen=j;

            }

        }

    }
    //cout<<lps[0]<<lps[1]<<endl;

    i=0;
    j=0;
    while(i<inputLen){
        if(inputStr[i]==pattern[j]){
            i++;
            j++;
            if(j==patternLen){
                result.push_back(i-j+1);
                j=lps[j-1];
            }

        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }

        }
    }
    return result;


}

int main(){
    int t;
    string inputStr,pattern;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>inputStr>>pattern;
        vector<int> result=positionOfPattern(inputStr,pattern);
        if(result.size()==0)
            cout<<"Not Found"<<endl;
        else{
            cout<<result.size()<<endl;
            for(int j=0;j<result.size();j++)
                if(j!=result.size()-1)
                    cout<<result[j]<<" ";
                else cout<<result[j]<<endl;

        }
        cout<<endl;

    }
    return 0;
}
