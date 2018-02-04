#include <iostream>
#include <unordered_map>
#include <string>


using namespace std;

string subseqPermutation(string a, string b) {
    int mapB[256] = {0};
    string result;
    unordered_map<char, int> charCount;
    for(int i = 0; i < a.length(); i++) {
        if (charCount.find(a[i]) != charCount.end()) {
            charCount[a[i]] += 1;
        }
        else {
            charCount[a[i]] = 1;
        }
    }

    for(int j = 0; j < b.length(); j++) {
        if (charCount.find(b[j]) != charCount.end() && charCount[b[j]] > 0) {
            mapB[b[j] - 'a'] += 1;
            charCount[b[j]] -= 1;
        }
    }
    for (int k = 0; k < 256; k++) {
        while(mapB[k]) {
            result += ('a' + k);
            mapB[k] --;
        }
    }
    return result;
}

int main() {
    string a,b;
    while(cin>>a) {
        cin>>b;
        cout<<subseqPermutation(a,b)<<endl;

    }


}
