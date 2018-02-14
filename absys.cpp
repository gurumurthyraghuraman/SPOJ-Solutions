#include <iostream>
#include <string>

using namespace std;

bool isNumber(string num) {
    for(int i = 0; i < num.length(); i++) {
        if(num[i] < '0' || num[i] > '9')
            return false;
    }
    return true;
}


int main() {
    int t;
    string num1,num2,num3;
    string plusSign, equalTo;
    int firstNumber, secondNumber, thirdNumber;
    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>num1>>plusSign>>num2>>equalTo>>num3;
        if (isNumber(num1)) {
            cout<<num1<<" + ";
        } else {
            secondNumber = stoi(num2);
            thirdNumber = stoi(num3);
            firstNumber = thirdNumber - secondNumber;
            cout<<firstNumber<<" + ";
        }
        if (isNumber(num2)) {
            cout<<num2<<" = ";
        } else {
            firstNumber = stoi(num1);
            thirdNumber = stoi(num3);
            secondNumber = thirdNumber - firstNumber;
            cout<<secondNumber<<" = ";
        }
        if (isNumber(num3)) {
            cout<<num3<<endl;
        } else {
            firstNumber = stoi(num1);
            secondNumber = stoi(num2);
            thirdNumber = firstNumber + secondNumber;
            cout<<thirdNumber<<endl;
        }
    }
    return 0;
}
