#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void initializeArray(int dpArr[50][50]){
    for(int i=0;i<50;i++)
        for(int j=0;j<50;j++)
            dpArr[i][j]=0;

}

int dfs(char arr[50][50], pair<int,int> node, int h, int w,int dpArr[50][50]){
    if(dpArr[node.first][node.second]==0){
        if(node.first+1<h && arr[node.first+1][node.second]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first+1,node.second),h,w,dpArr));
        }
        if(node.first-1>=0 && arr[node.first-1][node.second]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first-1,node.second),h,w,dpArr));
        }
        if(node.second+1<w && arr[node.first][node.second+1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first,node.second+1),h,w,dpArr));
        }
        if(node.second-1>=0 && arr[node.first][node.second-1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first,node.second-1),h,w,dpArr));
        }
        if(node.first-1>=0 && node.second-1>=0  && arr[node.first-1][node.second-1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first-1,node.second-1),h,w,dpArr));
        }
        if(node.first+1<h && node.second+1<w  && arr[node.first+1][node.second+1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first+1,node.second+1),h,w,dpArr));
        }
        if(node.first+1<h && node.second-1>=0  && arr[node.first+1][node.second-1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first+1,node.second-1),h,w,dpArr));
        }
        if(node.first-1>=0 && node.second+1<w  && arr[node.first-1][node.second+1]==arr[node.first][node.second]+1){
            dpArr[node.first][node.second]=max(dpArr[node.first][node.second],1+dfs(arr,make_pair(node.first-1,node.second+1),h,w,dpArr));
        }
    }
    if(dpArr[node.first][node.second]!=0)
	return dpArr[node.first][node.second];

    return 1;

}
int main() {
	char arr[50][50];
	int dpArr[50][50]={0};
	char c;
	int k=0;
	int h,w;
	cin>>h>>w;
	int maxAns,ans;
	vector<pair<int,int> > startPoints;
	while(h!=0 && w!=0){
		k++;
		startPoints.clear();
		initializeArray(dpArr);
		maxAns=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cin>>c;
				arr[i][j]=c;
				if(c=='A')
				     startPoints.push_back(make_pair(i,j));
			}
		}
		if(startPoints.empty())
			cout<<"Case "<<k<<": "<<maxAns<<endl;
		else {
			for(int i=0;i<startPoints.size();i++){
				ans=dfs(arr,startPoints[i],h,w,dpArr);
				if(ans>maxAns)
					maxAns=ans;
			}
			cout<<"Case "<<k<<": "<<maxAns<<endl;
		}
		cin>>h>>w;

	}
	// your code goes here
	return 0;
}
