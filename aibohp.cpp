#include <iostream>
#include <string>

using namespace std;

int dpArr[6100][6100];

int charsToBeAdded(string inputStr) {
    int inputLen = inputStr.length();
    for (int i = 0; i < inputLen; i++) {
        for (int j = 0; j < inputLen; j++) {
            if (i >= j) {
                dpArr[i][j] = 0;
            }
        }
    }
    int noOfCells = inputLen - 1;
    int oldQ = 1;
    int p = 0;
    int q = 1;
    while (noOfCells) {
        for (int i = 0; i < noOfCells; i++) {
            if (inputStr[p] == inputStr[q]) {
                dpArr[p][q] = dpArr[p+1][q-1];
            }
            else {
                dpArr[p][q] =  1 + min(dpArr[p + 1][q], dpArr[p][q - 1]);
            }
            p++;
            q++;
        }
        noOfCells--;
        q = oldQ + 1;
        oldQ++;
        p = 0;
    }
    return dpArr[0][inputLen - 1];

}



/*int charsToBeAdded(string inputStr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return 0;
    }
    if (inputStr[startIndex] == inputStr[endIndex]) {
        return charsToBeAdded(inputStr, startIndex + 1, endIndex - 1);
    }
    return 1 + min(charsToBeAdded(inputStr, startIndex + 1, endIndex), charsToBeAdded(inputStr, startIndex, endIndex - 1));
}*/


int main() {
    int t;
    string inputStr;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>inputStr;
        cout<<charsToBeAdded(inputStr)<<endl;
    }
    return 0;
}
