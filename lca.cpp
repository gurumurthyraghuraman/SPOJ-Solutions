#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;



void clearArray(vector<int> arr[1000],int levelArr[1000], int parentArr[1000], int LCAArr[1000]){
        for(int i=0;i<1000;i++) {
            arr[i].clear();
            levelArr[i]=-1;
            parentArr[i]=-1;
            LCAArr[i]=-1;
        }
}

int calculateHeight(vector<int> arr[1000], int index, int levelArr[1000]) {
    int height=0;
    levelArr[0]=0;
    int queueFront;
    int queueSize;
    queue<int> bfsQueue;
    bfsQueue.push(index);
    while(!bfsQueue.empty()) {
        queueSize=bfsQueue.size();
        for(int i=0;i<queueSize;i++) {
            queueFront=bfsQueue.front();
            levelArr[queueFront]=height;
            for(int j=0;j<arr[queueFront].size();j++) {
                bfsQueue.push(arr[queueFront][j]);
            }
            bfsQueue.pop();
        }
        height++;
    }

    return height-1;

}

void dfs(int node,int LCAArr[1000],int parentArr[1000],int levelArr[1000], int nr, vector<int> graphArr[1000] ) {
    if(levelArr[node]<nr) {
        LCAArr[node]=0;
    }
    else {
        if(levelArr[node]%nr==0){
            LCAArr[node]=parentArr[node];
        }
        else {
            LCAArr[node]=LCAArr[parentArr[node]];

        }

    }
    for(int i=0;i<graphArr[node].size();i++) {
        dfs(graphArr[node][i],LCAArr,parentArr,levelArr,nr,graphArr);
    }
}


int LCAquery(int a, int b, int LCAArr[1000], int parentArr[1000], int levelArr[1000]) {
    while(LCAArr[a]!=LCAArr[b]){
        if(levelArr[a]>levelArr[b]){
            a=LCAArr[a];
        }
        else
            b=LCAArr[b];

    }

    while(a!=b) {
        if(levelArr[a]>levelArr[b])
            a=parentArr[a];
        else b=parentArr[b];
    }

    return a;
}

int main() {

    vector<int> arr[1000];
    int levelArr[1000];
    int parentArr[1000];
    int LCAArr[1000];
    int t,n,edges,edgeValue,h,nr,noOfQueries,l, r;
    cin>>t;
    for(int i=0;i<t;i++) {
        clearArray(arr,levelArr,parentArr,LCAArr);
        cin>>n;
        for(int j=0;j<n;j++) {
            cin>>edges;
            for(int k=0;k<edges;k++) {
                cin>>edgeValue;
                arr[j].push_back(edgeValue-1);
                parentArr[edgeValue-1]=j;
            }
        }
        h=calculateHeight(arr,0,levelArr);
        if(h>0){
            nr=sqrt(h);
            dfs(0,LCAArr,parentArr,levelArr, nr,arr);
        }
        cin>>noOfQueries;
        cout<<"Case "<<i+1<<":"<<endl;
        for(int p=0;p<noOfQueries;p++) {
            cin>>l>>r;
            if(h>0)
                cout<<LCAquery(l-1,r-1,LCAArr,parentArr,levelArr)+1<<endl;
            else cout<<"1"<<endl;
        }

    }
    return 0;

}
