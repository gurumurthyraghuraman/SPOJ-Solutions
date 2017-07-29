#include <iostream>
#include <stdio.h>
#include <utility>
#include <queue>

using namespace std;


class node{
    public:
        pair<int,int> index;
        int dist;
        void setNode(int x, int y, int d){
            index=make_pair(x,y);
            dist=d;
        }

};


class lessThan{
    public:
        bool operator()(const node& l, const node& r){
            return l.dist>r.dist;
        }

};

int shortestPath(char arr[25][25], int m, int n, pair<int,int> start, pair<int,int> dest) {
        bool visited[25][25]={false};
        int x,y;
        node origin;
        origin.setNode(start.first, start.second, 0);
        priority_queue<node,vector<node>, lessThan> pq;
        pq.push(origin);
        while(!pq.empty()){
            node heapTop=pq.top();
            x=heapTop.index.first;
            y=heapTop.index.second;
            if(!visited[x][y]){
                if(x+1<n) {
                    if(arr[x+1][y]=='D')
                        return heapTop.dist;

                    if(arr[x+1][y]!='X' && arr[x+1][y]!='S'){
                        node temp1;
                        temp1.setNode(x+1,y,heapTop.dist+arr[x+1][y]-'0');
                        pq.push(temp1);
                    }

                }
                if(x-1>=0) {
                    if(arr[x-1][y]=='D')
                        return heapTop.dist;

                    if(arr[x-1][y]!='X' && arr[x-1][y]!='S'){
                        node temp2;
                        temp2.setNode(x-1,y,heapTop.dist+arr[x-1][y]-'0');
                        pq.push(temp2);
                    }

                }
                if(y+1<m) {
                    if(arr[x][y+1]=='D')
                        return heapTop.dist;

                    if(arr[x][y+1]!='X' && arr[x][y+1]!='S'){
                        node temp3;
                        temp3.setNode(x,y+1,heapTop.dist+arr[x][y+1]-'0');
                        pq.push(temp3);
                    }

                }
                if(y-1>=0) {
                    if(arr[x][y-1]=='D')
                        return heapTop.dist;

                    if(arr[x][y-1]!='X' && arr[x][y-1]!='S'){
                        node temp4;
                        temp4.setNode(x,y-1,heapTop.dist+arr[x][y-1]-'0');
                        pq.push(temp4);
                    }

                }

            }
            visited[x][y]=true;
            pq.pop();


        }

        return 0;
}


int main(){
    int m,n;
    char c;
    char arr[25][25];
    cin>>m>>n;
    pair<int,int> start;
    pair<int,int> dest;
    while(m!=0 && n!=0){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                arr[i][j]=c;
                if(c=='S')
                    start=make_pair(i,j);
                if(c=='D')
                    dest=make_pair(i,j);
            }
        }
        printf("%d\n",shortestPath(arr,m,n,start,dest));
        cin>>m>>n;
    }
    return 0;
}
