#include <iostream>
#include <string>
using namespace std;

class bracketNode {
	public:
		int open;
		int closed;
		void setNode(int a, int b) {
			open=a;
			closed=b;
		}

};

void updateSegTree(bracketNode segmentArr[65535], int l, int r, string strBrckt, int index,
					int updateIndex) {
		if(l==r) {
			if(segmentArr[index].open==1 && segmentArr[index].closed==0)
				segmentArr[index].setNode(0,1);
			else segmentArr[index].setNode(1,0);
			return;
		}
		int mid=(l+r)/2;
		if(updateIndex>=l && updateIndex<=mid)
			updateSegTree(segmentArr,l,mid,strBrckt,2*index+1,updateIndex);
		else
			updateSegTree(segmentArr,mid+1,r,strBrckt,2*index+2,updateIndex);
		if(segmentArr[2*index+1].open-segmentArr[2*index+2].closed<=0) {
			segmentArr[index].open=0;
			segmentArr[index].closed=segmentArr[2*index+2].closed-segmentArr[2*index+1].open;
		}
		else {
			segmentArr[index].closed=0;
			segmentArr[index].open=segmentArr[2*index+1].open-segmentArr[2*index+2].closed;
		}
		segmentArr[index].open+=segmentArr[2*index+2].open;
		segmentArr[index].closed+=segmentArr[2*index+1].closed;

}


void buildSegTree(bracketNode segmentArr[65535], int l, int r, string strBrckt, int index){
	if(l==r) {
		if(strBrckt[l]=='(')
			segmentArr[index].setNode(1,0);
		else
			segmentArr[index].setNode(0,1);
		return;
	}
	int mid=(l+r)/2;
	buildSegTree(segmentArr,l,mid,strBrckt,2*index+1);
	buildSegTree(segmentArr,mid+1,r,strBrckt,2*index+2);
	if(segmentArr[2*index+1].open-segmentArr[2*index+2].closed<=0) {
		segmentArr[index].open=0;
		segmentArr[index].closed=segmentArr[2*index+2].closed-segmentArr[2*index+1].open;
	}
	else {
		segmentArr[index].closed=0;
		segmentArr[index].open=segmentArr[2*index+1].open-segmentArr[2*index+2].closed;
	}
	segmentArr[index].open+=segmentArr[2*index+2].open;
	segmentArr[index].closed+=segmentArr[2*index+1].closed;

}

int main() {
	bracketNode segmentArr[65535];
	string strBrckt;
	int brcktLen,n,updateIndex;
	for(int i=1;i<=10;i++) {
		cin>>brcktLen;
		cin>>strBrckt;
		buildSegTree(segmentArr,0,brcktLen-1,strBrckt,0);
		cin>>n;
		cout<<"Test "<<i<<":"<<endl;
		for(int j=0;j<n;j++) {
			cin>>updateIndex;
			if(updateIndex==0) {
				if(segmentArr[0].open==0 && segmentArr[0].closed==0)
					cout<<"YES"<<endl;
				else cout<<"NO"<<endl;

			}
			else
				updateSegTree(segmentArr,0,brcktLen-1,strBrckt,0,updateIndex-1);

		}
	}
	// your code goes here
	return 0;
}
