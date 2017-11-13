#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>

using namespace std;

char specialChar(vector<string> arrWords){
    int arr[26]={0};
    int maxVal=-1;
    char specialChar;
    for(int i=0;i<arrWords.size();i++) {
        for(int j=0;j<arrWords[i].length();j++){
            arr[arrWords[i][j]-'a']++;
            if(arr[arrWords[i][j]-'a']>maxVal){
                maxVal = arr[arrWords[i][j]-'a'];
                specialChar = arrWords[i][j];
            }
        }
    }
    return specialChar;
}

bool spclCharOccurrences(string strWord, char spclChar){
    int resCharOcc=0;
    int arr[26]={0};
    int maxVal=-1;
    for(int i=0;i<strWord.length();i++){
        arr[strWord[i]-'a']++;
        if(arr[strWord[i]-'a'] > maxVal)
	maxVal = arr[strWord[i]-'a'];
    }
    for(int i=0;i<26;i++){
    	if(i!=spclChar-'a' && arr[i]==maxVal)
    		return false;
    }
    if(arr[spclChar - 'a'] == maxVal )
	return true;
    return false;

}

vector<string> specialWords(vector<string> arrWords){
    char spclChar = specialChar(arrWords);
    vector<string> result;
    for(int i=0;i<arrWords.size();i++){
        if(spclCharOccurrences(arrWords[i],spclChar)){
            result.push_back(arrWords[i]);
        }
    }

    return result;

}


int main(){
    int t;
    string eachLine;
    vector<string> arrWords;
    vector<string> spclWords;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        arrWords.clear();
        spclWords.clear();
        getline(cin,eachLine);
        istringstream iss(eachLine);
        for(string eachWord; iss >> eachWord; )
            arrWords.push_back(eachWord);
        spclWords = specialWords(arrWords);
        cout<<"Case #"<<i+1<<":"<<endl;
        for(int j=0;j<spclWords.size();j++){
            cout<<spclWords[j]<<endl;
        }

    }
    return 0;

}
