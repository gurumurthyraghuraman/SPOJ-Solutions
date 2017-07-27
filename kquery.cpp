#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


/*
                        0:4
                        /\                       4 2 2 2 0 1 1 1 1
                       /  \
                   0:2      3:4
                   /\        /\                     1,3  1          update index 2 to 0
                  /  \    3:3  4:4
                 0:1  2:2
                /\
               /  \
              0:0 1:1

*/

int segmentArr[1048575];


class node {
    public:
        int index;
        int value;

        void setNode(int a, int b){
            index=a;
            value=b;
        }

        bool operator<( const node& val ) const {
            return value < val.value;
        }

};

class queryNode {
    public:
        int index;
        int i;
        int j;
        int k;

        void setQueryNode(int index,int i,int j,int k){
            (*this).index=index;
            (*this).i=i;
            (*this).j=j;
            (*this).k=k;
        }

        bool operator<( const queryNode& val ) const {
            return k < val.k;
        }

};

void buildSegTree(int l, int r,int index) {
    if(l==r){
        segmentArr[index]=1;
        return;
    }
    int mid=(l+r)/2;
    buildSegTree(l,mid, 2*index+1);
    buildSegTree(mid+1,r,2*index+2);
    segmentArr[index]=segmentArr[2*index+1]+segmentArr[2*index+2];

}

void updateSegTree(int index, int l, int r, int arrIndex) {

        if(l==r) {
            segmentArr[index]=0;
            return;
        }
        int mid=(l+r)/2;
        if(l<=arrIndex && arrIndex<=mid){
            updateSegTree(index*2+1,l,mid,arrIndex);
        }
        else updateSegTree(index*2+2,mid+1,r,arrIndex);

        segmentArr[index]=segmentArr[2*index+1]+segmentArr[2*index+2];

}

int querySegTree(int l, int r, int index, int queryL, int queryR) {

        if(queryL>r || queryR<l)
            return 0;


        if(l>=queryL && r<=queryR)
            return segmentArr[index];

        int mid=(l+r)/2;
        int a=querySegTree(l,mid,2*index+1,queryL,queryR);
        int b=querySegTree(mid+1,r,2*index+2,queryL,queryR);
        return a+b;


}


int main() {
    //building segment trees with all 1's
    // marking the elements less than k with 0.
    // query on given range
    int n,inputElem,noOfQueries,l,r,queryVal;
    node arrInput[30000];
    queryNode arrQuery[200000];
    int ans[200000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&inputElem);
        arrInput[i].setNode(i,inputElem);
    }
    scanf("%d",&noOfQueries);
    for(int j=0;j<noOfQueries;j++) {
        scanf("%d",&l);
        scanf("%d",&r);
        scanf("%d",&queryVal);
        arrQuery[j].setQueryNode(j,l,r,queryVal);
    }

    buildSegTree(0,n-1,0);
    sort(arrInput,arrInput+n);
    sort(arrQuery,arrQuery+noOfQueries);
    int inputIndex=0;
    for(int k=0;k<noOfQueries;k++) {
        while(inputIndex<n && arrInput[inputIndex].value<=arrQuery[k].k) {
            updateSegTree(0,0,n-1,arrInput[inputIndex].index);
            inputIndex++;
        }
        ans[arrQuery[k].index]=querySegTree(0,n-1,0,arrQuery[k].i-1,arrQuery[k].j-1);

    }
    for(int p=0;p<noOfQueries;p++) {
        printf("%d\n",ans[p]);
    }
    return 0;
}

