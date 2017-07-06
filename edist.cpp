#include <iostream>
#include <string>


using namespace std;

int dpArr[2001][2001];

int returnDist(string a, string b) {
    int l1=a.length();
    int l2=b.length();
    for(int i=0;i<=l1;i++) {
        for(int j=0;j<=l2;j++) {
            if(i==0) {
                dpArr[i][j]=j;
            }
            else if(j==0) {
                dpArr[i][j]=i;
            }
            else if(a[i-1]==b[j-1]){
                dpArr[i][j]=dpArr[i-1][j-1];
            }
            else {
                dpArr[i][j]=1+min(dpArr[i-1][j],min(dpArr[i-1][j-1],dpArr[i][j-1]));
            }

        }
    }
    return dpArr[l1][l2];
}


int main() {
    int t;
    string strIn1, strIn2;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>strIn1>>strIn2;
        cout<<returnDist(strIn1, strIn2)<<endl;
    }
    return 0;
}
