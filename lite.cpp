#include <iostream>
#include <stdio.h>

using namespace std;


class node {
    public:
        int on;
        int off;
        void setNode(int a, int b){
            on=a;
            off=b;
        }

};

node segArr[262143];

bool lazyArrStall[262143]={false};


void update(int l, int r, int index, int qStart, int qEnd){
    int temp;
    int mid;
    if(lazyArrStall[index]){
        temp=segArr[index].on;
        segArr[index].on=segArr[index].off;
        segArr[index].off=temp;
        if(l!=r){
            lazyArrStall[2*index+1]=!lazyArrStall[2*index+1];
            lazyArrStall[2*index+2]=!lazyArrStall[2*index+2];
        }
        lazyArrStall[index]=false;
    }

    if(l>=qStart && r<=qEnd){
        temp=segArr[index].off;
        segArr[index].off=segArr[index].on;
        segArr[index].on=temp;
        if(l!=r){
            lazyArrStall[2*index+1]=!lazyArrStall[2*index+1];
            lazyArrStall[2*index+2]=!lazyArrStall[2*index+2];
        }
        return;
    }
    if(qEnd<l || qStart>r)
        return;

    else{
        mid=(l+r)/2;
        update(l,mid,2*index+1,qStart,qEnd);
        update(mid+1,r,2*index+2,qStart,qEnd);
        segArr[index].on=segArr[2*index+1].on + segArr[2*index+2].on;
        segArr[index].off=segArr[2*index+1].off+segArr[2*index+2].off;
    }


}

void buildSegTree(int l, int r, int index){
    if(l==r){
        segArr[index].setNode(0,1);
        return;
    }
    int mid=(l+r)/2;
    buildSegTree(l,mid,2*index+1);
    buildSegTree(mid+1,r,2*index+2);
    segArr[index].on=segArr[2*index+1].on + segArr[2*index+2].on;
    segArr[index].off=segArr[2*index+1].off+segArr[2*index+2].off;

}


int querySegTree(int l, int r, int index, int qStart, int qEnd){
    int temp;
    int mid;
    int a;
    int b;
    if(lazyArrStall[index]) {
        temp=segArr[index].on;
        segArr[index].on=segArr[index].off;
        segArr[index].off=temp;
        if(l!=r){
            lazyArrStall[2*index+1]=!lazyArrStall[2*index+1];
            lazyArrStall[2*index+2]=!lazyArrStall[2*index+2];
        }
        lazyArrStall[index]=false;
    }

    if(l>=qStart && r<=qEnd){
        return segArr[index].on;
    }
    if(qStart>r || qEnd<l)
        return 0;
    else{
        mid=(l+r)/2;
        a=querySegTree(l,mid,2*index+1,qStart,qEnd);
        b=querySegTree(mid+1,r,2*index+2,qStart,qEnd);
        return a+b;
    }


}

int main() {
    int n,m,type,l,r;
    scanf("%d",&n);
    scanf("%d",&m);
    buildSegTree(0,n-1,0);
    for(int i=0;i<m;i++){
        scanf("%d",&type);
        scanf("%d",&l);
        scanf("%d",&r);
        if(type==0){
            update(0,n-1,0,l-1,r-1);
        }
        else {
            printf("%d\n",querySegTree(0,n-1,0,l-1,r-1));
        }

    }

}
