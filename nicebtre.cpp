#include <iostream>
#include <string>

using namespace std;

int depth(string strTree, int *index) {
    if(strTree[*index]=='l')
        return 0;
    *index=*index+1;
    int leftDepth = depth(strTree,(index))+1;
    *index=*index+1;
    int rightDepth = depth(strTree,(index))+1;
    if(leftDepth>=rightDepth)
        return leftDepth;

    return rightDepth;




}


int main() {
    int t;
    int startIndex=0;
    string strInput;

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>strInput;
        startIndex=0;
        cout<<depth(strInput,&startIndex)<<endl;
    }
    return 0;
}

