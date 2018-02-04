#include <iostream>
#include <vector>

using namespace std;

string hashTable[101];
bool deletedList[101];

void initialize() {
    for(int i = 0; i < 101; i++) {
        hashTable[i] = "";
        deletedList[i] = false;
    }

}

int hashValue(string key) {
    int value = key[0];
    for(int i = 1; i < key.length(); i++) {
        value += key[i]*(i+1);
    }
    return (19*value) % 101;
}

int firstEmptySlot(string key, int index) {
    int position = -1;
    int copyIndex = index;

    for (int j = 1; j <= 20; j++) {
        if (hashTable[index] == key && !deletedList[index]) {
            return -1;
        }
        else if(deletedList[index] && position == -1) {
            position = index;
        }
        else if(hashTable[index].length() == 0 && position == -1) {
            position = index;
        }
        index = (copyIndex + j*j + 23*j) % 101;
    }
    return position;

}

void insertKey(string key) {
    int index = hashValue(key);
    int position = firstEmptySlot(key, index);
    if (position == -1) {
        return;
    }
    else {
        hashTable[position] = key;
        deletedList[position] = false;
    }
}

void deleteKey(string key) {
    int index = hashValue(key);
    int copyIndex = index;

    for (int j = 1; j <= 20; j++) {
        if (hashTable[index] == key && !deletedList[index]) {
            deletedList[index] = true;
            return;
        }
        index = (copyIndex + j*j + 23*j) % 101;
    }
}

void displayResults() {
    vector<int> allIndexes;
    for(int i = 0; i <= 100; i++) {
        if (hashTable[i].length() > 0 && !deletedList[i]) {
            allIndexes.push_back(i);
        }
    }
    cout<<allIndexes.size()<<endl;
    for(int j = 0; j < allIndexes.size(); j++) {
        cout<<allIndexes[j]<<":"<<hashTable[allIndexes[j]]<<endl;
    }
}

vector<string> splitString(string operatorAndKey) {
    string operation;
    string key;
    vector<string> vectOpAndKey;
    int nextPart = 0;
    for(int i = 0; i < operatorAndKey.length() ; i++) {
        if(operatorAndKey[i] == ':') {
            nextPart = i;
            break;
        } else {
            operation += operatorAndKey[i];
        }
    }
    for(int j = nextPart + 1; j < operatorAndKey.length(); j++) {
        key += operatorAndKey[j];
    }
    vectOpAndKey.push_back(operation);
    vectOpAndKey.push_back(key);

    return vectOpAndKey;
}

int main() {
    int t,n;
    string opAndKey;
    cin>>t;
    for (int i = 0; i < t; i++) {
        initialize();
        cin>>n;
        for (int j = 0; j < n; j++) {
            cin>>opAndKey;
            vector<string> operatorAndKey = splitString(opAndKey);
            if (operatorAndKey[0] == "ADD") {
                insertKey(operatorAndKey[1]);
            }
            else {
                deleteKey(operatorAndKey[1]);
            }
        }
        displayResults();
        cout<<endl;

    }

    return 0;
}
