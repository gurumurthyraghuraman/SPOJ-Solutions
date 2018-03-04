#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> phoneListWithoutDups;
vector<string> phoneListWithDups;

bool checkPrefixInList(string phoneNum) {
    if (phoneListWithoutDups.find(phoneNum) != phoneListWithoutDups.end()) {
        phoneListWithoutDups[phoneNum] += 1;
        if (phoneListWithoutDups[phoneNum] > 1) {
            return true;
        }
    }

    string phoneNumPrefix;
    phoneNumPrefix += phoneNum[0];
    for (int i = 1; i < phoneNum.length(); i++) {
        if (phoneListWithoutDups.find(phoneNumPrefix) != phoneListWithoutDups.end()) {
            return true;
        }
        phoneNumPrefix += phoneNum[i];
    }
    return false;
}


bool isConsistent(vector<string> phoneList) {
    for (int i = 0; i < phoneList.size(); i++) {
        if (checkPrefixInList(phoneList[i])) {
            return false;
        }
    }
    return true;

}

int main() {
    int t,n;
    string phoneNum;
    cin>>t;
    for(int i = 0; i < t; i++) {
        phoneListWithoutDups.clear();
        phoneListWithDups.clear();
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>phoneNum;
            if (phoneListWithoutDups.find(phoneNum) != phoneListWithoutDups.end())
                phoneListWithoutDups[phoneNum] =  phoneListWithoutDups[phoneNum] + 1;
            else phoneListWithoutDups[phoneNum] = 0;

            phoneListWithDups.push_back(phoneNum);
        }
        if (isConsistent(phoneListWithDups)) {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
