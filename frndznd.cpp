#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N,Q,arrElem,l,r;
	cin>>N>>Q;
	vector<int> arr;
	for(int i=0;i<N;i++) {
		cin>>arrElem;
		arr.push_back(arrElem);
	}
	for(int j=0;j<Q;j++){
		cin>>l>>r;
		if(l==r)
			cout<<arr[l-1]<<endl;
		else cout<<0<<endl;
	}

	return 0;
}
