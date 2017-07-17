#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int noOfSteps(char arr[100][100], pair<int,int> startIndex, int m, int n, int entCount){
    if(entCount!=1)
        return -1;
    bool visited[100][100]={false};
    int steps=0;
    int queueSize;
    pair<int,int> queueFront;
    queue<pair<int,int> > bfsQueue;
    bfsQueue.push(startIndex);

    while(!bfsQueue.empty()) {
        queueSize=bfsQueue.size();
        for(int i=0;i<queueSize;i++) {
            queueFront=bfsQueue.front();
            if(arr[queueFront.first][queueFront.second]=='#')
                return steps;
            if(arr[queueFront.first][queueFront.second]!='*' && !visited[queueFront.first][queueFront.second]) {
                if(queueFront.first+1<m) {
                        bfsQueue.push(make_pair(queueFront.first+1,queueFront.second));
                }
                if(queueFront.first-1>=0) {
                        bfsQueue.push(make_pair(queueFront.first-1,queueFront.second));
                }
                if(queueFront.second+1<n) {
                        bfsQueue.push(make_pair(queueFront.first,queueFront.second+1));
                }
                if(queueFront.second-1>=0) {
                        bfsQueue.push(make_pair(queueFront.first,queueFront.second-1));
                }
            }
            visited[queueFront.first][queueFront.second]=true;
            bfsQueue.pop();

        }
        steps++;

    }
    return -1;



}


int main() {
    int t,m,n, entCount;
    char tempChar;
    char arr[100][100];
    pair<int,int> startIndex;
    cin>>t;
    for(int k=0;k<t;k++) {
        cin>>m>>n;
        entCount=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>tempChar;
                arr[i][j]=tempChar;
                if(tempChar=='$') {
                    startIndex=make_pair(i,j);
                    entCount++;
                }

            }

        }
        cout<<noOfSteps(arr,startIndex,m,n,entCount)<<endl;
    }
    return 0;

}
