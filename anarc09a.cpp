#include <iostream>
#include <string>
#include <stack>

using namespace std;

int noOfOperations(string inputString) {
    stack<char> bracesStack;
    int operationsNeeded = 0;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] == '{' || inputString[i] == '}') {
            if (inputString[i] == '{') {
                bracesStack.push(inputString[i]);
            } else {
                if (!bracesStack.empty()) {
                    bracesStack.pop();
                } else {
                    operationsNeeded++;
                }
            }
        }
    }
    int remainingStackSize = bracesStack.size();
    operationsNeeded = operationsNeeded / 2 + operationsNeeded % 2;
    operationsNeeded += (remainingStackSize / 2) + (remainingStackSize % 2);
    return operationsNeeded;
}

int main() {
    string inputString;
    int testCaseNo = 1;
    cin>>inputString;
    while(inputString[0] != '-') {
        cout<<testCaseNo<<". "<<noOfOperations(inputString)<<endl;
        cin>>inputString;
        testCaseNo++;
    }
    return 0;
}
