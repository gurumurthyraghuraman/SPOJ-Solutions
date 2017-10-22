#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;


bool visited[2001];
bool color[2001];

void initializeArray(){
    for(int i=0;i<2001;i++){
        visited[i]=false;
        color[i]=false;

    }
}
bool isBipartiteHelper(map<int,vector<int> > graphAdjList,int startVertex){
    queue<int> bfsQueue;
    color[startVertex]=true;
    visited[startVertex]=true;
    bfsQueue.push(startVertex);
    int nextVertex;
    while(!bfsQueue.empty()){
        nextVertex=bfsQueue.front();
        for(int j=0;j<graphAdjList[nextVertex].size();j++){
            if(!visited[graphAdjList[nextVertex][j]]){
                visited[graphAdjList[nextVertex][j]]=true;
                color[graphAdjList[nextVertex][j]]=!color[nextVertex];
                bfsQueue.push(graphAdjList[nextVertex][j]);
            }
            else{
                if(color[graphAdjList[nextVertex][j]]==color[nextVertex])
                    return false;
            }

        }
        bfsQueue.pop();
    }
    return true;


}


bool isBipartite(map<int,vector<int> > graphAdjList,int bugs, int startVertex){
    if(isBipartiteHelper(graphAdjList,startVertex)){
        for(int i=1;i<=bugs;i++){
            if(graphAdjList.find(i)!=graphAdjList.end()){
                if(!visited[i]){
                    if(!isBipartiteHelper(graphAdjList,i))
                        return false;
                }
            }

        }
    }
    else{
        return false;

    }
    return true;


}

int main(){
    int noOfScenarios,bugs,interactions,v1,v2,startVertex;
    scanf("%d",&noOfScenarios);
    map<int,vector<int> > graphAdjList;
    for(int i=0;i<noOfScenarios;i++){
        graphAdjList.clear();
        initializeArray();
        scanf("%d",&bugs);
        scanf("%d",&interactions);
        for(int j=0;j<interactions;j++){
            scanf("%d",&v1);
            scanf("%d",&v2);
            if(j==0)
                startVertex=v1;
            graphAdjList[v1].push_back(v2);
            graphAdjList[v2].push_back(v1);
        }
        printf("Scenario #%d:\n",i+1);
        if(isBipartite(graphAdjList,bugs,startVertex))
            printf("No suspicious bugs found!\n");
        else printf("Suspicious bugs found!\n");

    }



}
