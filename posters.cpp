#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

const int maxArrSize = 40000000;
set<int> posters;
void noOfPosters(int arr[maxArrSize], int init, int maxArrayT) {
	if(init>=maxArrayT)
		return;

	if(arr[init]!=0){
		posters.insert(arr[init]);
		return;
	}
	else {
		noOfPosters(arr,init*2+1,maxArrayT);
		noOfPosters(arr,init*2+2,maxArrayT);

	}

}

void initializeArray(int a[maxArrSize], int arrSize) {
    fill(a,a+arrSize,0);
}

void updateSegTree(int arr[maxArrSize], int node, int first, int last, int leftRange, int rightRange, int color) {
        if(first>last || last<leftRange || first>rightRange) return;

        if(first>=leftRange && last<=rightRange) {
            arr[node]=color;
            return;
        }

        if(arr[node]!=0) {
            if(first!=last) {
                arr[node*2+1]=arr[node*2+2]=arr[node];
                arr[node]=0;
            }
        }


        int mid=(first+last)/2;
        updateSegTree(arr,node*2+1,first, mid, leftRange, rightRange, color);
        updateSegTree(arr, node*2+2, mid+1, last, leftRange, rightRange, color);

}


int main() {
    int k,t,n,inputSeg1,inputSeg2, maxInputLen,maxArrayT;
    int arr[maxArrSize]={0};
    cin>>t;
    for(int i=0;i<t; i++) {
        cin>>n;
        maxInputLen=0;
        for(int j=0;j<n;j++){
            cin>>inputSeg1>>inputSeg2;
            updateSegTree(arr,0,0,10000000,inputSeg1-1, inputSeg2-1, j+1);
        }
        k=0;
        maxArrayT=2*pow(2, ceil(log2(maxInputLen)))-1;
        noOfPosters(arr,0,maxArrayT-1);

        cout<<posters.size()<<endl;
        initializeArray(arr,maxArrSize);
        posters.clear();
    }
    return 0;
}
