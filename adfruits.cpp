#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


/*
        a b c
        0 0 0
    a 0 1 1 1
    q 0 1 1 1
    b 0 1 2 2


*/

/*int lcs(string a, string b, int m, int n) {
    if(m==0 || n==0)
        return 0;

    if(a[m-1]==b[n-1]) {
        return 1+lcs(a,b,m-1,n-1);
    }
    else return max(lcs(a,b,m-1,n), lcs(a,b,m,n-1));

}*/
void boolArray(vector<bool> &vectStr1, string a, string strLCS) {
        int strLen=a.length();
        int lcsLen=strLCS.length()-1;
        for(int i=strLen-1;i>=0;i--) {
            if(lcsLen>=0 && a[i]==strLCS[lcsLen]){
                vectStr1[i]=true;
                lcsLen--;
            }
            else{
                vectStr1[i]=false;
            }

        }
}


string strFromDpArray(int dpArr[][101], string a, string b, int m, int n){
       int strLen=dpArr[m][n];
       string retString;
       while(m>0 && n>0) {
            if(a[m-1]==b[n-1]){
                retString+=a[m-1];
                m--;n--;
            }
            else if(dpArr[m][n]==dpArr[m-1][n])
                    m--;
            else n--;
       }
       reverse(retString.begin(),retString.end());
       return retString;

}

string fruitName(string a, string b, int m, int n) {
    int dpArr[101][101];
    string retString;
    int p=0;
    int q=0;
    int x,y;
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++) {
            if(i==0 || j==0) dpArr[i][j]=0;
            else if(a[i-1]==b[j-1]) dpArr[i][j]=1+dpArr[i-1][j-1];
            else dpArr[i][j]=max(dpArr[i-1][j], dpArr[i][j-1]);
        }
    }
    string lcsString=strFromDpArray(dpArr,a,b,m,n);
    vector<bool> vecta(m);
    vector<bool> vectb(n);
    boolArray(vecta,a,lcsString);
    boolArray(vectb,b,lcsString);
    while(p<m && q<n) {
        x=p;y=q;
        while(x<m && !vecta[x]){
            retString+=a[x];
            x++;
        }
        while(y<n && !vectb[y]) {
            retString+=b[y];
            y++;
        }
        while(x<m && y<n && vecta[x] && vectb[y]){
            retString+=a[x];
            x++;y++;
        }
        p=x;
        q=y;

    }
    for(int u=p;u<m;u++){
        retString+=a[u];
    }
    for(int v=q;v<n;v++){
        retString+=b[v];
    }
    return retString;
}



int main() {
    string strIn1, strIn2;
    while(cin>>strIn1) {
        cin>>strIn2;
        cout<<fruitName(strIn1,strIn2,strIn1.length(),strIn2.length())<<endl;
    }
    return 0;
}
