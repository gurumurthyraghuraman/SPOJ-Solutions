#include <iostream>
#include <stdio.h>
using namespace std;

class node{
	public:
		int divBy3;
		int rem1;
		int rem2;
		void setNode(int a, int b, int c){
			divBy3=a;
			rem1=b;
			rem2=c;
		}
};
node segTree[262143];
int lazyArr[262143];

void buildSegTree(int l, int r, int index){
	if(l==r){
		segTree[index].setNode(1,0,0);
		return;
	}
	int mid=(l+r)/2;
	buildSegTree(l,mid,2*index+1);
	buildSegTree(mid+1,r,2*index+2);
	segTree[index].divBy3=segTree[2*index+1].divBy3+segTree[2*index+2].divBy3;
	segTree[index].rem1=0;
	segTree[index].rem2=0;
}

void updateSegTree(int l, int r, int index, int qStart, int qEnd) {
	if(lazyArr[index]!=0) {
		if(lazyArr[index]==1) {
			segTree[index].setNode(segTree[index].rem2,segTree[index].divBy3, segTree[index].rem1);
			if(l!=r) {
				lazyArr[2*index+1]=lazyArr[2*index+1]+1;
				lazyArr[2*index+2]=lazyArr[2*index+2]+1;
				lazyArr[2*index+1]=lazyArr[2*index+1]%3;
				lazyArr[2*index+2]=lazyArr[2*index+2]%3;
			}
		}
		if(lazyArr[index]==2) {
			segTree[index].setNode(segTree[index].rem1, segTree[index].rem2, segTree[index].divBy3);
			if(l!=r) {
				lazyArr[2*index+1]=lazyArr[2*index+1]+2;
				lazyArr[2*index+2]=lazyArr[2*index+2]+2;
				lazyArr[2*index+1]=lazyArr[2*index+1]%3;
				lazyArr[2*index+2]=lazyArr[2*index+2]%3;
			}
		}
		lazyArr[index]=0;
	}
	if(l>qEnd || r<qStart) {
		return;
	}
	if(l>=qStart && r<=qEnd) {
		segTree[index].setNode(segTree[index].rem2,segTree[index].divBy3,segTree[index].rem1);
		if(l!=r) {
			lazyArr[2*index+1]++;
			lazyArr[2*index+2]++;
			lazyArr[2*index+1]=lazyArr[2*index+1]%3;
			lazyArr[2*index+2]=lazyArr[2*index+2]%3;
		}
		return;
	}
	else {
		int mid=(l+r)/2;
		updateSegTree(l,mid,2*index+1,qStart,qEnd);
		updateSegTree(mid+1,r,2*index+2,qStart,qEnd);
		segTree[index].divBy3=segTree[2*index+1].divBy3+segTree[2*index+2].divBy3;
		segTree[index].rem1=segTree[2*index+1].rem1+segTree[2*index+2].rem1;
		segTree[index].rem2=segTree[2*index+1].rem2+segTree[2*index+2].rem2;
	}

}

int querySegTree(int l, int r, int index, int qStart, int qEnd) {
	if(lazyArr[index]!=0) {
		if(lazyArr[index]==1) {
			segTree[index].setNode(segTree[index].rem2,segTree[index].divBy3, segTree[index].rem1);
			if(l!=r) {
				lazyArr[2*index+1]+=1;
				lazyArr[2*index+2]+=1;
				lazyArr[2*index+1]=lazyArr[2*index+1]%3;
				lazyArr[2*index+2]=lazyArr[2*index+2]%3;
			}
		}
		if(lazyArr[index]==2) {
			segTree[index].setNode(segTree[index].rem1, segTree[index].rem2, segTree[index].divBy3);
			if(l!=r) {
				lazyArr[2*index+1]+=2;
				lazyArr[2*index+2]+=2;
				lazyArr[2*index+1]=lazyArr[2*index+1]%3;
				lazyArr[2*index+2]=lazyArr[2*index+2]%3;
			}
		}
		lazyArr[index]=0;
	}
	if(l>qEnd || r<qStart) {
		return 0;
	}
	if(l>=qStart && r<=qEnd){
		return segTree[index].divBy3;
	}
	else {
		int mid=(l+r)/2;
		int a=querySegTree(l,mid,2*index+1,qStart,qEnd);
		int b=querySegTree(mid+1,r,2*index+2,qStart,qEnd);
		return a+b;
	}

}


void initializeArr(){
	for(int i=0;i<262143;i++){
		lazyArr[i]=0;
	}
}

int main() {
	// your code goes here
	int n,m,type,l,r;
	scanf("%d",&n);
	scanf("%d",&m);
	initializeArr();
	buildSegTree(0,n-1,0);
	for(int i=0;i<m;i++){
		scanf("%d",&type);
		scanf("%d",&l);
		scanf("%d",&r);
		if(type==0){
			updateSegTree(0,n-1,0,l,r);
		}
		else{
			printf("%d\n",querySegTree(0,n-1,0,l,r));
		}
	}
	return 0;
}
