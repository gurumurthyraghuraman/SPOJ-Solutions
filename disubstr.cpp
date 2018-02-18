#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


vector<string> generateSuffixArray(string inputStr) {
    int n = inputStr.length();
    vector<string> result;
    for (int i = 0; i < n; i++) {
        result.push_back(inputStr.substr(i, n - i));
    }
    sort(result.begin(), result.end());
    return result;
}

int lcp(string str1, string str2) {
    if (str1.length() == 0 || str2.length() == 0)
        return 0;
    int i = 0;
    while (str1[i] == str2[i]) {
        i++;
    }
    return i;
}

int noOfDistinctSubstrings(string inputStr) {
    int distinctSubStrings;
    vector<string> suffixes = generateSuffixArray(inputStr);
    distinctSubStrings = suffixes[0].length();
    for (int i = 1; i < suffixes.size(); i++) {
        distinctSubStrings += suffixes[i].length() - lcp(suffixes[i-1], suffixes[i]);
    }
    return distinctSubStrings;
}


int main() {
    int t;
    string inputStr;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>inputStr;
        cout<<noOfDistinctSubstrings(inputStr)<<endl;
    }
    return 0;
}
