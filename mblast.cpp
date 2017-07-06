#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int dpArr[2001][2001];

int minDist(string a, string b, int m, int n, int d) {
    int charDist;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++) {
            if(i==0)
                dpArr[i][j]=j*d;

            else if(j==0)
                dpArr[i][j]=i*d;
            else {
                charDist=abs(a[i-1]-b[j-1]);
                dpArr[i][j]=min(d+dpArr[i][j-1], min(d+dpArr[i-1][j],charDist+dpArr[i-1][j-1]));
            }

        }

    }

    return dpArr[m][n];

}


/*int minDist(string a, string b, int l1, int l2, int d) {
    int charDist=abs(a[l1-1]-b[l2-1]);
    if(l1==0)
        return l2*d;

    if(l2==0)
        return l1*d;


    return min(d+minDist(a,b,l1,l2-1,d),min(d+minDist(a,b,l1-1,l2,d), charDist+minDist(a,b,l1-1,l2-1,d)));


}*/


int main() {
    int dist;
    string strIn1, strIn2;
    cin>>strIn1>>strIn2;
    cin>>dist;
    cout<<minDist(strIn1,strIn2,strIn1.length(),strIn2.length(),dist)<<endl;
    return 0;
}
