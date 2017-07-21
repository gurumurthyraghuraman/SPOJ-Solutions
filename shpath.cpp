#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class edge {
   public:
        int index;
        int cost;
        edge(int a, int b) {
            index=a;
            cost=b;
        }
};


class lessThan {
    public:
        bool operator()(const edge &l, const edge &r) {
            return l.cost>r.cost;
        }

};

int minimumCost(int startIndex, int endIndex, unordered_map<int, vector<edge> > mapNodesToEdges) {
    bool visited[10001]={false};
    priority_queue<edge,vector<edge>,lessThan> verticesPQ;
    edge startEdge(startIndex,0);
    verticesPQ.push(startEdge);
    while(!verticesPQ.empty()) {
        edge minCostVertex=verticesPQ.top();
        if(minCostVertex.index==endIndex)
            return minCostVertex.cost;
        if(!visited[minCostVertex.index]) {
            for(int i=0;i<mapNodesToEdges[minCostVertex.index].size();i++) {
                    edge tempEdge(mapNodesToEdges[minCostVertex.index][i].index,mapNodesToEdges[minCostVertex.index][i].cost+minCostVertex.cost);
                    verticesPQ.push(tempEdge);
            }
        }
        visited[minCostVertex.index]=true;
        verticesPQ.pop();
    }


    return -1;

}


int main() {
    int t,n,noOfNeighbours,edgeIndex, edgeCost, noOfQueries;
    unordered_map<string,int> mapNamesToIndex;
    unordered_map<int, vector<edge> > mapNodesToEdges;
    string cityName,qString1,qString2;
    cin>>t;
    for(int i=0;i<t;i++) {
        mapNamesToIndex.clear();
        mapNodesToEdges.clear();
        cin>>n;
        for(int j=0;j<n;j++) {
            cin>>cityName;
            mapNamesToIndex.insert(make_pair(cityName,j+1));
            cin>>noOfNeighbours;
            for(int k=0;k<noOfNeighbours;k++) {
                cin>>edgeIndex>>edgeCost;
                edge tempEdge(edgeIndex,edgeCost);
                mapNodesToEdges[j+1].push_back(tempEdge);
            }
        }
        cin>>noOfQueries;
        for(int p=0;p<noOfQueries;p++) {
            cin>>qString1>>qString2;
            cout<<minimumCost(mapNamesToIndex[qString1],mapNamesToIndex[qString2], mapNodesToEdges)<<endl;
        }

    }

    return 0;
}
