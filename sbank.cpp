#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(map<string, int> mapAccountNumberCount) {
    for (map<string,int> :: iterator it = mapAccountNumberCount.begin(); it != mapAccountNumberCount.end(); it++) {
        cout<<it -> first<< " "<<it -> second<<endl;
    }
}


int main() {
    int t,n;
    string inputStr;
    map<string, int> mapAccountNumberCount;
    getline(cin, inputStr);
    t = stoi(inputStr);
    for (int i = 0; i < t; i++) {
        mapAccountNumberCount.clear();
        getline(cin, inputStr);
        n = stoi(inputStr);
        for (int j = 0; j < n; j++) {
            getline(cin, inputStr);
            if (mapAccountNumberCount.find(inputStr) != mapAccountNumberCount.end()) {
                mapAccountNumberCount[inputStr] += 1;
            } else {
                mapAccountNumberCount[inputStr] = 1;
            }
        }
        printMap(mapAccountNumberCount);
        cout<<endl;
        getline(cin,inputStr);
    }
    return 0;
}
