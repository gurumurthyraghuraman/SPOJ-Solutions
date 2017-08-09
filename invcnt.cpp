#include <iostream>
using namespace std;
int arr[200000];
long long inversions;

long long merge(int first, int mid, int last){
	int leftArr[100000];
	int rightArr[100000];
	int l,r;
	int j=0;
	int q=0;
	long long inv=0;
	int iter=first;
	l=r=0;
	for(int i=first;i<=mid;i++){
		leftArr[j]=arr[i];
		j++;
	}

	for(int p=mid+1;p<=last;p++){
		rightArr[q]=arr[p];
		q++;
	}
	while(l<j && r<q){
		if(leftArr[l]<rightArr[r]){
			arr[iter]=leftArr[l];
			l++;
			iter++;
		}
		else{
			arr[iter]=rightArr[r];
			r++;
			inv+=j-l;
			iter++;
		}

	}
	while(l<j){
		arr[iter]=leftArr[l];
		iter++;
		l++;
	}
	while(r<q){
		arr[iter]=rightArr[r];
		iter++;
		r++;
	}

	return inv;

}


void mergeSort(int first, int last){
	int mid;
	if(first<last){
		mid=(first+last)/2;
		mergeSort(first,mid);
		mergeSort(mid+1,last);
		inversions+=merge(first,mid,last);
	}

}


int main() {
	// your code goes here
	int t,n,temp;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		inversions=0;
		for(int j=0;j<n;j++){
			cin>>temp;
			arr[j]=temp;
		}
		mergeSort(0,n-1);
		cout<<inversions<<endl;
	}
	return 0;
}
