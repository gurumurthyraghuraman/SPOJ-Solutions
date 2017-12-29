#include <iostream>
#include <string>

using namespace std;


string reverseStr(string inputStr) {
    string retString = "";
    for(int i = inputStr.length(); i >= 0; i--){
        retString += inputStr[i];
    }
    return retString;

}

string subtract(string sum, string res1) {
    int i = sum.length() - 1;
    int j = res1.length() - 1;
    string res2;
    string finalStr;
    while(i >= 0 && j >= 0){
        if(sum[i] >= res1[j]) {
            res2 += (sum[i] - res1[j]) + '0';
        }
        else {
            int k = i - 1;
            while(sum[k] == '0') {
                k--;
            }
            sum[k]--;
            for(int p = k + 1; p < i ; p++) {
                sum[p] = '9';
            }
            int num = 10 + (sum[i] - '0');
            res2 += (num - (res1[j] - '0')) + '0';
        }
        i--;
        j--;

    }
    while(i >= 0){
        res2 += sum[i];
        i--;
    }
    string retStr = reverseStr(res2);
    int q = 0;
    while(retStr[q] <= '0' || retStr[q] > '9') {
        q++;
    }
    for(int x = q; x < retStr.length(); x++){
        finalStr += retStr[x];
    }
    return finalStr;
}



string divideByTwo(string inputStr) {
    int i = 0;
    int carry = 0;
    string newStr = "";
    string retStr = "";
    string finalStr;
    while(i < inputStr.length()){
        if((int)inputStr[i] != 0) {
            newStr += inputStr[i];
            if(newStr[0]>='2' && newStr.length() == 1) {
                int num = carry*10 + (newStr[0] - '0');
                retStr += num / 2 + '0';
                carry = num % 2;
                newStr = "";
            }
            else {
                if(newStr.length() == 2) {
                    int dig1 = newStr[0] - '0';
                    int dig2 = newStr[1] - '0';
                    int num =  carry*10 + dig1*10 + dig2;
                    retStr += (num / 2) + '0';
                    carry = num % 2;
                    newStr = "";
                }
                if(newStr[0] == '0' && carry == 0 && i != 0) {
                    retStr += '0';
                    newStr = "";

                }
                if(newStr[0] == '0' && carry == 1 && i != 0) {
                    retStr += '5';
                    newStr = "";
                    carry = 0;

                }

                if(newStr[0] == '1' && carry == 0 && i != 0) {
                    retStr += '0';
                    newStr = "";
                    carry = 1;
                }

                else if(newStr[0] == '1' && carry == 1 && i != 0) {
                    retStr += '5';
                    newStr = "";
                    carry = 1;
                }


            }
        }
        i++;
    }
    int j = 0;
    while(retStr[j] == '0') {
        j++;
    }
    for(int x = j; x<retStr.length(); x++)
        finalStr += retStr[x];

    return finalStr;

}

string julka(string sum, string diff){
    int i = sum.length() - 1;
    int j = diff.length() - 1;
    int carry = 0;
    string newSum = "";
    while(i>=0 && j>=0) {
        int num1 = sum[i] - '0';
        int num2 = diff[j] - '0';
        int num3 = num1 + num2 + carry;
        if(num3 < 10) {
            newSum += '0' + num3;
            carry = 0;
        }
        else {
            newSum += '0' + (num3 % 10);
            carry = num3 / 10;
        }
        i--;
        j--;
    }
    while(i>=0){
        if(carry == 1) {
            int newNum = carry + (sum[i] - '0');
            if(newNum >= 10){
                newSum += (newNum % 10) + '0';
                carry = newNum / 10;
            }
            else{
                newSum += newNum + '0';
                carry = 0;
            }
        }
        else newSum += sum[i];
        i--;
    }
    if(carry == 1) {
        newSum += '1';
    }
    string addStr = reverseStr(newSum);
    string finalAddStr;
    int y = 0;
    while(addStr[y] == '0' || addStr[y] < '0' || addStr[y] > '9')
        y++;
    for(int x = y; x<addStr.length(); x++)
        finalAddStr += addStr[x];

    return divideByTwo(finalAddStr);
}


int main(){
    int i = 0;
    string sum,diff;
    while(i < 10) {
        cin>>sum>>diff;
        string res1,res2;
        res1 = julka(sum, diff);
        res2 = subtract(res1, diff);
        cout<<res1<<endl<<res2<<endl;
        i++;
    }

    return 0;
}
