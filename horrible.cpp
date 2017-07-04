#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

void initializeArray(long long a[300000], int n){

    //memset(a, 0, 400000*sizeof(*a));
    fill(a, a+n, 0);
}

void updateRange(long long treeArr[300000], long long lazyArr[300000], int node, int first, int last, int leftRange, int rightRange, long long  value) {

     if(lazyArr[node]!=0) {
        treeArr[node]+=(last-first+1)*lazyArr[node];
        if(first!=last) {
            lazyArr[node*2+1] += lazyArr[node];
            lazyArr[node*2+2] += lazyArr[node];
        }
        lazyArr[node]=0;
    }


    if(first>last || last<leftRange || first > rightRange) return;




    if(first>=leftRange && last<=rightRange) {
        treeArr[node]+=(last-first+1)*value;
        if(first!=last) {
            lazyArr[node*2+1]+=value;
            lazyArr[node*2+2]+=value;
        }
        return;
    }
    int mid = (first+last)/2;
    updateRange(treeArr, lazyArr, node*2+1, first, mid, leftRange, rightRange, value);
    updateRange(treeArr, lazyArr, node*2+2, mid+1, last, leftRange, rightRange, value);
    treeArr[node]=treeArr[node*2+1]+treeArr[node*2+2];
}

long long queryRange(long long treeArr[300000], long long lazyArr[300000], int node, int first, int last, int leftRange, int rightRange) {
    if(first>last || last<leftRange || first > rightRange) return 0;

    if(lazyArr[node]!=0) {
        treeArr[node]+=(last-first+1)*lazyArr[node];
        if(first!=last) {
            lazyArr[node*2+1] += lazyArr[node];
            lazyArr[node*2+2] += lazyArr[node];
        }
        lazyArr[node]=0;
    }

    if(first>=leftRange && last<=rightRange) {
        return treeArr[node];
    }
    int mid=(first+last)/2;
    long long r1=queryRange(treeArr, lazyArr, node*2+1, first, mid, leftRange, rightRange);
    long long r2=queryRange(treeArr, lazyArr, node*2+2, mid+1, last, leftRange, rightRange);
    return (r1+r2);
}

int main() {
    long long arrN[300000];
    long long lazyArr[300000];
    int t,n,c, segIn1, segIn2, segIn3, sizeOfTree;
    long long segIn4;

    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n>>c;
        sizeOfTree = 2*pow(2,ceil(log2(n)))-1;
        initializeArray(arrN, sizeOfTree);
        initializeArray(lazyArr,sizeOfTree);
        for(int j=0;j<c;j++) {
            cin>>segIn1;
            if(segIn1==0) {
                cin>>segIn2>>segIn3>>segIn4;
                updateRange(arrN,lazyArr,0,0,n-1,segIn2-1, segIn3-1, segIn4);
            }
            else {
                cin>>segIn2>>segIn3;
                cout<<queryRange(arrN,lazyArr,0, 0, n-1, segIn2-1, segIn3-1)<<endl;
            }
        }


    }
    return 0;
}
