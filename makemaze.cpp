#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool isMaze(char arr[20][20], int pCount,pair<int,int> sIndex, int m , int n){
    if(pCount!=2)
        return false;
    queue<pair<int,int> > bfsQueue;
    bool visited[1000][1000]={false};
    if(sIndex.first+1<m){
        pair<int,int> tempPair(sIndex.first+1,sIndex.second);
        bfsQueue.push(tempPair);
    }
    if(sIndex.first-1>=0) {
        pair<int,int> tempPair(sIndex.first-1,sIndex.second);
        bfsQueue.push(tempPair);

    }
    if(sIndex.second+1<n) {
        pair<int,int> tempPair(sIndex.first,sIndex.second+1);
        bfsQueue.push(tempPair);
    }
    if(sIndex.second-1>=0) {
        pair<int,int> tempPair(sIndex.first,sIndex.second-1);
        bfsQueue.push(tempPair);

    }
    visited[sIndex.first][sIndex.second]=true;

    while(!bfsQueue.empty()) {
        pair<int,int> queueFront=bfsQueue.front();
        if(queueFront.first>=m || queueFront.first<0 || queueFront.second>=n || queueFront.second<0)
            return true;

        if(!visited[queueFront.first][queueFront.second] &&  arr[queueFront.first][queueFront.second]=='.'){
            pair<int,int> temp1(queueFront.first+1, queueFront.second);
            pair<int,int> temp2(queueFront.first-1, queueFront.second);
            pair<int,int> temp3(queueFront.first, queueFront.second+1);
            pair<int,int> temp4(queueFront.first, queueFront.second-1);
            bfsQueue.push(temp1);
            bfsQueue.push(temp2);
            bfsQueue.push(temp3);
            bfsQueue.push(temp4);
        }
        visited[queueFront.first][queueFront.second]=true;
        bfsQueue.pop();
    }

    return false;

}



int main() {
    char maze[20][20];
    char tempIn;
    int m,n,t,pCount;
    pair<int,int> startIndex;
    cin>>t;
    for(int k=0;k<t;k++){
        cin>>m>>n;
        pCount=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>tempIn;
                maze[i][j]=tempIn;
                if(tempIn=='.' && (i==0 || i==m-1 || j==0 || j==n-1)) {
                    pCount++;
                    startIndex.first=i;
                    startIndex.second=j;
                }

            }

        }
        if(isMaze(maze,pCount,startIndex,m,n))
            cout<<"valid"<<endl;
        else cout<<"invalid"<<endl;
    }
    return 0;

}
