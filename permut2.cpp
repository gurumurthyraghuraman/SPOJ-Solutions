#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool isAmbiguous(int n, map<int,int> arrPosMap, vector<int> inputArr) {
    for(int i = 0; i < n; i++) {
        if(arrPosMap[i + 1] != inputArr[i])
            return false;
    }
    return true;
}


int main() {
    map<int, int> arrPosMap;
    vector<int> inputArr;
    int n,temp;
    cin>>n;
    while(n!=0){
        arrPosMap.clear();
        inputArr.clear();
        for(int i = 0; i < n; i++) {
            cin>>temp;
            arrPosMap[temp] = i + 1;
            inputArr.push_back(temp);
        }
        if(isAmbiguous(n, arrPosMap, inputArr)) {
            cout<<"ambiguous"<<endl;
        }
        else {
            cout<<"not ambiguous"<<endl;
        }
        cin>>n;
    }


    return 0;
}
